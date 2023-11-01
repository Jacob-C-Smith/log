# LOG CMake configuration file:
# This file is meant to be placed in a cmake subfolder of LOG-devel-2.x.y-VC

cmake_minimum_required(VERSION 3.0)

include(FeatureSummary)
set_package_properties(LOG PROPERTIES
    URL "https://g10.app/status/#miscellaneous"
    DESCRIPTION "Log errors, warnings, and information with pretty printing"
)

# Copied from `configure_package_config_file`
macro(set_and_check _var _file)
    set(${_var} "${_file}")
    if(NOT EXISTS "${_file}")
        message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
    endif()
endmacro()

# Copied from `configure_package_config_file`
macro(check_required_components _NAME)
    foreach(comp ${${_NAME}_FIND_COMPONENTS})
        if(NOT ${_NAME}_${comp}_FOUND)
            if(${_NAME}_FIND_REQUIRED_${comp})
                set(${_NAME}_FOUND FALSE)
            endif()
        endif()
    endforeach()
endmacro()

set(LOG_FOUND TRUE)

# For compatibility with autotools LOG-config.cmake, provide LOG_* variables.

set_and_check(LOG_PREFIX       "${CMAKE_CURRENT_LIST_DIR}/..")
set_and_check(LOG_EXEC_PREFIX  "${CMAKE_CURRENT_LIST_DIR}/..")
set_and_check(LOG_INCLUDE_DIR  "${LOG_PREFIX}/include")
set(LOG_INCLUDE_DIRS           "${LOG_INCLUDE_DIR}")
set_and_check(LOG_BINDIR       "${CMAKE_CURRENT_LIST_DIR}/../build/Debug/")
set_and_check(LOG_LIBDIR       "${CMAKE_CURRENT_LIST_DIR}/../build/Debug/")

set(LOG_LIBRARIES log::log)

# All targets are created, even when some might not be requested though COMPONENTS.
# This is done for compatibility with CMake generated LOG-target.cmake files.

set(_LOG_library     "${LOG_LIBDIR}/log.lib")
set(_LOG_dll_library "${LOG_BINDIR}/log.dll")
if(EXISTS "${_LOG_library}" AND EXISTS "${_LOG_dll_library}")
    if(NOT TARGET log::log)
        add_library(log::log SHARED IMPORTED)
        set_target_properties(log::log
            PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${LOG_INCLUDE_DIRS}"
                IMPORTED_IMPLIB "${_LOG_library}"
                IMPORTED_LOCATION "${_LOG_dll_library}"
                COMPATIBLE_INTERFACE_BOOL "LOG_SHARED"
                INTERFACE_LOG_SHARED "ON"
        )
    endif()
    set(LOG_LOG_FOUND TRUE)
else()
    set(LOG_LOG_FOUND FALSE)
endif()
unset(_LOG_library)
unset(_LOG_dll_library)

check_required_components(LOG)
