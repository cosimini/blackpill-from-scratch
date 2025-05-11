#!/usr/bin/fish
# Create build folder
if not test -d "build"
  mkdir build
end
rm build/*

arm-none-eabi-gcc\
  *.c\
  -T link.ld \
  -static \
  -ggdb\
  -mcpu=cortex-m4\
  -mfloat-abi=hard -mthumb -nostdlib\
  -o build/output.o \

if test "$status" -eq 0
  openocd --file interface/stlink-v2-1.cfg --file target/stm32f4x.cfg -c "program build/output.o verify reset exit"
end

