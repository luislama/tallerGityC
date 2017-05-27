#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printMessageError(char *name);
void validarLlave(int num);
void userInput();
void cifrado();
int buscarIndice(char letra);
void printCifrado();



#define TAMANO 1024		/*tamaño del mensaje*/
char texto[TAMANO] = {0};	/*variable donde se almacenara el mensaje*/
char textoCiclico[TAMANO] = {0};
char textoMorse[TAMANO] = {0}; 


int llaveNum = 0;		/*variable donde se almacenara la llave numerica*/
int argumentos = 1;
int cifrar=0;

char l[37]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9',' '};
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
	{
		cifrado();
		printCifrado();
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

void printCifrado()
{
	printf("\n\nMensaje Cifrado: %s ",textoCiclico);
	printf("\n\nMensaje Cifrado en morse: %s ",textoMorse);
        printf("\n\n");
}

void cifrado()
{
	int c=0;
	char letra = 'a';

	for(int i = 0; i <= strlen(texto); i++) 
	{
		c = texto[i];
		if(c<=57 && c>=48)
		{
			if((c+llaveNum)<=57)
				letra = c + llaveNum;
			else
				letra = 47+(c+llaveNum-57);
		}
		else if(c<=90 && c>=65)
		{
			if((c+llaveNum)<=90)
				letra = c + llaveNum;
			else
				letra = 64+(c+llaveNum-90);
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
		textoCiclico[i]=letra;
		strcat(  textoMorse, m[ buscarIndice(textoCiclico[i]) ]  );
		strcat( textoMorse, m[37] );
	}
}

int buscarIndice(char letra)
{
	if(letra>=65 && letra<=90)
		letra += 32;
	int indice=-1;
	for(int i=0; i<37; i++)
	{
		if(l[i]==letra)
			indice = i;
	}
	return indice;
}
