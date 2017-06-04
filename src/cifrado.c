#include <stdlib.h>
#include <string.h>
#define TAMANO 100000

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
			if((c+llave)<=57)
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

char* cifradoAutollave(char* mensaje, char* llave){
  //char * cifrado = {0};
  return mensaje;
}

char* cifradoContrasenia(char* mensaje, char* llave){
  //char * cifrado = {0};
  return mensaje;
}
