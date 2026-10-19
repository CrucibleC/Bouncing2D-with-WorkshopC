#ifndef APP_APP_H
#define APP_APP_H

#include "numbers.h"

// Runs the program: starts logging (bouncing2d.log next to the executable, and the terminal), the
// random generator and the window library, then runs the bouncing spheres until the window
// closes. Without SDL the window is the headless mock: the run is a benchmark that ends on its own
// and logs ms per frame and per physics step. Returns the process exit code: 0, or 1 on failure
i32 app_run(void);

#endif // APP_APP_H
