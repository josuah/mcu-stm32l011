LDFLAGS = -Wl,-Map=firmware.map
CFLAGS = -Os -g -Wall -Wextra -std=c99 -pedantic
OBJ = main.o

ZMCU = ../..
include ${ZMCU}/lib/libzmcu.stm32l011.mk

all: firmware.elf firmware.asm

ocd:
	${OPENOCD}

gdb:
	${GDB} -x script.gdb
