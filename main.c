/** !
 * Example log program
 * 
 * @file main.c
 * 
 * @author Jacob Smith
 */

// Standard library
#include <stdio.h>
#include <stdlib.h>

// log
#include <log/log.h>

// Enumeration definitions
enum parallel_examples_e
{
    LOG_MESSAGE_EXAMPLE   = 0,
    LOG_TESTER_EXAMPLE    = 1,
    LOG_COLORFUL_EXAMPLE  = 2,
    LOG_EXAMPLES_QUANTITY = 3
};

// Forward declarations
/** !
 * Print a usage message to standard out
 * 
 * @param argv0 the name of the program
 * 
 * @return void
 */
void print_usage ( const char *argv0 );

/** !
 * Parse command line arguments
 * 
 * @param argc            the argc parameter of the entry point
 * @param argv            the argv parameter of the entry point
 * @param examples_to_run return
 * 
 * @return void on success, program abort on failure
 */
void parse_command_line_arguments ( int argc, const char *argv[], bool *examples_to_run );

/** !
 * Message example program
 * 
 * @param argc the argc parameter of the entry point
 * @param argv the argv parameter of the entry point
 * 
 * @return 1 on success, 0 on error
 */
int log_message_example ( int argc, const char *argv[] );

/** !
 * Tester example program
 * 
 * @param argc the argc parameter of the entry point
 * @param argv the argv parameter of the entry point
 * 
 * @return 1 on success, 0 on error
 */
int log_tester_example ( int argc, const char *argv[] );

/** !
 * Colorful example program
 * 
 * @param argc the argc parameter of the entry point
 * @param argv the argv parameter of the entry point
 * 
 * @return 1 on success, 0 on error
 */
int log_colorful_example ( int argc, const char *argv[] );

// Entry point
int main ( int argc, const char *argv[] )
{

    // Initialized data
    bool examples_to_run[LOG_EXAMPLES_QUANTITY] = { 0 };

    // Parse command line arguments
    parse_command_line_arguments(argc, argv, examples_to_run);

    // Formatting
    log_info("╭─────────────╮\n");
    log_info("│ log example │\n");
    log_info("╰─────────────╯\n");
    log_info("The log library provides primitive logging functions.\n");
    log_info("Log provides %d categories of loggingfunctions. Message logs, test logs, and colorful logs.\n\n",LOG_EXAMPLES_QUANTITY);
    log_info("A message log is one of < info | warning | error >.\n");
    log_info("A tester log is one of < scenario | pass | fail >.\n");
    log_info("A colorful log is written with any ANSI color. \n\n");

    //////////////////////
    // Run the examples //
    //////////////////////

    // Run the message example program
    if ( examples_to_run[LOG_MESSAGE_EXAMPLE] )

        // Error check
        if ( log_message_example(argc, argv) == 0 ) goto failed_to_run_message_example;

    // Run the tester example program
    if ( examples_to_run[LOG_TESTER_EXAMPLE] )

        // Error check
        if ( log_tester_example(argc, argv) == 0 ) goto failed_to_run_tester_example;

    // Run the colorful example program
    if ( examples_to_run[LOG_COLORFUL_EXAMPLE] )

        // Error check
        if ( log_colorful_example(argc, argv) == 0 ) goto failed_to_run_colorful_example;

    // Success
    return EXIT_SUCCESS;

    // Error handling
    {
        failed_to_run_message_example:

            // Print an error message
            log_error("Error: Failed to run message example!\n");

            // Error
            return EXIT_FAILURE;

        failed_to_run_tester_example:

            // Print an error message
            log_error("Error: Failed to run tester example!\n");

            // Error
            return EXIT_FAILURE;
        
        failed_to_run_colorful_example:
            
            // Print an error message
            log_error("Error: Failed to run colorful example!\n");

            // Error
            return EXIT_FAILURE;   
    }
}

void print_usage ( const char *argv0 )
{

    // Argument check
    if ( argv0 == (void *) 0 ) exit(EXIT_FAILURE);

    // Print a usage message to standard out
    printf("Usage: %s [message] [tester] [colorful]\n", argv0);

    // Done
    return;
}

void parse_command_line_arguments ( int argc, const char *argv[], bool *examples_to_run )
{

    // If no command line arguments are supplied, run all the examples
    if ( argc == 1 ) goto all_examples;

    // Error check
    if ( argc > LOG_EXAMPLES_QUANTITY + 1 ) goto invalid_arguments;

    // Iterate through each command line argument
    for (size_t i = 1; i < (size_t) argc; i++)
    {
        
        // Message example?
        if ( strcmp(argv[i], "message") == 0 )

            // Set the message example flag
            examples_to_run[LOG_MESSAGE_EXAMPLE] = true;

        // Tester example?
        else if ( strcmp(argv[i], "tester") == 0 )
            
            // Set the tester example flag
            examples_to_run[LOG_TESTER_EXAMPLE] = true;

        // Colorful example?
        else if ( strcmp(argv[i], "colorful") == 0 )

            // Set the colorful example flag
            examples_to_run[LOG_COLORFUL_EXAMPLE] = true;

        // Default
        else goto invalid_arguments;
    }
    
    // Success
    return;

    // Set each example flag
    all_examples:
    {

        // For each example ...
        for (size_t i = 0; i < LOG_EXAMPLES_QUANTITY; i++)
        
            // ... set the example flag
            examples_to_run[i] = true;
        
        // Success
        return;
    }

    // Error handling
    {

        // Argument errors
        {
            invalid_arguments:
                
                // Print a usage message to standard out
                print_usage(argv[0]);

                // Abort
                exit(EXIT_FAILURE);
        }
    }
}

int log_message_example ( int argc, const char *argv[] )
{
    
    // Supress warnings
    (void) argc;
    (void) argv;

    // Formatting
    log_info("╭─────────────────╮\n");
    log_info("│ message example │\n");
    log_info("╰─────────────────╯\n");
    log_info("This example prints an error, a warning, and an info message\n\n");

    // Log an error
    log_error("[ERROR] This is an error\n");

    // Log a warning
    log_warning("[WARNING] This is a warning\n");

    // Log some info
    log_info("[INFO] This is some info\n");
    
    // Example formatting
    putchar('\n');

    // Success
    return 1;

    // Error handling
    { }
}

int log_tester_example ( int argc, const char *argv[] )
{

    // Supress warnings
    (void) argc;
    (void) argv;

    // Formatting
    log_info("╭────────────────╮\n");
    log_info("│ tester example │\n");
    log_info("╰────────────────╯\n");
    log_info("This example prints a scenario header, a pass, and a fail.\n\n");

    // Log a scenario
    log_scenario("This is a test scenario\n");

    // Log a passing test
    log_pass("This is a passing test\n");

    // Log a failing test
    log_fail("This is a failing test\n");

    // Formatting
    putchar('\n');
    
    // Success
    return 1;

    // Error handling
    { }
}

int log_colorful_example ( int argc, const char *argv[] )
{

    // Supress warnings
    (void) argc;
    (void) argv;

    // Formatting
    log_info("╭──────────────────╮\n");
    log_info("│ colorful example │\n");
    log_info("╰──────────────────╯\n");
    log_info("This example prints many logs in different ANSI colors.\n\n");

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
    return 1;

    // Error handling
    { }
}
