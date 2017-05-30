#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cifrado.h"
#include "codificacion.h"

void printMessageError(char* name);
void validarLlave(int num);
void userInput();
void printCifrado();
void mostrarMensaje(char* mensaje);

#define TAMANO 1024		/*tamaño del mensaje*/
char texto[TAMANO] = {0};	/*variable donde se almacenara el mensaje*/

int llaveNum = 0;		/*variable donde se almacenara la llave numerica*/
int argumentos = 1;
int cifrar = 0;

char m[38][19]={{". ---"},{"--- . . ."},{"--- . --- ."},{"--- . ."},{"."},{". . --- ."},{"--- --- ."},{". . . ."},{". ."},{". --- --- ---"},{"--- . ---"},{". --- . ."},{"--- ---"},{"--- ."},{"--- --- ---"},{". --- --- ."},{"--- --- . ---"},{". --- ."},{". . ."},{"---"},{". . ---"},{". . . ---"},{". --- ---"},{"--- . . ---"},{"--- . --- ---"},{"--- --- . ."},{". --- --- --- ---"},{". . --- --- ---"},{". . . --- ---"},{". . . . ---"},{". . . . ."},{"--- . . . ."},{"--- --- . . ."},{"--- --- --- . ."},{"--- --- --- --- ."},{"--- --- --- --- ---"},{"/"},{"   "}};


int main(int argc, char *argv[])
{
	argumentos = argc;
	if(argumentos == 1)
	{
		cifrar = 1;
		userInput();
		/*printCifrado();*/
	}
	else if(argumentos==3  &&  atoi(argv[1]))
	{
		validarLlave( atoi(argv[1]) );
		strcat(texto,argv[2]);
		cifrar = 1;
	}else
		printMessageError(argv[0]);


	if(cifrar==1)
	{
		char* textoCifrado = cifradoCiclico(texto,llaveNum);
		mostrarMensaje(textoCifrado);
	}
	return(0);
}

void printMessageError(char *name)
{
	printf("El programa se lo utiliza de la siguiente manera.\n");
        printf("-con parametros:\n");
        printf("%s integer \"mensaje\"\n",name);
        printf("-sin parametros:\n");
        printf("%s\n\n",name);
}

void userInput()
{
	char llave[30]={0};

        printf("\nCifrado Cíclico");

        printf("\n\nIngrese mensaje a cifrar: ");
        scanf("%1024[^\n]", texto);

	while(llaveNum == 0)
	{
	        printf("\nIngrese la llave numérica: ");
        	scanf("%s", llave);
	        llaveNum = atoi(llave);
		if(llaveNum == 0)
			 printf("\n\nLlave numérica incorrecta!");
	}
	validarLlave(llaveNum);
}

void validarLlave(int num)
{
        llaveNum = num;
      	if(llaveNum>26 || llaveNum<-26)
               	llaveNum %= 26;
        if(llaveNum<0)
       	        llaveNum += 26;
}

/*void printCifrado()
{
	printf("\n\nMensaje Cifrado: %s ",textoCiclico);
	printf("\n\nMensaje Cifrado en morse: %s ",textoMorse);
        printf("\n\n");
}*/

void mostrarMensaje(char* mensaje){
	int i=0;
	while (mensaje[i]!='\0'){
		printf("%c", mensaje[i]);
		i++;
	}
	printf("\n\n");
}
