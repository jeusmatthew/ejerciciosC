#include <stdio.h>
#include <ctype.h>
#include <string.h>


void leerValores();

void verificarErrorSintactico();

void verificarErrorLexico();

void operacion();

void convertirPosfija();

void obtenerResultado();

int verificarOperador(int *operador) {
    switch (*operador) {
    case '+':
    
        break;

    case '-':
        break;

    case '*':
        break;

    case '/':
        break;

    default:

        break;
    }
}

int main(int argc, char const* argv[]) {
    int arr[10];
    char caracter;

    while (caracter != '\n') {
        caracter = getchar();
        printf("%d", isdigit(caracter));
    }
    return 0;
}

