#MAKEFLAGS+=--silent
R=64
A=lp64d

SRC=[ampbiv].c
GCC=$(shell env env which gcc-12||gcc-11||which gcc-10||env which gcc-9||env which gcc-8||echo gcc)
RV?=0
O=-O0 -g -UTEST

ifeq ($(RV),1)
	O+= -DRV -march=rv$Rgc -mabi=$A
	DIS=-m riscv:rv$R
else
	DIS=-m i386 -M intel,x86-64
endif

CF=$O -Wall -Wno-deprecated-non-prototype -Wno-unused-variable -Wno-pointer-sign -Wno-strict-aliasing -Wno-parentheses -Wno-unused-function -Wno-misleading-indentation -Wno-unused-value
LF=
OD=objdump

ifeq ($(shell uname),Darwin)
 CC=clang
 LF+=-pagezero_size 0x4000
 CF+=-I$(shell xcrun --show-sdk-path)/usr/include -L$(shell xcrun --show-sdk-path)/usr/lib
 CF+= -arch x86_64 -msse
 ifeq ($(shell uname -m),arm64)
	OD=$(shell which objdump)
 endif
endif

ifeq ($(shell uname -m),riscv64)
	DIS=-m riscv:rv$R
	CC=tcc
endif

OBJDUMP="$(OD) --adjust-vma=0x%llx -b binary $(DIS) -D ref/lnk.bin | tail -n+8"
CF+=-DOBJDUMP=\"$(OBJDUMP)\"

# default: build bcc w/clang and compile t.b
b: cln
	clang -o $@ $(SRC) $(CF) $(LF) -Wno-unknown-warning-option
	./$@ t.b

# debug t.b
d: b
	lldb -b -o run -- ./b t.b

# clang build + reftest
l: cln *.c *.h makefile
	clang -o $@ $(SRC) $(CF) $(LF) -Wno-unknown-warning-option
	./$@ ref/t.b

# gcc build + reftest
g: cln *.c *.h makefile
	$(GCC) -o $@ $(SRC) $(CF) $(LF)
	./$@ ref/t.b

# tcc build + reftest
t: cln *.c *.h makefile
	tcc -std=c99 $(SRC) $(CF) -O2 -o $@
	./$@ ref/t.b

# cleanup
cln:
	@rm -f l g t

.PHONY:all cln d
