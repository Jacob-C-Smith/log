# Need CMake 3.20
cmake_minimum_required (VERSION 3.20)

# This is the name of the repository
project ("log")

# Set the correct paths
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/extern/)

# Comment out for Debug mode
set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")

# Set debug mode
if (${IS_DEBUG_BUILD})
    add_compile_definitions(NDEBUG)
endif()

# Add the log project
if ( NOT "${HAS_LOG}")

    # Log
    message("[log] Adding log project")

    # Let any parent project know that it has the log project
    set(HAS_LOG true PARENT_SCOPE)
endif()

# Add source to this project's executable.
add_executable(log_example "main.c")
add_dependencies(log_example log)
target_include_directories(log_example PUBLIC include include/log)
target_link_libraries(log_example log)

# Add source to the library
add_library(log SHARED "log.c")
target_include_directories(log PUBLIC include include/log)
