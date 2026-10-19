cmake_minimum_required(VERSION 3.20)
project(bouncing2d LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)        # needed by WorkshopC; only Makefile and Ninja generators write it

# The real SDL3 window. Off everywhere except CI release builds: local builds and every test use
# the headless mock window (src/core/window_mock.c) and never fetch, compile or link SDL
option(BOUNCING2D_SDL "Build the real SDL3 window instead of the headless mock" OFF)

# Runtime checks for test runs (build.py --test builds a sanitized Debug copy; CI tests use it):
# - GCC/Clang on Linux: AddressSanitizer (with LeakSanitizer) and UndefinedBehaviorSanitizer,
#   any finding fails the run
# - MinGW: GCC ships no sanitizer runtimes there, so undefined behavior traps instead (the
#   runner stops with an illegal instruction; no report)
option(BOUNCING2D_SANITIZE "Build with sanitizers (for tests; never for release builds)" OFF)
if(BOUNCING2D_SANITIZE)
    if(BOUNCING2D_SDL)
        message(FATAL_ERROR "BOUNCING2D_SANITIZE is for test builds, not the SDL release build")
    endif()
    if(MINGW)
        add_compile_options(-fsanitize=undefined -fsanitize-trap=undefined)
        add_link_options(-fsanitize=undefined -fsanitize-trap=undefined)
    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-fsanitize=address,undefined -fno-sanitize-recover=all -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address,undefined)
    else()
        message(WARNING "BOUNCING2D_SANITIZE: no sanitizers for ${CMAKE_C_COMPILER_ID}")
    endif()
endif()

# Optimized unless asked otherwise (build.py --debug, or -DCMAKE_BUILD_TYPE=Debug)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Debug or Release" FORCE)
endif()

if(MSVC)
    set(BOUNCING2D_WARNINGS /W4)
else()
    set(BOUNCING2D_WARNINGS -Wall -Wextra -Wpedantic)
    # sqrt can then be a single instruction (and vectorize): nothing reads errno from math.
    # Not -ffast-math: the cast functions in numbers.c rely on exact NaN behavior
    add_compile_options(-fno-math-errno)
endif()

# Link-time optimization in Release, so calls between files (e.g. the grid calling
# core_collision_resolve_pair) can be inlined
include(CheckIPOSupported)
check_ipo_supported(RESULT BOUNCING2D_IPO_SUPPORTED LANGUAGES C)
if(BOUNCING2D_IPO_SUPPORTED)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
endif()

# Everything in src except main.c, compiled once and shared by the app and the test runners
add_library(bouncing2d_lib STATIC
    src/app/app.c
    src/app/fps.c
    src/app/hud.c
    src/app/simulation.c
    src/core/collision.c
    src/core/grid.c
    src/core/physics.c
    src/core/spawn.c
    src/core/spheres.c
    src/core/sprite_batch.c
    src/memory_block.c
    src/numbers.c
    src/span.c
    src/status.c
    src/util/dynamic_array.c
    src/util/fs.c
    src/util/clock.c
    src/util/log.c
    src/util/random.c
    src/util/string.c
    src/util/singleton.c
)
target_include_directories(bouncing2d_lib PUBLIC src include include/workshopc)
target_compile_options(bouncing2d_lib PRIVATE ${BOUNCING2D_WARNINGS})

# sqrt and the other <math.h> functions live in libm on Linux; Windows has them in its C runtime
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(bouncing2d_lib PUBLIC ${MATH_LIBRARY})
endif()

# The headless window: every build without SDL and every test runner
add_library(bouncing2d_window_mock OBJECT src/core/window_mock.c)
target_link_libraries(bouncing2d_window_mock PUBLIC bouncing2d_lib)
target_compile_options(bouncing2d_window_mock PRIVATE ${BOUNCING2D_WARNINGS})

add_executable(bouncing2d src/main.c)
target_compile_options(bouncing2d PRIVATE ${BOUNCING2D_WARNINGS})

