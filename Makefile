cifrador: libcifrado.so codificacion.o main.o
	gcc -Wall -Iinclude/ -Llib/ obj/main.o obj/codificacion.o -lcifrado -o bin/cifrador

libcifrado.so: src/cifrado.c
	gcc -Wall -shared -fPIC src/cifrado.c -o lib/libcifrado.so
	#LD_LIBRARY_PATH=./lib
	#export LD_LIBRARY_PATH

codificacion.o: src/codificacion.c
	gcc -Wall -c src/codificacion.c -o obj/codificacion.o

main.o: src/main.c
	gcc -Wall -c src/main.c -Iinclude/ -o obj/main.o

.PHONY: clean
clean:
	rm -f lib/*.so obj/*.o bin/*
