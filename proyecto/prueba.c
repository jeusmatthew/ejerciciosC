#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STR_SIZE 40

int validarCaracter(char);
// void validadCadena(char[]);
int isOperator(char);

void limpiarCadena(char*);
// char* trimCadenaMemoria(char*);

void imprimirCaracteres(char*);

void errorLexico(char*);

int main(int argc, char const* argv[]) {
    char cadena[STR_SIZE] = "";

    gets(cadena);
    limpiarCadena(cadena);
    errorLexico(cadena);
    // imprimirCaracteres(cadena);
    // puts(cadena);

    // char caracter = 0;

    // while (caracter != '\n') {
    //     caracter = getchar();

    //     if (validarCaracter(caracter) == 1) {
    //         printf("Error en el caracter %c", caracter);
    //         return 0;
    //     }

    // }
    return 0;
}

void imprimirCaracteres(char* cadena) {
    for (int i = 0; i < STR_SIZE; i++) {
        printf("%d: ascii: %d char: %c\n", i, cadena[i], cadena[i]);
    }
}

// todavia se tienen residuos revisar
void limpiarCadena(char* cadena) {
    // " 1 + 2\n" -> "1+2\0"
    char nuevaCadena[STR_SIZE];
    int j = 0;

    for (int i = 0; i < STR_SIZE; i++) {
        if (!isspace(cadena[i])) {
            nuevaCadena[j++] = cadena[i];
        }
    }
    nuevaCadena[j] = '\0';

    for (int i = 0; i < STR_SIZE; i++) {
        cadena[i] = nuevaCadena[i];
    }

}

void errorLexico(char* cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {



        if (validarCaracter(cadena[i]) == 1) {
            printf("Error lexico en el caracter: %c", cadena[i]);
            return;
        }
    }
}

int isOperator(char caracter) {
    return (caracter >= '(' && caracter <= '+') || caracter == '-' || caracter == '/' || caracter == '^';
}

int validarCaracter(char caracter) {
    return !isdigit(caracter) && !isOperator(caracter);
}