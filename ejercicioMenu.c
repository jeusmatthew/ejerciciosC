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
void numeroPrimo(void);
void numeroArmstrong(void);
void numeroRepunit(void);
void numeroPerfecto(void);
void trianguloPascal(void);

int main(int argc, char const* argv[]) {
    int number = 0, opcion = 0;

    do {
        puts("\nMenu:\n1. Primo\n2. Armstrong\n3. Repunit\n4. Perfecto\n5. Triangulo pascal\n0. Salir");
        opcion = leerNumeroEntero();

        if (opcion > 5) puts("Digite una opcion valida!");

    } while (opcion > 5);

    switch (opcion) {
    case 0:
        return 0;
        break;

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
        puts("JIJIJA");
        break;
    }

    return 0;
}

int leerNumeroEntero(void) {
    int number = 0;
    do {
        scanf("%d", &number);
        if (number < 0) puts("Digite un numero mayor a 0");
    } while (number < 0);

    return number;
}

void numeroPrimo(void);
void numeroArmstrong(void);
void numeroRepunit(void);
void numeroPerfecto(void);
void trianguloPascal(void);