#include <stdio.h>
#include <stdlib.h>

int main() {
    char c = '9';
    int i = atoi(&c);
    printf("El caracter '%c' convertido a int es: %d\n", c, i);
    return 0;
}