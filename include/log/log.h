/** !
 * @file log/log.h 
 * 
 * @author Jacob Smith
 * 
 * Include header for log library
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

// Initializer
/** !
 *  Initialize the log library
 *
 * @param path path to the log file if not null pointer else logs to standard out
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
DLLEXPORT int log_init ( const char *const path, bool ansi_color );

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
