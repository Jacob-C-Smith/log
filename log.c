/** !
 * log library
 *
 * @file log.c
 *
 * @author Jacob Smith
 */

// Headers
#include <log/log.h>

static FILE *log_file = 0;
static bool log_with_ansi_color = false;

<<<<<<< HEAD
/** !
 * This gets called when linking the shared object
 * 
 * @param void
 * 
 * @return void
 */
void init ( void ) __attribute__((constructor));

void init ( void ) __attribute__((constructor))
{

    // Initialize log on standard out with ANSI colors
    log_init(0, true);

    // Done
    return;
}

void close_log_file ( void )
=======
void log_init ( void )
>>>>>>> cc56252efe769c6d3a44e49a12cd96c5cfe82441
{

    // Log to standard out
    log_file = stdout;
    
    // ANSI color flag
    log_with_ansi_color = true;
    
    // Flush standard out
    fflush(stdout);

    // Done
    return;
}

void log_exit ( void )
{

    // Close the log file
    fclose(log_file);
    
    // Done
    return;
}

int log_update ( const char *const path, bool ansi_color )
{

    // Argument check
    if ( path == (void *) 0 ) goto log_on_standard_out;

    // Open the file 
    log_file = fopen(path, "w+");

    // Error check
    if ( log_file == (void *) 0 ) goto no_log_file;

    // Success
    return 1;

    log_on_standard_out:
        
        // Log to standard out
        log_file = stdout;
        
        // ANSI color flag
        log_with_ansi_color = ansi_color;
        
        // Flush standard out
        fflush(stdout);

        // Success
        return 1;

    no_log_file:
        #ifndef NDEBUG
            printf("[log] Failed to open file \"%s\" in call to function \"%s\"\n", path, __FUNCTION__);
        #endif

        // Error
        return 0;
}


int log_error ( const char *const format, ... )
{

    // Argument check
    if ( format == (void *) 0 ) goto no_format;

    // Initialized data
    va_list list;

    // Use the varadic argument list in vprintf call
    va_start(list, format);

    // Uses ANSI terminal escapes to set the color to red,
    if ( log_with_ansi_color ) printf("\033[91m");
    
    // Print the error
    vfprintf(log_file, format, list);

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Done with variadic list
    va_end(list);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_format:
                #ifndef NDEBUG
                    printf("[log] Null pointer provided for parameter \"format\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int log_warning ( const char *const format, ... )
{

    // Argument check
    if ( format == (void *) 0 ) goto no_format;

    // Initialized data
    va_list list;

    // Use the varadic argument list in vprintf call
    va_start(list, format);

    // Uses ANSI terminal escapes to set the color to red,
    if ( log_with_ansi_color ) printf("\033[93m");
    
    // Print the warning
    vfprintf(log_file, format, list);

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Done with variadic list
    va_end(list);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_format:
                #ifndef NDEBUG
                    printf("[log] Null pointer provided for parameter \"format\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int log_info ( const char *const format, ... )
{

    // Argument check
    if ( format == (void *) 0 ) goto no_format;

    // Initialized data
    va_list list;

    // Use the varadic argument list in vprintf call
    va_start(list, format);

    // Uses ANSI terminal escapes to set the color to red,
    if ( log_with_ansi_color ) printf("\033[94m");
    
    // Print the info
    vfprintf(log_file, format, list);

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Done with variadic list
    va_end(list);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_format:
                #ifndef NDEBUG
                    printf("[log] Null pointer provided for parameter \"format\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int log_pass ( const char *const format, ... )
{

    // Argument check
    if ( format == (void *) 0 ) goto no_format;

    // Initialized data
    va_list list;

    // Use the varadic argument list in vprintf call
    va_start(list, format);

    // Uses ANSI terminal escapes to set the color to green
    if ( log_with_ansi_color ) printf("\033[42m\033[1m");

    fprintf(log_file, "[PASS]");

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Uses ANSI terminal escapes to set the color to green,
    if ( log_with_ansi_color ) printf(" \033[92m");
    
    // Print the info
    vfprintf(log_file, format, list);

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Done with variadic list
    va_end(list);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_format:
                #ifndef NDEBUG
                    printf("[log] Null pointer provided for parameter \"format\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int log_fail ( const char *const format, ... )
{

    // Argument check
    if ( format == (void *) 0 ) goto no_format;

    // Initialized data
    va_list list;

    // Use the varadic argument list in vprintf call
    va_start(list, format);

    // Uses ANSI terminal escapes to set the color to red,
    if ( log_with_ansi_color ) printf("\033[41m\033[1m");

    fprintf(log_file, "[FAIL]");

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Uses ANSI terminal escapes to set the color to red,
    if ( log_with_ansi_color ) printf(" \033[91m");

    // Print the info
    vfprintf(log_file, format, list);

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Done with variadic list
    va_end(list);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_format:
                #ifndef NDEBUG
                    printf("[log] Null pointer provided for parameter \"format\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int log_scenario ( const char *const format, ... )
{

    // Argument check
    if ( format == (void *) 0 ) goto no_format;

    // Initialized data
    va_list list;

    // Use the varadic argument list in vprintf call
    va_start(list, format);

    // Uses ANSI terminal escapes to set the color to red,
    if ( log_with_ansi_color ) printf("\033[96m\033[1m\033[4m");

    fprintf(log_file, "Scenario: ");

    // Print the info
    vfprintf(log_file, format, list);

    // Restore the color.
    if ( log_with_ansi_color ) printf("\033[0m");

    // Done with variadic list
    va_end(list);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_format:
                #ifndef NDEBUG
                    printf("[log] Null pointer provided for parameter \"format\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}
