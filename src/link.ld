MEMORY {
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 512K
  sram (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
  .isr_vector : {
    *(.reset_vector)
    . = ALIGN(4);
  } > flash

  .text : {
    *(.text*)
    *(.rodata)
    . = ALIGN(4);
  } > flash

  .data : {
    *(.data)
    . = ALIGN(4);
  } > sram AT> flash

  .bss : {
    *(.bss)
    . = ALIGN(4);
  } > sram

}
