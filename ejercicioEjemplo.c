#include <stdio.h>

void imprime();
int a = 10; //Ámbito del programa
int main() {
    a += 5;
    printf("a=% d\n", a);
    imprime();
    //printf("%d\n", c); Error Ámbito de función
    for (int i = 1;i < 5; i++) { //Ámbito de bloque
        printf("i= %d\n", i);
    }
    //printf("%d\n", i); Error Ámbito bloque
    if (a == 20) {
        int j = -1; //Ámbito de bloque
        printf("j= %d\n", j);
    }
    //printf("%d\n", j); Error Ámbito bloque
    //printf("%d\n", m); Error Ámbito archivo fuente
    return 0;
}

static int m = 0; //Ámbito de archivo fuente
void imprime() {
    int c = 0; //Ámbito de función
    c += 5;
    printf("c=%d\n", c);
    a += 5;
    printf("a= %d\n", a);
    printf("m= %d\n", m);
    return;
}