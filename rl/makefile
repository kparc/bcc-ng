#-fno-stack-protector
O=-fvisibility=hidden -flax-vector-conversions -fno-common -fno-asynchronous-unwind-tables -fno-stack-protector
WL=-Werror -Wno-empty-body -Wno-variadic-macros -Wno-gnu-statement-expression \
	-Wno-gnu-zero-variadic-macro-arguments -Wno-unused-value -Wno-language-extension-token \
	-Wno-pointer-sign -Wno-int-conversion -Wno-gnu-empty-initializer -Wno-zero-length-array
WG=-Werror -pedantic -Wno-variadic-macros -Wno-unused-value -Wno-builtin-declaration-mismatch -Wno-int-conversion
A=-m64

#-Wno-empty-body -Wno-unused-value

l: c
	@clang -pagezero_size 1000 -arch x86_64 -msse -DUSE_AW_MALLOC -DNOLIBC=1 ?.[c] main.c ../m.c -ol $O $(WL) $A -O0 -g -Wno-format -Wno-format-pedantic -Wno-incompatible-library-redeclaration
	@#strip l
	@#ls -la l
	@./l

c:
	@rm -f l

#/:~
