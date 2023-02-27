/*
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

#include <stdio.h>

int leerNumeroEntero(void);
void numeroPrimo(int);
void numeroArmstrong(int);
void numeroRepunit(int);
void numeroPerfecto(int);
void trianguloPascal(int);

int main(int argc, char const* argv[]) {
    int number = 0, opcion = 0;

    puts("Digite la opcion deseada:");
    do {

        puts("Menu:\n1. Primo\n2. Armstrong\n3. Repunit\n4. Perfecto\n5. Triangulo pascal\n0. Salir");
        
    } while (1);

    return 0;
}

int leerNumeroEntero(void) {

    // while
    //     int number;
    // scanf("%d", &number);

    // return number;
}

void numeroPrimo(int);
void numeroArmstrong(int);
void numeroRepunit(int);
void numeroPerfecto(int);
void trianguloPascal(int);