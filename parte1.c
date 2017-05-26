#include <stdio.h>

#define TAMANO 1024

char texto[TAMANO]={0};

int main()
{
   char str2[30]={0};

	printf("\nCifrado Cíclico");

 	printf("\n\nIngrese mensaje a cifrar: ");
	scanf("%1024[^\n]", texto);

 	printf("\n\nIngrese la llave numérica: ");
	scanf("%s", str2);

	printf("\n");
	printf("\n\nMensaje: %s", texto);
	printf("\n\nLlave numérica: %s", str2);
	printf("\n");
   
   return(0);
}
