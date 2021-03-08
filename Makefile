NAME = kernel

toolchain = arm-none-eabi-

### FLAGS
cflags	=	-g \
			-O4 \
			-nostartfiles \
			-mfloat-abi=hard

### Color constants
NOCOLOR	=	'\033[0m'
RED		=	'\033[0;31m'
GREEN	=	'\033[0;32m'
BLUE	=	'\033[0;34m'
YELLOW	=	'\033[1;33m'

### Functions
define convert
	@echo $(YELLOW)"Converting the ELF output file to a binary image..."$(NOCOLOR)
    @${toolchain}objcopy kernel.$(1).elf -O binary kernel.img
	@echo $(GREEN)"Image file created."$(NOCOLOR)
endef

define disassemble
	@echo $(YELLOW)"Disassembling..."$(NOCOLOR)
	@${toolchain}objdump -l -S -D kernel.$(1).elf > kernel.$(1).asm
	@#${toolchain}nm kernel.$(1).elf > kernel.$(1).nm
	@#hexdump kernel.img > kernel.img.hexdump
	@echo $(GREEN)"Disassembled."$(NOCOLOR)
endef

### ###

rpi0:
	@echo $(YELLOW)"Compiling..."$(NOCOLOR)
	@${toolchain}gcc ${cflags} -DRPI0 \
	-mfpu=vfp \
	-march=armv6zk \
	-mtune=arm1176jzf-s \
	src/*.S src/*.c -o kernel.rpi0.elf
	@echo $(GREEN)"Source for RPi0 compiled."$(NOCOLOR)
	$(call convert,rpi0)
	$(call disassemble,rpi0)

rpi1:
	@echo $(YELLOW)"Compiling..."$(NOCOLOR)
	@${toolchain}gcc ${cflags} -DRPI1 \
	-mfpu=vfp \
	-march=armv6zk \
	-mtune=arm1176jzf-s \
	src/*.S src/*.c -o kernel.rpi1.elf
	@echo $(GREEN)"Source for RPi1 compiled."$(NOCOLOR)
	$(call convert,rpi1)
	$(call disassemble,rpi1)

rpi2:
	@echo $(YELLOW)"Compiling..."$(NOCOLOR)
	@${toolchain}gcc ${cflags} -DRPI2 \
	-mfpu=neon-vfpv4 \
	-march=armv7-a \
	-mtune=cortex-a7 \
	src/*.S src/*.c -o kernel.rpi2.elf
	@echo $(GREEN)"Source for RPi2 compiled."$(NOCOLOR)
	$(call convert,rpi2)
	$(call disassemble,rpi2)

# rpi3:
#	@echo $(YELLOW)"Compiling..."$(NOCOLOR)
# 	@${toolchain}gcc ${cflags} -DRPI3 \
# 	-mfpu=crypto-neon-fp-armv8 \
# 	-march=armv8-a+crc \
# 	-mcpu=cortex-a53 \
# 	src/*.S src/*.c -o kernel.rpi3.elf
# 	@echo $(GREEN)"Source for RPi3 compiled."$(NOCOLOR)
#	$(call convert,rpi3)
#	$(call disassemble,rpi3)

rpi4:
	@echo $(YELLOW)"Compiling..."$(NOCOLOR)
	@${toolchain}gcc ${cflags} -DRPI4 \
	-mfpu=crypto-neon-fp-armv8 \
	-march=armv8-a+crc \
	-mcpu=cortex-a72 \
	src/*.S src/*.c -o kernel.rpi4.elf
	@echo $(GREEN)"Source for RPi4 compiled."$(NOCOLOR)
	$(call convert,rpi4)
	$(call disassemble,rpi4)

clean:
	@rm -rf *.elf
	@echo $(RED)"ELF output files deleted."$(NOCOLOR)

	@rm -rf *.asm
	@echo $(RED)"Disassembled files deleted."$(NOCOLOR)

	@rm -rf kernel.img
	@echo $(RED)"kernel.img deleted."$(NOCOLOR)