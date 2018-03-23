all: variable_overflow buffer_overflow system

system: system.c
	gcc system.c -o system.bin

variable_overflow: variable_overflow.c
	gcc variable_overflow.c -o variable_overflow.bin

buffer_overflow: buffer_overflow.c
	sudo sysctl -w kernel.randomize_va_space=0
	gcc -m32 -z execstack -fno-stack-protector buffer_overflow.c -o buffer_overflow.bin

buffer_overflow_good:
	echo "AAAA" > badfile
	hexdump -C badfile
	./buffer_overflow.bin || true

buffer_overflow_bad:
	python buffer_overflow_exploit.py badfile 1
	hexdump -C badfile
	./buffer_overflow.bin || true

retlibc:
	python ret2libc.py
	(cat in.txt; cat) | ./ret2libc

clean:
	rm *.bin in.txt badfile
