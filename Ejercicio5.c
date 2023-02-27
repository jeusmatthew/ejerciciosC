#include <stdio.h>

#define PI 3.141516

float calcularAreaCirculo(float);
float calcularAreaSombreada(float, float);
// float leerFlotante();
void leerFlotante(float*);

int main(int argc, char const* argv[]) {
    float radioExterno = 0, radioInterno = 0, areaExterna = 0, areaInterna = 0;

    puts("Digite el radio interno");
    leerFlotante(&radioInterno);

    puts("Digite el radio externo");
    leerFlotante(&radioExterno);

    areaExterna = calcularAreaCirculo(radioExterno);
    areaInterna = calcularAreaCirculo(radioInterno);

    printf("Area sombreada: %.4f", calcularAreaSombreada(areaExterna, areaInterna));

    return 0;
}

// float leerFlotante() {
//     float var;
//     scanf("%f", &var);
//     return var;
// }

void leerFlotante(float* ptrVar) {
    scanf("%f", ptrVar);
    return;
}

float calcularAreaCirculo(float radio) {
    return PI * radio * radio;
}

float calcularAreaSombreada(float aExterna, float aInterna) {
    return aExterna - aInterna;
}
