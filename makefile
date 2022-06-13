SRC=a.c b.c
CC=gcc-10
O=-O0 -g
CF=-Wno-unused-value -minline-all-stringops -fno-asynchronous-unwind-tables -fno-stack-protector -Wall -Wno-pointer-sign -Wno-strict-aliasing -Wno-parentheses -Wno-unused-function -Wno-misleading-indentation
LF=
#-s -nostdlib A.S

ifeq ($(shell uname),Darwin)
 LF+= -pagezero_size 1000
 CF+= -I$(shell xcrun --show-sdk-path)/usr/include -L$(shell xcrun --show-sdk-path)/usr/lib
endif

b: cln a.c b.c *.h makefile
	$(CC) -o $@ $(LF) $(SRC) $(CF)
	./$@ t/t.b

l: cln a.c b.c *.h makefile
	clang -o $@ $(LF) $(SRC) $(CF)
	./$@ t/t.b

tcc:
	tcc -std=c99 -O0 -g $(SRC) $(CF) -o bt
	./bt t.b

dis:
	@objdump -b binary -m i386 -M intel,x86-64 -D t/lnk.bin | tail -n+8
	#sudo lldb ./b

cln:
	rm -f b l

all: d
