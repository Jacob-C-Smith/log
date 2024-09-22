// Standard library
#include <stdio.h>
#include <stdlib.h>

// Include
#include <log/log.h>

// Entry point
int main ( int argc, const char* argv[] )
{
    
    // Suppress compiler warnings
    (void) argc;
    (void) argv;

    // Log an error
    log_error("[ERROR] This is an error\n");

    // Log a warning
    log_warning("[WARNING] This is a warning\n");

    // Log some info
    log_info("[INFO] This is some info\n");

    // Log a scenario
    log_scenario("This is a test scenario\n");

    // Log a passing test
    log_pass("This is a passing test\n");

    // Log a failing test
    log_fail("This is a failing test\n");

    // Log with colors
    log_colorful(black  , "Hello, World!\n");
    log_colorful(red    , "Hello, World!\n");
    log_colorful(green  , "Hello, World!\n");
    log_colorful(yellow , "Hello, World!\n");
    log_colorful(blue   , "Hello, World!\n");
    log_colorful(magenta, "Hello, World!\n");
    log_colorful(cyan   , "Hello, World!\n");
    log_colorful(gray   , "Hello, World!\n");

    // Success
    return EXIT_SUCCESS;
}
