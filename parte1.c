#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void userInput();

void printCifrado();
void ciclico();

#define TAMANO 1024		/*tamaño del mensaje*/

char texto[TAMANO] = {0};	/*variable donde se almacenara el mensaje*/
int llaveNum = 0;		/*variable donde se almacenara la llave numerica*/

int main()
{
	userInput();
	
	printCifrado();

	return(0);
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
	if(llaveNum>26 || llaveNum<-26)
		llaveNum %= 26;
	if(llaveNum<0)
		llaveNum += 26;
}

void printCifrado()
{
	printf("\nMensaje Cifrado: ");
	ciclico();
        printf("\n\n");
}

void ciclico()
{
	int c=0;
	char letra = 'a';

	for(int i = 0; i <= strlen(texto); i++) 
	{
		c = texto[i];
		if(c<=90 && c>=64)
		{
			if((c+llaveNum)<=90)
				letra = c + llaveNum;
			else
				letra = 63+(c+llaveNum-90);
		}
		else if(c<=122 && c>=97)
		{
                        if((c+llaveNum)<=122)
                                letra = c + llaveNum;
                        else
                                letra = 96+(c+llaveNum-122);
                }
		else 
		{
			letra = c;
		}
		printf("%c",letra);
	}
}
