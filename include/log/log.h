/** !
 * Include header for log library
 * 
 * @file log/log.h 
 * 
 * @author Jacob Smith
 */

// Include guard
#pragma once

// Standard library
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

// Platform dependent macros
#ifdef _WIN64
#define DLLEXPORT extern __declspec(dllexport)
#else
#define DLLEXPORT
#endif

enum log_color_e
{
    black   = 30,
    red     = 31,
    green   = 32,
    yellow  = 33,
    blue    = 34,
    magenta = 35,
    cyan    = 36,
    gray    = 37,
};

// Initializer
/** !
 * This gets called at runtime before main. By default, log to standard out 
 * with ANSI color coding 
 * 
 * @param void
 * 
 * @return void
 */
DLLEXPORT void log_init ( void ) __attribute__((constructor));

// State
/** !
 *  Update the log file and color coding flag
 *
 * @param path       path to the log file if not null pointer else log to standard out
 * @param ansi_color color coded logs if true else plain
 *
 * @sa log_error
 * @sa log_warning
 * @sa log_info
 * @sa log_pass
 * @sa log_fail
 * @sa log_scenario
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_update ( const char *const path, bool ansi_color );

// Debug logging
/** !
 *  Log an error
 *
 * @param format : printf format parameter
 * @param ...    : Additional arguments
 *
 * @sa log_warning
 * @sa log_info
 * @sa log_pass
 * @sa log_fail
 * @sa log_scenario
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_error ( const char *const format, ... );

/** !
 *  Log a warning
 *
 * @param format : printf format parameter
 * @param ...    : Additional arguments
 *
 * @sa log_error
 * @sa log_info
 * @sa log_pass
 * @sa log_fail
 * @sa log_scenario
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_warning ( const char *const format, ... );

/** !
 *  Log some information
 *
 * @param format : printf format parameter
 * @param ...    : Additional arguments
 *
 * @sa log_error
 * @sa log_warning
 * @sa log_pass
 * @sa log_fail
 * @sa log_scenario
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_info ( const char *const format, ... );

/** !
 *  Log a passing test
 *
 * @param format : printf format parameter
 * @param ...    : Additional arguments
 *
 * @sa log_error
 * @sa log_warning
 * @sa log_info
 * @sa log_fail
 * @sa log_scenario
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_pass ( const char *const format, ... );

/** !
 *  Log a failing test
 *
 * @param format : printf format parameter
 * @param ...    : Additional arguments
 *
 * @sa log_error
 * @sa log_warning
 * @sa log_info
 * @sa log_pass
 * @sa log_scenario
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_fail ( const char *const format, ... );

/** !
 *  Log a test scenario
 *
 * @param format : printf format parameter
 * @param ...    : Additional arguments
 *
 * @sa log_error
 * @sa log_warning
 * @sa log_info
 * @sa log_pass
 * @sa log_fail
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_scenario ( const char *const format, ... );

/** !
 *  Log with user defined colors
 *
 * @param 
 * @param format : printf format parameter
 * @param ...    : Additional arguments
 *
 * @sa log_error
 * @sa log_warning
 * @sa log_info
 * @sa log_pass
 * @sa log_fail
 *
 * @return 1 on success, 0 on error
 */
DLLEXPORT int log_colorful ( enum log_color_e color, const char *const format, ... );

// Cleanup
/** !
 * This gets called after main
 * 
 * @param void
 * 
 * @return void
 */
DLLEXPORT void log_exit ( void ) __attribute__((destructor));
