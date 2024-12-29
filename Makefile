#######################
# Log Makefile        #
#                     #
# @file Makefile      #
#                     #
# @author Jacob Smith #
#######################
PROJECT_NAME = log

CC = gcc
AS = nasm
DISABLE = #MESSAGES TESTER COLORFUL

CC_FLAGS = -fPIC -I$(INCLUDE_DIRECTORY) $(DEFINES) -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -Wformat-security -Wfloat-equal -Wshadow -Wconversion -pthread -lpthread -Wlogical-not-parentheses -Wnull-dereference
LD_FLAGS = -g

INCLUDE_DIRECTORY = $(shell pwd)/include
LIBRARY_DIRECTORY = $(shell pwd)/lib
BUILD_DIRECTORY   = $(shell pwd)/build

LIBRARY_SOURCES = log.c 
EXAMPLE_SOURCES = main.c

DEFINES = -D_GNU_SOURCE $(addprefix -DLOG_BUILD_NO_,$(DISABLE))

.PHONY : clean all log_example_run

.SUFFIXES:
%.o: %.c; $(CC) -o $(BUILD_DIRECTORY)/$@ -c $< $(CC_FLAGS)
%.i: %.c; $(CC) -I $(CC_FLAGS) -o $(BUILD_DIRECTORY)/$@ -E $< 
%.s: %.c; $(CC) -I $(CC_FLAGS) -o $(BUILD_DIRECTORY)/$@ -S $<

all: log example
	# >>>> LOG ALL <<<<

log: log.o
	# >>>> LOG LIB <<<<

	$(CC) $(CC_FLAGS) $(DEFINES) -I$(INCLUDE_DIRECTORY) -shared -o "$(LIBRARY_DIRECTORY)/lib$@.so" $(BUILD_DIRECTORY)/$^

example: ./main.o
	# >>>> LOG EXAMPLE <<<<

	$(CC) -L$(LIBRARY_DIRECTORY) -Wl,-rpath=$(LIBRARY_DIRECTORY) $(CC_FLAGS) $(DEFINES) -o "$(BUILD_DIRECTORY)/$(PROJECT_NAME)_$@" $(BUILD_DIRECTORY)/$^ -llog

clean:
	# >>>> CLEAN <<<<
	rm -rf *.o $(LIBRARY_DIRECTORY)/* $(BUILD_DIRECTORY)/*
