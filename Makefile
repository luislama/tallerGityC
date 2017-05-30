cifrador: libcifrado.so codificacion.o main.o
	gcc -Wall -Llib/ -Iinclude/ obj/codificacion.o obj/main.o -lcifrado -o bin/cifrador

#cifrado.o: src/cifrado.c
#	gcc -Wall -c src/cifrado.c -o obj/cifrado.o

libcifrado.so: src/cifrado.c
	gcc -Wall -Iinclude/ -shared -fPIC src/cifrado.c -o lib/libcifrado.so
	LD_LIBRARY_PATH=./lib
	export LD_LIBRARY_PATH

codificacion.o: src/codificacion.c
	gcc -Wall -c src/codificacion.c -Iinclude/ -o obj/codificacion.o

#libcodificacion.so:
#	gcc -shared -o lib/libcodificacion.so -fPIC src/codificacion.c

main.o: src/main.c
	gcc -Wall -c src/main.c -Iinclude/ -Llib/ -o obj/main.o

.PHONY: clean
clean:
	rm -f lib/*.so obj/*.o bin/*
