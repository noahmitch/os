#include <stddef.h>
#include <stdint.h>

/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

#include "ram.h"
#include "memory.h"
#include "string.h"
#include "tty.h"


TTY out;
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif


void kernel_main ()
{
	out = TTY (0xB8000);
	uint64_t base = (uint64_t)0x534D4150;
	initMem ();
	string a;
	out.printString (a);
}
