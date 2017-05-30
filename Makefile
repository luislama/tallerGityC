#programa: parte1.c
#	gcc -Wall parte1.c -o parte1

cifrador: main.o libcifrado.so codificacion.o
	gcc -Wall obj/main.o obj/codificacion.o -Llib/ -o bin/cifrador

#cifrado.o: src/cifrado.c
#	gcc -Wall -c src/cifrado.c -o obj/cifrado.o

libcifrado.so:
	gcc -Iinclude/ -shared -o lib/libcifrado.so -fPIC src/cifrado.c

codificacion.o: src/codificacion.c
	gcc -Wall -c src/codificacion.c -Iinclude/ -o obj/codificacion.o

#libcodificacion.so:
#	gcc -shared -o lib/libcodificacion.so -fPIC src/codificacion.c

main.o: src/main.c
	gcc -Wall -c src/main.c -Iinclude/ -Llib/ -o obj/main.o

.PHONY: clean
clean:
	rm -f lib/*.so obj/*.o bin/*
