#!/usr/bin/fish

# Create build folder
if not test -d "build"
  mkdir build
end
rm build/*

# Flags explaination:
#  --specs=nano.specs  : This is a specific configuration file, provided by the toolkit, ships his own standard library if stdlib is in use
#  -Os                 : Optimize for space
#  -mthumb             : Use the Thumb2 instruction set
#  -nostdlib           : Do not link with the standard lib
#  -Wall               : Enable all warnings
#  -ggdb               : Enable debugger symbols

arm-none-eabi-gcc\
  src/*.c\
  -T src/link.ld \
  -static \
  -ggdb\
  -mcpu=cortex-m4\
  -mfloat-abi=hard -mthumb -nostdlib\
  -o build/output.o \
#  -l:libgcc.a \
#  -L:/usr/lib/gcc/arm-none-eabi/9.3.0/

#  Flags I'm not using
#-Wall -Wextra -Werror 
#  -Os\
#  --specs=nano.specs\
#  -static\

if test "$status" -eq 0
  # This requires st-utils to be running and connected to the host
  arm-none-eabi-gdb --command=gdb-init build/output.o
end
