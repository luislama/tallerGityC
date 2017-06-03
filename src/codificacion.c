#include <stdlib.h>
#define TAMANO 10000

char** claveMorse(char* mensaje){
  char** morse = (char **) malloc(sizeof(char) * TAMANO);
  int i = 0;
	while (mensaje[i]!='\0'){
		char caracter = mensaje[i];
		if (caracter=='A' || caracter=='a')
			morse[i] = ".- ";
		else if (caracter=='B' || caracter=='b')
			morse[i] = "-... ";
		else if (caracter=='C' || caracter=='c')
			morse[i] = "-.-. ";
		else if (caracter=='D' || caracter=='d')
			morse[i] = "-.. ";
		else if (caracter=='E' || caracter=='e')
			morse[i] = ". ";
		else if (caracter=='F' || caracter=='f')
			morse[i] = "..-. ";
		else if (caracter=='G' || caracter=='g')
			morse[i] = "--. ";
		else if (caracter=='H' || caracter=='h')
			morse[i] = ".... ";
		else if (caracter=='I' || caracter=='i')
			morse[i] = ".. ";
		else if (caracter=='J' || caracter=='j')
			morse[i] = ".--- ";
		else if (caracter=='K' || caracter=='k')
			morse[i] = "-.- ";
		else if (caracter=='L' || caracter=='l')
			morse[i] = ".-.. ";
		else if (caracter=='M' || caracter=='m')
			morse[i] = "-- ";
		else if (caracter=='N' || caracter=='n')
			morse[i] = "-. ";
		else if (caracter=='O' || caracter=='o')
			morse[i] = "--- ";
		else if (caracter=='P' || caracter=='p')
			morse[i] = ".--. ";
		else if (caracter=='Q' || caracter=='q')
			morse[i] = "--.- ";
		else if (caracter=='R' || caracter=='r')
			morse[i] = ".-. ";
		else if (caracter=='S' || caracter=='s')
			morse[i] = "... ";
		else if (caracter=='T' || caracter=='t')
			morse[i] = "- ";
		else if (caracter=='U' || caracter=='u')
			morse[i] = "..- ";
		else if (caracter=='V' || caracter=='v')
			morse[i] = "...- ";
		else if (caracter=='W' || caracter=='w')
			morse[i] = ".-- ";
		else if (caracter=='X' || caracter=='x')
			morse[i] = "-..- ";
		else if (caracter=='Y' || caracter=='y')
			morse[i] = "-.-- ";
		else if (caracter=='Z' || caracter=='z')
			morse[i] = "--.. ";
		else if (caracter==' ')
			morse[i] = "/ ";
		else{
			char c[3] = {(char)caracter,' ','\0'};
			morse[i] = c;
			//strcpy(morse[i],(char [3]){(char)caracter,' ','\0'});
		}
		i++;
	}
	morse[i] = NULL;
  return morse;
}
