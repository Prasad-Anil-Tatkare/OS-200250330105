CC=gcc

arith_demo: arith_demo.o add.o sub.o
	$(CC) -o arith_demo arith_demo.o add.o sub.o

arith_demo.o: arith_demo.c
	$(CC) -c -o arith_demo.o arith_demo.c

add.o: add.c
	$(CC) -c -o add.o add.c

sub.o: sub.c
	$(CC) -c -o sub.o sub.c

clean:
	rm -rf *.o build_demo
