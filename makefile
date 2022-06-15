SRC=a.c b.c p.c m.c
CC=$(shell env env which gcc-11||which gcc-10||env which gcc-9||env which gcc-8||echo gcc)
O=-O0 -g
CF=$O -fno-asynchronous-unwind-tables -fno-stack-protector -Wall -Wno-pointer-sign -Wno-strict-aliasing -Wno-parentheses -Wno-unused-function -Wno-misleading-indentation
LF=
OD=objdump
#-s -nostdlib A.S

ifeq ($(shell uname),Darwin)
 LF+= -pagezero_size 1000
 CF+= -I$(shell xcrun --show-sdk-path)/usr/include -L$(shell xcrun --show-sdk-path)/usr/lib
 OD=/usr/local/opt/binutils/bin/objdump
 ifeq ($(shell uname -m),arm64)
	CF+= -arch x86_64 -msse
	OD=/opt/homebrew/opt/binutils/bin/objdump
 endif
 
endif

g: cln *.c *.h makefile
	@$(CC) -o $@ $(LF) $(SRC) $(CF)
	@./$@ t/t.b

l: cln *.c *.h makefile
	@clang -o $@ $(LF) $(SRC) $(CF) -Wno-unknown-warning-option

tcc:
	tcc -std=c99 -O0 -g $(SRC) $(CF) -o bt
	./bt t.b

dis: l
	./l t.b
	@$(OD) -b binary -m i386 -M intel,x86-64 -D t/lnk.bin | tail -n+8

dbg: l
	@lldb -b -o run -- ./l t.b

cln:
	@rm -f g l

all: d
