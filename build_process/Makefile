CC=gcc

build_demo: build_demo.o add.o sub.o
	$(CC) -o build_demo build_demo.o add.o sub.o

build_demo.o: build_demo.c
	$(CC) -c -o build_demo.o build_demo.c

add.o: add.c
	$(CC) -c -o add.o add.c

sub.o: sub.c
	$(CC) -c -o sub.o sub.c

clean:
	rm -rf *.o build_demo
