#
# Log Makefile
#
# @file Makefile
#
# @author Jacob Smith
#
PROJECT_NAME = log

CC = gcc
AS = nasm

CC_FLAGS = -fPIC -I $(INCLUDE_DIRECTORY) $(DEFINES) -Wall -Wextra -Wpointer-arith -Wstrict-prototypes -Wformat-security -Wfloat-equal -Wshadow -Wconversion -pthread -lpthread -Wlogical-not-parentheses -Wnull-dereference
LD_FLAGS = -g

INCLUDE_DIRECTORY = ./include
LIBRARY_DIRECTORY = ./lib
BUILD_DIRECTORY   = ./build

LIBRARY_SOURCES = log.c 
EXAMPLE_SOURCES = main.c

DEFINES = -D_GNU_SOURCE

.PHONY : clean all

.SUFFIXES:
%.o: %.c; $(CC) -o $(BUILD_DIRECTORY)/$@ -c $< $(CC_FLAGS)
%.i: %.c; $(CC) -I $(CC_FLAGS) -o $(BUILD_DIRECTORY)/$@ -E $< 
%.s: %.c; $(CC) -I $(CC_FLAGS) -o $(BUILD_DIRECTORY)/$@ -S $<

all:
	# ╭─────╮
	# │ log │
	# ╰─────╯
	make log
	make log_example

log: log.o
	# ╭─────────────╮
	# │ log library │
	# ╰─────────────╯
	$(CC) $(CC_FLAGS) $(DEFINES) -I$(INCLUDE_DIRECTORY) -shared -o $(LIBRARY_DIRECTORY)/lib$@.so $(BUILD_DIRECTORY)/$^ 

log_example: main.o
	$(CC) -L$(LIBRARY_DIRECTORY) -Wl,-R$(LIBRARY_DIRECTORY) -llog $(CC_FLAGS) $(DEFINES) -o $(BUILD_DIRECTORY)/$@ $(BUILD_DIRECTORY)/$^ 
	# ╭─────────────╮
	# │ log example │
	# ╰─────────────╯
	$(BUILD_DIRECTORY)/$@

clean:
	rm -rf *.o $(LIBRARY_DIRECTORY)/* $(BUILD_DIRECTORY)/*