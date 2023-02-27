#include <stdio.h>

float powa(float, float);
unsigned factorial(unsigned);
float serieEX(float, int);
float serieE_X(float, int);
float serieLn(float, int);

int main(int argc, char const *argv[])
{

	float x = 0;
	int n = 0;
	puts("Digite el valor de x");
	scanf("%f", &x);
	puts("Digite el valor de la potencia");
	scanf("%d", &n);

	printf("%f", serieEX(x, n));

	return 0;
}



float serieEX(float x, int n)
{
	float sumatoria = 0;
	for (int i = 0; i <= n; i++)
	{
		sumatoria += powa(x, i) / factorial(n);
	}
	return sumatoria;
}

float serieE_X(float x, int n){
	float resultado = 1;

	// for(int i = 0)

}

float powa(float base, float exponent)
{
	if (exponent == 0)
		return 1;
	else
		return base * powa(base, exponent - 1);
}

unsigned factorial(unsigned num)
{
	return num == 0 ? 1 : num * factorial(num - 1);
}
