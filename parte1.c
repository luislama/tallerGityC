#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printMessageError(char *name);
void validarLlave(int num);
void userInput();
void ciclico();

void printCifrado();



#define TAMANO 1024		/*tamaño del mensaje*/
char texto[TAMANO] = {0};	/*variable donde se almacenara el mensaje*/
char textoCiclico[TAMANO] = {0};
char textoMorse[TAMANO] = {0}; 


int llaveNum = 0;		/*variable donde se almacenara la llave numerica*/
int argumentos = 1;
int cifrar=0;

char l[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
char m[27][12]={{". ___"},{"___ . . ."},{"___ . ___ ."},{"___ . ."},{"."},{". . ___ ."},{"___ ___ ."},{". . . ."},{". ."},{". ___ ___ ___"},{"___ . ___"},{". ____ . ."},{"___ ___"},{"___ ."},{"___ ___ ___"},{". ___ ___ ."},{"___ ___ . ___"},{". ___ ."},{". . ."},{"___"},{". . ___"},{". . . ___"},{". ___ ___"},{"___ . . ___"},{"___ . ___ ___"},{"___ ___ . ."},{"/"}};


int main(int argc, char *argv[])
{

	argumentos = argc;
	if(argumentos == 1)
	{
		cifrar = 1;
		userInput();
		/*printCifrado();*/
	}
	else if(  argumentos==3  &&  atoi(argv[1])  )
	{
		validarLlave( atoi(argv[1]) );
		strcat(texto,argv[2]);
		cifrar = 1;
	}else
	{
		printMessageError(argv[0]);
	}
	
	if(cifrar==1)
		printCifrado();
	printf("\nel mensaje es: %s\n",textoCiclico);
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
		textoCiclico[i]=letra;
	}
}
