#include <stdio.h>
#include <stdlib.h>


void userInput();

void printCifrado(char *mensaje, int *num);
/*void ciclico(char *mensaje, int *num);*/

#define TAMANO 1024		/*tamaño del mensaje*/

char texto[TAMANO] = {0};	/*variable donde se almacenara el mensaje*/
int llaveNum = 0;		/*variable donde se almacenara la llave numerica*/
int ingreso = 0;		/*guardara 1 si el ingreso es valido, 0 si no*/

int main()
{
	userInput();
	
	printCifrado(texto,&llaveNum);

	return(0);
}

void userInput()
{
	char llave[30]={0};

        printf("\nCifrado Cíclico");

        printf("\n\nIngrese mensaje a cifrar: ");
        scanf("%1024[^\n]", texto);

        printf("\n\nIngrese la llave numérica: ");
        scanf("%s", llave);
        llaveNum = atoi(llave);

        if(llaveNum==0)
		printf("\n\nLlave numérica incorrecta!");
        else
        {
                printf("\n\nLlave numérica correcta!");
		ingreso = 1;
        }

}

void printCifrado(char *mensaje, int *num)
{
	printf("\n");
        printf("\n\nMensaje: %s", mensaje);
        printf("\n\nLlave numérica: %i", *num);
        printf("\n");
}
/*
void ciclico(char *mensaje, int *num)
{
	char cifrado[1024];
	int c="";
	char letra="";
	if(num>26)
		int llave = num%26;
	while( EOF != (c = getchar()) )
	{
		if(c<=90 && c>=64)
		{
			if((c+llave)<=90)
			{
				letra = c + llave;
				printf("%s",letra)
			}
			else
			{
				letra = c+llave-90+64-1;
			}
		}
		else if(c<=122 && c>=97)
		{
                        if((c+llave)<=122)
                        {
                                letra = c + llave;
                                printf("%s",letra)
                        }
                        else
                        {
                                letra = c+llave-122+97-1;
                        }
                }

	}
	
}
*/
