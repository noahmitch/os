cc=i686-elf-gcc
tool=i686-elf
ccargs=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
ccargs2=-ffreestanding -O2 -Wall -Wextra -fno-exceptions
linkerargs=-T linker.ld -ffreestanding -O2 -nostdlib -lgcc
assemblyargs=-O2 -Wall -Wextra

out=kernel.bin

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
SRCS2 = $(wildcard *.c)
OBJS2 = $(SRCS2:.c=.o)

ASSEMBLYOBJECTS = $(wildcard *.s)
ASSEMOBJS = $(ASSEMBLYOBJECTS:.s=.o)

.s.o:
	@$(tool)-as -c $< -o $@ 
	@echo "AS >> " $<

.cpp.o:
	@$(cc) $(ccargs) -c $< -o $@ 
	@echo "CC >> " $<

.c.o:
	@$(cc) $(ccargs2) -c $< -o $@
	@echo "CC >> " $<

build: $(ASSEMOBJS) $(OBJS) $(OBJS2)
	@echo "CC" $(shell ls *.o) " >> " $(out)
	@$(cc) $(linkerargs) *.o -o $(out)

all: $(x86)

clean:
	@rm -fv $(out) $(wildcard *.o)

iso:
	cp $(out) iso/boot/kernel
	grub-mkrescue -o boot.iso iso/
