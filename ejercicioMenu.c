/*
PENDIENTE
dado un numero entero positivo
menu:
1. primo
2. armstrong
3. repunit
4. perfecto
5. triangulo pascal
0. salir
> opcion
cualquier dado incorrecto regresa al meno

firmas:
int primo;

*/
//HOLA
#include <stdio.h>

long long leerNumeroEntero(void);
float elevarAlExponente(float, float);
unsigned digitosNumero(unsigned);
void elegirOpcion(const int);

void numeroPrimo(void);
void numeroArmstrong(void);
void numeroRepunit(void);
void numeroPerfecto(void);
void trianguloPascal(void);

unsigned getFactorial(int num) {
    return num == 0 ? 1 : num * getFactorial(num - 1);
}

int main(int argc, char const* argv[]) {
    int number = 0, opcion = 0;

    do {
        puts("\nMenu:\n1. Primo\n2. Armstrong\n3. Repunit\n4. Perfecto\n5. Triangulo pascal\n0. Salir");
        opcion = leerNumeroEntero();
        elegirOpcion(opcion);

    } while (opcion > 5);

    return 0;
}

long long leerNumeroEntero(void) {
    long long number = 0;
    do {
        puts("Digite un numero");
        scanf("%lld", &number);
        // printf("%lld", number);
        if (number < 0) puts("Dato no valido!\nDigite un numero mayor a 0");
    } while (number < 0);

    return number;
}

void elegirOpcion(const int opc) {
    switch (opc) {
    case 0:
        return;

    case 1:
        numeroPrimo();
        break;

    case 2:
        numeroArmstrong();
        break;

    case 3:
        numeroRepunit();
        break;

    case 4:
        numeroPerfecto();
        break;

    case 5:
        trianguloPascal();
        break;
    default:
        puts("Digite una opcion valida!");
        break;
    }
    return;
}

float elevarAlExponente(float base, float exponent) {
    float resultado;
    resultado = exponent == 0 ? 1 : base * elevarAlExponente(base, exponent - 1);
    return resultado;
}
unsigned digitosNumero(unsigned num) {
    unsigned short numSize = 0;
    while (num > 0) {
        num /= 10;
        numSize++;
    }
    return numSize;
}

void numeroPrimo(void) {
    puts("\nNumero Primo");
    unsigned number = leerNumeroEntero();

    for (int divider = 2; divider < number; divider++) {
        if (number % divider == 0) {
            puts("El numero no es primo");
            return;
        }
    }

    puts("El numero es primo");

    return;
}

void numeroArmstrong(void) {
    puts("\nNumero Armstrong");
    const unsigned originalNumber = leerNumeroEntero();
    unsigned number = originalNumber, sumatoria = 0, numberSize = digitosNumero(number);
    do {
        sumatoria += elevarAlExponente(number % 10, numberSize);
        number /= 10;
    } while (number > 0);

    puts(sumatoria == originalNumber ? "Es un numero armstrong" : "NO es un numero armstrong");

    return;
}

void numeroRepunit(void) {
    puts("\nNumero repunit");
    unsigned number = leerNumeroEntero();
    do {
        if (number % 10 != 1) {
            puts("El numero no es repunit");
            return;
        }
        number /= 10;
    } while (number > 0);

    puts("El numero es repunit");

    return;
}

void numeroPerfecto(void) {
    unsigned number = leerNumeroEntero(), sumatoriaDivisores = 0;

    for (int divisor = 1; divisor < number; divisor++) {
        if (number % divisor == 0) sumatoriaDivisores += divisor;
    }

    if (sumatoriaDivisores == number) puts("El numero es perfecto");
    else puts("El numero no es perfecto");

    return;
}

void trianguloPascal(void) {
    unsigned number = leerNumeroEntero();

    for (int row = 0; row < number; row++) {
        //espacios en blanco
        for(int espacio = number - row - 1; espacio > 0; espacio--){
            putchar(' ');
        }
        
        //formula que da
        for (int column = 0; column <= row; column++) {
            printf("%u ", getFactorial(row) / (getFactorial(column) * getFactorial(row - column)));
        }

        putchar('\n');
    }
    return;
}