#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cifrado.h"
#include "codificacion.h"

#define MAX 10000

void mostrarMensaje(char* mensaje);
void mostrarMorse(char** morse);
char mensaje[MAX] = {0};
char llave[MAX] = {0};

int main(int argc, char** argv){
	int llaveN = 0;

	if (argc == 4){
		if ( (argv[3][0]=='-' && argv[3][1]=='c') || (argv[3][0]=='-' && argv[3][1]=='a')
			|| (argv[3][0]=='-' && argv[3][1]=='p') ){
				char* mensajeCifrado;
				if (argv[3][0]=='-' && argv[3][1]=='c'){
					llaveN = atoi(argv[1]);
					if (llaveN == 0){
						printf("No puede ingresar ese valor de llave\n\n");
						return 0;
					}
					else{
						mensajeCifrado = cifradoCiclico(argv[2],llaveN);
					}
				}
				else if (argv[3][0]=='-' && argv[3][1]=='a'){
					mensajeCifrado = cifradoAutollave(argv[2],argv[1]);
				}
				else {
					mensajeCifrado = cifradoContrasenia(argv[2],argv[1]);
				}
				printf("Mensaje cifrado: ");
				mostrarMensaje(mensajeCifrado);
				char** mensajeMorse = claveMorse(mensajeCifrado);
				printf("Mensaje cifrado en morse: ");
				mostrarMorse(mensajeMorse);
		}
		else{
			printf("Tipo de cifrado invalido\n\n");
			return 0;
		}
	}
	else if (argc == 1){
		char* mensajeCifrado;
		char c;
		printf("Tipo de cifrado: ");
		scanf("%s",&c);

		if (c=='C' || c=='c'){
			printf("Cifrado ciclico");
			printf("\nIngrese el mensaje a cifrar: ");
			scanf(" %[^\n]", mensaje);

			while(llaveN == 0)
			{
	      printf("Ingrese la llave numerica: ");
	    	scanf("%s", llave);
	      llaveN = atoi(llave);
				if(llaveN == 0)
			 		printf("\nLlave numérica incorrecta!\n");
			}
			mensajeCifrado = cifradoCiclico(mensaje,llaveN);
		}

		else if (c=='A' || c=='a'){
			printf("Cifrado autollave");
			printf("\nIngrese el mensaje a cifrar: ");
			scanf(" %[^\n]", mensaje);
			printf("Ingrese la llave: ");
			scanf(" %[^\n]", llave); //ME VALIO VALIDAR LA LLAVE
			mensajeCifrado = cifradoAutollave(mensaje,llave);
		}

		else if (c=='P' || c=='p'){
			printf("Cifrado contrasenia");
			printf("\nIngrese el mensaje a cifrar: ");
			scanf(" %[^\n]", mensaje);
			printf("Ingrese la llave: ");
			scanf(" %[^\n]", llave); //ME VALIO VALIDAR LA LLAVE
			mensajeCifrado = cifradoContrasenia(mensaje,llave);
		}
		else{
			printf("Tipo de cifrado invalido\n");
			return 0;
		}
		printf("\nMensaje cifrado: ");
		mostrarMensaje(mensajeCifrado);
		char** mensajeMorse = claveMorse(mensajeCifrado);
		printf("\nMensaje cifrado en morse: ");
		mostrarMorse(mensajeMorse);
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
