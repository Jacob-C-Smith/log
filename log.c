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

int log_init ( const char *const path, bool ansi_color )
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
