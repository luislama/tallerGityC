#include "cifrado.h"
#define TAMANO 1024

char* cifradoCiclico(char* mensaje,int llave){
  char* cifrado = {0};
  llave = llave%26;
	for (int i=0; i<TAMANO-1; i++){ //recorre el arreglo de caracteres
		int caracter = (int)mensaje[i];
		if (caracter!='\0'){ //verifica que no sea el ultimo caracter
			if ((caracter>=65 && caracter<=90) || (caracter>=97 && caracter<=122)){
				int suma = caracter + llave;
				if (llave>0){ //para llaves positivas
					if (caracter>=65 && caracter<=90){ //verifica rango de mayusculas
							if (suma > 90)
								caracter = 64 + (suma-90);
							else
								caracter += llave;
					}else{ //rango de minusculas
							if (suma > 122)
								caracter = 96 + (suma-122);
							else
								caracter += llave;
					}
				}else{ //para llaves negativas
					if (caracter>=65 && caracter<=90){ //rango de mayusculas
							if (suma < 65)
								caracter = 91 + (suma-65);
							else
								caracter += llave;
					}else{ //rango de minusculas
							if (suma < 97)
								caracter = 123 + (suma-97);
							else
								caracter += llave;
					}
				}
				cifrado[i]=caracter;
			}
		}else
			break;
	} //cierre for
  return cifrado;
}


/*char* cifradoAutollave(char* mensaje, char* llave){

}

char* cifradoContrasenia(char* mensaje, char* llave){

}*/
