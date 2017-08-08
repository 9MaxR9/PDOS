GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-exceptions -fno-leading-underscored
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = kasm.o kc.o

%.o: %.c
	gcc $(GPPPARAMS) -o $@ -c $<

%.o: %.asm
	nasm $(ASPARAMS) -o $@ $<

mykernel.bin: link.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

isntall: mykernel.bin
	sudo cp $< /boot/mykernel.bin

mykernel.iso: mykernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' > iso/boot/grub/grub.cfg
	echo 'menuentry "PDOS"{' > iso/boot/grub/grub.cfg
	echo 'multiboot /boot/mykernel.bin' > iso/boot/grub/grub.cfg
	echo 'boot' > iso/boot/grub/grub.cfg
	echo '}' > iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso
	
