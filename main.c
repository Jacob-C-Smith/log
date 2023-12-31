// Standard library
#include <stdio.h>
#include <stdlib.h>

// Include
#include <log/log.h>

// Entry point
int main ( int argc, const char* argv[] )
{

    // Initialize log
    if ( log_init(0, true) == 0 ) goto failed_to_initialize_log;

    // Log an error
    log_error("[ERROR] This is an error\n");

    // Log a warning
    log_warning("[WARNING] This is a warning\n");

    // Log some info
    log_info("[INFO] This is some info\n");

    // Log a passing test
    log_pass("This is a passing test\n");

    // Log a failing test
    log_fail("This is a failing test\n");

    // Log a scenario
    log_scenario("This is a test scenario\n");

    // Success
    return EXIT_SUCCESS;

    // Error handling
    {
        failed_to_initialize_log:

            // Write an error message to standard out
            printf("Error: Failed to initialize log!\n");

            // Error
            return EXIT_FAILURE;
    }
}
