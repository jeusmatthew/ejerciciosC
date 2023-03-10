#include <stdio.h>
#include <string.h>

#define MAXIMA_LONGITUD_CADENA 100

// Nota: la cadena deber�a tener espacio suficiente para concatenar el car�cter.
// Esta funci�n no se encarga de evitar desbordamientos o cosas parecidas
// https://parzibyte.me/blog

//2 -> 2\0|
void concatenarCharACadena(char c, char* cadena) {
	char cadenaTemporal[2];
	cadenaTemporal[0] = c;
	cadenaTemporal[1] = '\0';
	strcat(cadena, cadenaTemporal);
}

int main(int argc, char const* argv[]) {
	char cadena[MAXIMA_LONGITUD_CADENA] = "";
	printf("Antes de concatenar: %s\n", cadena);
	// Concatenar
	char c = '+';
	concatenarCharACadena(50, cadena);
	printf("Despu�s de concatenar: %s\n", cadena);
	return 0;
}
