INCLUDE memory_map.ld

/* Section Definitions */
SECTIONS
{
    .text :
    {
        KEEP(*(.vectors .vectors.*))
        *(.text*)
        *(.rodata*)
        _etext = .;
    } > approm
    ...
    SECTIONS {
      .text :
      {
          KEEP(*(.vectors .vectors.*))
          *(.text*)
          *(.rodata*)
      } > eram AT > approm
      ...
  }

}
