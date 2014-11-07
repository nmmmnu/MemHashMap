
all: test

test: strmap.o test.o
	gcc -o test strmap.o test.o

test.o: test.c strmap.h
	gcc -c test.c

strmap.o: strmap.c strmap.h
	gcc -c strmap.c

clean:
	rm -f *.o test

