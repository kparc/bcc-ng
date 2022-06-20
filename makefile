MAKEFLAGS+=--silent

SRC=[ampbiv].c
CC=$(shell env env which gcc-11||which gcc-10||env which gcc-9||env which gcc-8||echo gcc)
RV?=0
O=-Os -g -UTEST

ifeq ($(RV),1)
	O+= -DRV
	DIS=-m riscv:rv32
else
	DIS=-m i386 -M intel,x86-64
endif

CF=$O -fno-asynchronous-unwind-tables -fno-stack-protector -Wall -Wno-pointer-sign -Wno-strict-aliasing -Wno-parentheses -Wno-unused-function -Wno-misleading-indentation -Wno-unused-value
LF=
OD=objdump

ifeq ($(shell uname),Darwin)
 CC=clang
 LF+= -pagezero_size 1000
 CF+= -I$(shell xcrun --show-sdk-path)/usr/include -L$(shell xcrun --show-sdk-path)/usr/lib
 OD=/usr/local/opt/binutils/bin/objdump
 OBJDUMP="/usr/local/opt/binutils/bin/objdump -b binary $(DIS) -D t/lnk.bin | tail -n+8"
 ifeq ($(shell uname -m),arm64)
	CF+= -arch x86_64 -msse
	OD=/opt/homebrew/opt/binutils/bin/objdump
	OBJDUMP="/opt/homebrew/opt/binutils/bin/objdump -b binary $(DIS) -D t/lnk.bin | tail -n+8"
 endif
endif

ifeq ($(shell uname -m),riscv64)
	RV=1
	DIS=-m riscv:rv32
	OBJDUMP="objdump -b binary $(DIS) -D t/lnk.bin | tail -n+8"
	CC=tcc
endif

CF+= -DOBJDUMP=\"$(OBJDUMP)\"

all: clear
	@make dis
	@RV=1 make dis

dis: l
	@./l t.b

clear:
	@#echo "\x1b[H\x1b[2J" # clear screen

l: cln *.c *.h makefile
	@$(CC) -o $@ $(LF) $(SRC) $(CF) -Wno-unknown-warning-option

g: cln *.c *.h makefile
	@$(CC) -o $@ $(LF) $(SRC) $(CF)
	@./$@ t/t.b

dbg: l
	@lldb -b -o run -- ./l t.b

tst: l clear
	@./l t/t.b

cln:
	@rm -f g l

b:
	tcc -std=c99 $(SRC) $(CF) -O2 -o $@
	./$@
