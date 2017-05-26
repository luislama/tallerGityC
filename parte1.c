#include <stdio.h>
#include <stdlib.h>

#define TAMANO 1024

char texto[TAMANO]={0};

int main()
{
	char llave[30]={0};
	int llaveNum=0;

	printf("\nCifrado Cíclico");

 	printf("\n\nIngrese mensaje a cifrar: ");
	scanf("%1024[^\n]", texto);

 	printf("\n\nIngrese la llave numérica: ");
	scanf("%s", llave);
	llaveNum = atoi(llave);

	if(llaveNum==0)
		printf("\n\nLlave numérica incorrecta!");
	else
		printf("\n\nLlave numérica correcta!");

	printf("\n");
	printf("\n\nMensaje: %s", texto);
	printf("\n\nLlave numérica: %s", llave);
	printf("\n");

   return(0);
}
