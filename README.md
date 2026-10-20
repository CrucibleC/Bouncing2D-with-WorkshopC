[Part of The Crucible C Project.](https://github.com/CrucibleC/CrucibleC)

# Bouncing2D with WorkshopC
A demo of using WorkshopC to make an app of bouncing objects.

**[WorkshopC](https://github.com/CrucibleC/WorkshopC)** · **[Uppercase tags version](https://github.com/CrucibleC/Bouncing2D-with-WorkshopC/tree/uppercase-tags)**

The point of this project is to show what a C codebase can look like when it is written with WorkshopC: explicit ownership, RAII lifetimes, null safety, and sized buffers, checked by the analyzer on every change.

It is made using WorkshopC, along with its VS Code extension and its AI integration named RobotC. These tools are not part of this project and are under a different license of their own. This project's license does not cover them.

## Running it

Download the newest build from **Releases**: the one release, "Latest build", is replaced by every green CI run on `main`. Builds of other branches are in the artifacts of their CI run (Actions tab). They are single executables with nothing to install, packed with the project's LICENSE and NOTICE and SDL3's license. On Windows, unzip and run `bouncing2d.exe`. On Linux, unpack the tarball and run `./bouncing2d`; it needs an X11 or Wayland desktop and a glibc from 2022 or later.

- The buttons at the top set n, and n² bodies bounce (1 to 1 000 000): the inner `◀ ▶` change n by 1, the outer ones divide or multiply it by 10.
- FPS shows at the top left, with a line under it saying where each frame's time goes (physics, draw, present, physics steps); the body count is at the top right.
- Esc or closing the window quits.

## License

This project is free to use and copy under the Apache License, Version 2.0. See [LICENSE](LICENSE) and [NOTICE](NOTICE).

The released executables include [SDL3](https://libsdl.org), under the zlib license.