if(BOUNCING2D_SDL)
    # SDL3 from its release source, built as a static library with only what the app needs
    include(FetchContent)
    set(SDL_STATIC ON CACHE BOOL "" FORCE)
    set(SDL_SHARED OFF CACHE BOOL "" FORCE)
    set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
    set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
    foreach(unused AUDIO CAMERA JOYSTICK HAPTIC HIDAPI SENSOR POWER DIALOG TRAY GPU)
        set(SDL_${unused} OFF CACHE BOOL "" FORCE)
    endforeach()
    FetchContent_Declare(SDL3
        URL https://github.com/libsdl-org/SDL/releases/download/release-3.4.18/SDL3-3.4.18.tar.gz
        URL_HASH SHA256=9c75cf16330322c217dedd2e0609f1124f1b54b8633e763467b4684d0f4334a3)
    FetchContent_MakeAvailable(SDL3)

    add_library(bouncing2d_window_sdl OBJECT src/core/window_sdl.c)
    target_link_libraries(bouncing2d_window_sdl PUBLIC bouncing2d_lib SDL3::SDL3-static)
    target_compile_options(bouncing2d_window_sdl PRIVATE ${BOUNCING2D_WARNINGS})   # WorkshopC can't see this file
    target_link_libraries(bouncing2d PRIVATE bouncing2d_window_sdl bouncing2d_lib)

    # Everything static, so the executable runs without installing anything:
    # MinGW: libgcc and winpthread too (only Windows' own DLLs remain).
    # Linux: libgcc; glibc and the desktop's display/GPU libraries (which SDL loads at runtime)
    # come from the system, as they must
    if(MINGW)
        target_link_options(bouncing2d PRIVATE -static)
    elseif(UNIX)
        target_link_options(bouncing2d PRIVATE -static-libgcc)
    endif()
else()
    target_link_libraries(bouncing2d PRIVATE bouncing2d_window_mock bouncing2d_lib)
endif()

# Tests: one HammerC runner, tests_<folder>, per top-level folder of tests/ that has *.test.c files.
# hammerc.py generates tests/<folder>/generated/ from them; the runners link bouncing2d_lib.
set(HAMMERC_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/../HammerC/hammerc.py"
    CACHE FILEPATH "HammerC's hammerc.py, which generates the test runners")
# A relative path (e.g. CI's -DHAMMERC_SCRIPT=HammerC/hammerc.py) is relative to this folder
get_filename_component(HAMMERC_SCRIPT "${HAMMERC_SCRIPT}" ABSOLUTE BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
if(EXISTS "${HAMMERC_SCRIPT}")
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    enable_testing()

    set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS ${TESTS_DIR}/*.test.c)
    set(TEST_FOLDERS "")
    foreach(test_file IN LISTS TEST_FILES)
        file(RELATIVE_PATH test_path ${TESTS_DIR} ${test_file})
        string(REGEX MATCH "^[^/]+" test_folder "${test_path}")
        if(NOT test_path STREQUAL test_folder)   # a .test.c directly in tests/ belongs to no runner
            list(APPEND TEST_FOLDERS ${test_folder})
        endif()
    endforeach()
    list(REMOVE_DUPLICATES TEST_FOLDERS)

    foreach(test_folder IN LISTS TEST_FOLDERS)
        set(folder_dir ${TESTS_DIR}/${test_folder})
        file(GLOB_RECURSE folder_tests CONFIGURE_DEPENDS ${folder_dir}/*.test.c)

        # hammerc.py only rewrites files whose content changed, so a stamp file tells
        # the build when the script last ran
        set(stamp ${CMAKE_CURRENT_BINARY_DIR}/tests_${test_folder}_generated.stamp)
        add_custom_command(
            OUTPUT ${stamp}
            BYPRODUCTS ${folder_dir}/generated/hammer_tests.h ${folder_dir}/generated/hammer_main.c
            COMMAND ${Python3_EXECUTABLE} ${HAMMERC_SCRIPT} ${folder_dir}
            COMMAND ${CMAKE_COMMAND} -E touch ${stamp}
            DEPENDS ${folder_tests} ${HAMMERC_SCRIPT}
            COMMENT "Generating the HammerC runner for tests/${test_folder}"
            VERBATIM)
        add_custom_target(tests_${test_folder}_generate DEPENDS ${stamp})

        add_executable(tests_${test_folder} ${folder_tests} ${folder_dir}/generated/hammer_main.c)
        add_dependencies(tests_${test_folder} tests_${test_folder}_generate)
        target_include_directories(tests_${test_folder} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)   # hammerc.h
        target_link_libraries(tests_${test_folder} PRIVATE bouncing2d_window_mock bouncing2d_lib)
        target_compile_options(tests_${test_folder} PRIVATE ${BOUNCING2D_WARNINGS})
        # --quiet: print only the failed tests and the summary
        add_test(NAME tests_${test_folder} COMMAND tests_${test_folder} --quiet)
    endforeach()
else()
    message(STATUS "HammerC not found at ${HAMMERC_SCRIPT}: the tests are not built")
endif()
