SRC=a.c m.c p.c b.c i.c v.c
CC=$(shell env env which gcc-11||which gcc-10||env which gcc-9||env which gcc-8||echo gcc)
RV=0
O=-O0 -g -UTEST

ifeq ($(RV),1)
	O+= -DRV
	DIS=-m riscv:rv32
else
	DIS=-m i386 -M intel,x86-64
endif

CF=$O -fno-asynchronous-unwind-tables -fno-stack-protector -Wall -Wno-pointer-sign -Wno-strict-aliasing -Wno-parentheses -Wno-unused-function -Wno-misleading-indentation -Wno-unused-value
LF=
OD=objdump
#-s -nostdlib A.S

ifeq ($(shell uname),Darwin)
 LF+= -pagezero_size 1000
 CF+= -I$(shell xcrun --show-sdk-path)/usr/include -L$(shell xcrun --show-sdk-path)/usr/lib
 OD=/usr/local/opt/binutils/bin/objdump
 OBJDUMP="/usr/local/opt/binutils/bin/objdump -b binary $(DIS) -D t/lnk.bin | tail -n+8"
 ifeq ($(shell uname -m),arm64)
	CF+= -arch x86_64 -msse
	OD=/opt/homebrew/opt/binutils/bin/objdump
	OBJDUMP="/opt/homebrew/opt/binutils/bin/objdump -b binary $(DIS) -D t/lnk.bin | tail -n+8"
	#riscv riscv:rv64 riscv:rv32
 endif
endif

CF+= -DOBJDUMP=\"$(OBJDUMP)\"

clear:
	@echo "\x1b[H\x1b[2J" # clear screen

g: cln *.c *.h makefile
	@$(CC) -o $@ $(LF) $(SRC) $(CF)
	@./$@ t/t.b

l: cln *.c *.h makefile
	@clang -o $@ $(LF) $(SRC) $(CF) -Wno-unknown-warning-option

tcc:
	tcc -std=c99 -O0 -g $(SRC) $(CF) -o bt
	./bt t.b

dis: l clear
	@./l t.b
	@#$(OD) -b binary -m i386 -M intel,x86-64 -D t/lnk.bin | tail -n+8

dbg: l
	@lldb -b -o run -- ./l t.b

tst: l clear
	@./l t/t.b

cln:
	@rm -f g l

all: d
