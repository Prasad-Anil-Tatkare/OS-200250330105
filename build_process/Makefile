

build_demo: build_demo.o add.o sub.o
	gcc -o build_demo build_demo.o add.o sub.o

build_demo.o: build_demo.c
	gcc -c -o build_demo.o build_demo.c

add.o: add.c
	gcc -c -o add.o add.c

sub.o: sub.c
	gcc -c -o sub.o sub.c

