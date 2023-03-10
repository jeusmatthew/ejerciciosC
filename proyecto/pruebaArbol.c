#include <stdio.h>
#include <string.h>
#include <ctype.h>

void infijaAPosfija(char*);
void concatenarCharACadena(char, char*);

int main(int argc, char const* argv[]) {
    char infija[10] = "2+2*3";

    // concatenarCharACadena('c', infija);
    // concatenarCharACadena('9', infija);
    // puts(infija);

    return 0;
}

void concatenarCharACadena(char c, char* cadena) {
    char cadenaTemporal[2];
    cadenaTemporal[0] = c;
    cadenaTemporal[1] = '\0';
    strcat(cadena, cadenaTemporal);
}

void infijaAPosfija(char* cadena) {
    char pila[10];
    char listaSalida[10];

    int error = 0;

    while (!error) {
        for (int i = 0; i < 10; i++) {
            char e = cadena[i];

            if (isdigit(e)) {
                concatenarCharACadena(e, listaSalida);
            }
            else if (e == '(') {
                concatenarCharACadena(e, pila);
            }

        }
    }

}