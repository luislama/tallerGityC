#include <stdlib.h>
#include <string.h>
#define TAMANO 100000

char* cifradoCiclico(char* mensaje,int llave)
{
  char* cifrado = (char *) malloc(sizeof(char) * TAMANO);
	int c=0;
	char letra = 'a';

	for(int i = 0; i <= strlen(mensaje); i++)
	{
		c = mensaje[i];
		if(c<=57 && c>=48)
		{
			if((c+llave)<=57)
				letra = c + llave;
			else
				letra = 47+(c+llave-57);
		}
		else if(c<=90 && c>=65)
		{
			if((c+llave)<=90)
				letra = c + llave;
			else
        letra = 64+(c+llave-90);
		}
		else if(c<=122 && c>=97)
		{
      if((c+llave)<=122)
        letra = c + llave;
      else
        letra = 96+(c+llave-122);
    }
		else
		{
			letra = c;
		}
		cifrado[i]=letra;
	}
  return cifrado;
}


char* cifradoAutollave(char* mensaje, char* llave){
  char * cifrado = {0};
  return cifrado;
}

char* cifradoContrasenia(char* mensaje, char* llave){
  char * cifrado = {0};
  return cifrado;
}
