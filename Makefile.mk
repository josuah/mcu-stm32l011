OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
CC = arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -msoft-float --specs=nosys.specs
AR = arm-none-eabi-ar
GDB = arm-none-eabi-gdb
OPENOCD = openocd -f interface/stlink.cfg -f target/stm32l0.cfg

SDK_OBJ = ${SDK}/init.o ${SDK}/gpio.o ${SDK}/usart.o ${SDK}/lpuart.o
SDK_CFLAGS = -ffunction-sections -fdata-sections
SDK_LDFLAGS = -Wl,-Map=firmware.map -Wl,--gc-sections -T${SDK}/script.ld \
	-nostartfiles -nostdlib -static
SDK_CPPFLAGS = -I${SDK}
SDK_ASFLAGS = -I${SDK}

all: firmware.elf firmware.asm

clean:
	rm -f *.[os] ${SDK}/*.[os] *.asm *.elf *.map *.hex *.bin *.uf2

ocd:
	${OPENOCD}

gdb:
	${GDB} -x ${SDK}/script.gdb

firmware.elf: ${SDK_OBJ} ${OBJ}
	${LD} ${SDK_LDFLAGS} ${LDFLAGS} -o $@ ${SDK_OBJ} ${OBJ}

flash.avrdude: firmware.hex
	${AVRDUDE} -qu -P ${PORT} -U flash:w:firmware.hex

flash.dfuutil: firmware.bin
	${DFUUTIL} -D firmware.bin

flash.mount: firmware.uf2
	mount /mnt && cp firmware.uf2 /mnt

flash.openocd: firmware.hex
	${OPENOCD} -c 'program firmware.hex verify reset exit'

.SUFFIXES: .c .s .S .o .elf .bin .asm .hex .uf2

.c.o:
.S.o:

.c.s:
	${CC} ${SDK_CPPFLAGS} ${CPPFLAGS} ${SDK_CFLAGS} ${CFLAGS} -c -o $@ $<

.S.s:
	${CPP} ${SDK_CPPFLAGS} ${CPPFLAGS} -o $@ $<

.s.o:
	${AS} ${SDK_CPPFLAGS} ${CPPFLAGS} ${SDK_ASFLAGS} ${ASFLAGS} -c -o $@ $<

.elf.asm:
	${OBJDUMP} -z -d $< >$@

.elf.hex:
	${OBJCOPY} -j .text -j .data -O ihex $< $@

.elf.bin:
	${OBJCOPY} -j .text -j .data -O binary $< $@

.elf.uf2:
	elf2uf2 $< $@
