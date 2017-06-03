#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cifrado.h"
#include "codificacion.h"

#define MAX 10000

void mostrarMensaje(char* mensaje);
void mostrarMorse(char** morse);

int main(int argc, char** argv){
	int llaveN = 0;

	if (argc == 4){
		if (argv[3][0]=='-' && argv[3][1]=='c'){
			llaveN = atoi(argv[1]);
			if (llaveN == 0){
				printf("No puede ingresar ese valor de llave\n\n");
			}
			else{
				char* mensajeCifrado = cifradoCiclico(argv[2],llaveN);
				printf("Mensaje cifrado: ");
				mostrarMensaje(mensajeCifrado);
				char** mensajeMorse = claveMorse(mensajeCifrado);
				printf("Mensaje cifrado en morse: ");
				mostrarMorse(mensajeMorse);
			}
		}
		else if (argv[3][0]=='-' && argv[3][1]=='a'){
			char* mensajeCifrado = cifradoAutollave(argv[2],argv[1]);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(mensajeCifrado);
			char** mensajeMorse = claveMorse(mensajeCifrado);
			printf("Mensaje cifrado en morse: ");
			mostrarMorse(mensajeMorse);
		}
		else if (argv[3][0]=='-' && argv[3][1]=='p'){
			char* mensajeCifrado = cifradoContrasenia(argv[2],argv[1]);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(mensajeCifrado);
			char** mensajeMorse = claveMorse(mensajeCifrado);
			printf("Mensaje cifrado en morse: ");
			mostrarMorse(mensajeMorse);
		}
		else{
			printf("Tipo de cifrado invalido\n\n");
		}
	}
	else if (argc == 1){
		printf("\nTipo de cifrado: ");
		char c = getchar();
		if (c=='C' || c=='c'){
			printf("\nCifrado Ciclico");
			printf("\nIngrese mensaje a cifrar: ");
			printf("\nIngrese clave numerica: ");
			//char* mensajeCifrado = cifradoCiclico(mensaje,llaveN);
			//mostrarMensaje(mensajeCifrado);
		}
		else if (c=='A' || c=='a'){

		}
		else if (c=='P' || c=='p'){

		}
		else{
			printf("Tipo de cifrado invalido\n");
		}
	}
	else{
		printf("No puede llamar al programa con esos parametros...\n\n");
	}
	return 0;
}

void mostrarMensaje(char* mensaje){
	int i=0;
	while (mensaje[i]!='\0'){
		printf("%c", mensaje[i]);
		i++;
	}
	printf("\n");
}

void mostrarMorse(char** morse){
	int c=0;
	while (morse[c]) {
		printf("%s", morse[c]);
		c++;
	}
	printf("\n\n");
}
