#include <stdlib.h>
#include <string.h>
#define TAMANO 10000

char* cifradoCiclico(char* mensaje,int llave)
{

	int key = validarLlave(llave);
	char* cifrado = (char *) malloc(sizeof(char) * TAMANO);

	int c=0;
	char letra = 'a';

	for(int i = 0; i <= strlen(mensaje); i++)
	{
		c = mensaje[i];
		if(c<=57 && c>=48)
		{
			if((c+key)<=57)
				letra = c + key;
			else
				letra = 47+(c+key-57);
		}
		else if(c<=90 && c>=65)
		{
			if((c+key)<=90)
				letra = c + key;
			else
        			letra = 64+(c+key-90);
		}
		else if(c<=122 && c>=97)
		{
			if((c+key)<=122)
				letra = c + key;
			else
				letra = 96+(c+key-122);
		}
		else
		{
			letra = c;
		}
		cifrado[i]=letra;
	}
	return cifrado;
}

int validarLlave(int num){
	int llaveNum = num;
	if(llaveNum>26 || llaveNum<-26)
		llaveNum %= 26;
	if(llaveNum<0)
		llaveNum += 26;
	return llaveNum;
}

char* cifradoAutollave(char* mensaje, char* llave)
{
	char* cifrado = (char *) malloc(sizeof(char) * TAMANO);

	//no quiero hacer for, y el strcat me da problemas con
	//los char* texto = "letras";

	char* mensajeA[TAMANO] = {0};	//Guarda HOLA PEDRO
	char* llaveA[TAMANO] = {0};	//Me da MARAZULHOLA PEDRO
					//usando strcat

	strcat( mensajeA, mensaje);
	strcat( llaveA, llave);
	strcat( llaveA, mensajeA);		//MARAZULHOLA PEDRO

	printf("mensaje: %s\n",mensajeA);
	printf("llave: %s\n",llaveA);


	int c = 0;
	int d = 0;
	int j = 0;
	for(int i=0; i<strlen(llaveA); i++)
	{
		c = llaveA[i];
		d = llaveA[j];
		while( d<65 || (d>90 && d<97) ||  d>122 )
                {
                        j++;
			d = llaveA[j];
                }
                llaveA[i] = llaveA[j];
                j++;
	}					//MARAZULHOLAPEDRO

	printf("llave Completa: %s\n",llaveA);

	char letra = 'a';
	int mayus = 1;
	int noLetra = 0;
	int spacSimbNum = 0;

	for(int i = 0; i<= strlen(mensajeA); i++)
	{
		noLetra = 0;
		mayus = 1;
		c = mensajeA[i];

		if( c<=122 && c>=97 )
		{
			c -= 32;
			mayus = 0;
		}

		if( c<=90 && c>=65 )
		{
			c += ( llaveA[i-spacSimbNum] - 65);

			if( c>90 )
				c = (c-90) + 64;
			if(mayus == 0)
				c += 32;
		}
		else
		{
			noLetra = 1;
			spacSimbNum++;
		}

		if( noLetra == 1 )
			cifrado[i] = mensajeA[i];
		else
		{
			letra = c;
			cifrado[i] = letra;
		}
	}
	printf("Mensaje en autollave: %s",cifrado);
	return cifrado;
}

char* cifradoContrasenia(char* mensaje, char* llave)
{
	char* cifrado = (char *) malloc(sizeof(char) * TAMANO);

        char mensajeA[TAMANO]={0};
        char llaveA[TAMANO]={0};

        strcat( mensajeA, mensaje);
        strcat( llaveA, llave);

	int size = strlen(llaveA);

	int c = 0;
        char letra = 'a';
        int noLetra=1;
        int mayus = 1;
        int indice = 0;
        int psswrd = 0;

	for(int i = 0; i <= strlen(mensajeA); i++)
        {
                noLetra = 0;
                mayus = 1;
                psswrd = 0;
                c = mensajeA[i];

		if(c<=122 && c>=97)
                {
                        c -= 32;
                        mayus = 0;
                }
                if(c<=(64+size) && c>=65) //llave MARAZUL(7) --> (65,71)
                {
                        indice = c-65;
                        psswrd = 1;
                }
		else if (c>(64+size) && c<97)
                {
                        c -= size;
                }
                else
                {
                        noLetra = 1;
                }

                if( mayus == 0 )
                        c += 32;
                if( noLetra == 1 )
                        cifrado[i]=mensajeA[i];
                else if(psswrd == 1)
                {
                        letra = llaveA[indice];
                        cifrado[i] = letra;
                }
                else
                {
                        letra = c;
                        cifrado[i] = letra;
                }
        }
	printf("Mensaje en contrasenia: %s",cifrado);
	return cifrado;
}
