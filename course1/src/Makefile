#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#-----------------------------------------------------------------------------
# Build Targets:
#      compile-everything: compile all object files
#      build : Builds and links all source files
#      clean : Removes all generated files
#
# Platform Overrides:
#      PLATFORM -  Host , MSP432
#
#-----------------------------------------------------------------------------

SOURCES = main.c  memory.c
INCLUDES = -I../include/CMSIS -I ../include/common -I ../include/msp432
PLATFORM = HOST
TARGET = C1M2

# Enable comprehensive set of warnings.
# All warnnings as errors.
# Additional debug information
# Optimization level 0 
# standart c99
FLAGS = -Wall -Werror -g -O0 -std=c99

ifeq ($(PLATFORM), HOST)
CC = gcc
CFLAGS = $(FLAGS)
CPPFLAGS = -DHOST $(INCLUDES)
LDFLAGS = -Wl,-Map=$(TARGET).map
SIZE = size

else
# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds
LINKER_FILE_PATH = -L ../ $(LINKER_FILE)
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
OTHER_ARCH_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16

SOURCES = main.c memory.c interrupts_msp432p401r_gcc.c startup_msp432p401r_gcc.c system_msp432p401r.c

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LDFLAGS = -Wl,-Map=$(TARGET).map $(LINKER_FILE_PATH)
CFLAGS = $(FLAGS) $(OTHER_ARCH_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
CPPFLAGS = -DMSP432 $(INCLUDES)
SIZE = arm-none-eabi-size
endif

#************************************************************************************
#using -c flag to stop linking
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -S flag to generate assembly file
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

#using -E flag to generate preprocessed, so i only need CPPFLAGS
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

#using -E -M flag to generate dependency files
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

#*************************************************************************************

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

#************************************************************************************
#compile-all will generate all object files for all source files without linking

.PHONY: compile-everything
compile-everything:$(OBJS)

.PHONY: build
build:$(DEPS)
build:$(TARGET).out

$(TARGET).out:$(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map
