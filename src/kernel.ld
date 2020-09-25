ENTRY(start) 
SECTIONS 
{
	/* Segement Beginning */
	. = 0x100000;
	 PROVIDE( kern_start = .);
	.text :
	{
		*(.text)
		. = ALIGN(4096);
	}
	
	/* Code Segment */
	.text :
	{
		*(.text)
		. = ALIGN(4096);
	}

	/* Initialized Data */
	.data :
	{
		*(.data)
		*(.rodata)
		. = ALIGN(4096);
	}

	/* Uninitialized Data */
	.bss :
	{
		*(.bss)
		. = ALIGN(4096);
	}

	.stab :
	{
		*(.stab)
		. = ALIGN(4096);
	}

	.stabstr :
	{
		*(.stabstr)
		. = ALIGN(4096);
	}
		PROVIDE( kern_end = . );

	/DISCARD/ : { *(.comment) *(.eh_frame) }
}
