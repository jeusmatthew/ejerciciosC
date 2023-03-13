//fuente: AR PL KaitiM Big5
#include <stdio.h>

// recibe caracter cima y recibe e el numero
int verificarPrecedencia(char, char);

int main(int argc, char *argv[]) {
	int prioridad_a,  prioridad_b, res;
	
/*	char ci[5];*/
/*	char e[5];*/
	
/*	scanf("%d", &e);*/
/*	printf("%c", e);*/
	
/*	scanf("%d", &ci);*/
/*	printf("%c", ci);*/
	
	char ci;
	char e;
	ci = getchar();
	e = getchar();
	
	//ci = cima(&pila);
	if (ci == '('){
		prioridad_a = 4;
	}
	if (ci == ')'){
		prioridad_a = 4;
	}
	if (ci  == '^'){
		prioridad_a = 3;
	}
	if (ci  == '*'){
		prioridad_a = 2;
	}
	if (ci  == '/'){
		prioridad_a = 2;
	}
	if (ci  == '+'){
		prioridad_a = 1;
	}
	if (ci  == '-'){
		prioridad_a = 1;
	}
	
	
	
	//numero[i] = e
	if (e == '('){
		prioridad_b = 4;
	}
	if (e == ')'){
		prioridad_b = 4;
	}
	if (e == '^'){
		prioridad_b = 3;
	}
	if (e == '*'){
		prioridad_b = 2;
	}
	if (e == '/'){
		prioridad_b = 2;
	}
	if (e == '+'){
		prioridad_b = 1;
	}
	if (e == '-'){
		prioridad_b = 1;
	}
	
	if (prioridad_a >= prioridad_b){
		res = 1; // si se cumple la condicion
		puts("se cumple");
	} else {
		res = 0; //no se cumple la condicion
		puts("NOOO se cumple");
	}
	
	return 0;
}



int verificarPrecedencia(char ci, char e){
	int prioridad_a, prioridad_b;
		
	//ci = cima(&pila);
	if (ci == '('){
		prioridad_a = 4;
	}
	if (ci == ')'){
		prioridad_a = 4;
	}
	if (ci  == '^'){
		prioridad_a = 3;
	}
	if (ci  == '*'){
		prioridad_a = 2;
	}
	if (ci  == '/'){
		prioridad_a = 2;
	}
	if (ci  == '+'){
		prioridad_a = 1;
	}
	if (ci  == '-'){
		prioridad_a = 1;
	}
	
	//numero[i] = e
	if (e == '('){
		prioridad_b = 4;
	}
	if (e == ')'){
		prioridad_b = 4;
	}
	if (e == '^'){
		prioridad_b = 3;
	}
	if (e == '*'){
		prioridad_b = 2;
	}
	if (e == '/'){
		prioridad_b = 2;
	}
	if (e == '+'){
		prioridad_b = 1;
	}
	if (e == '-'){
		prioridad_b = 1;
	}

	return prioridad_a >= prioridad_b;
	
	// if (prioridad_a <= prioridad_b){
	// 	return 1; // si se cumple la condicion
	// 	puts("se cumple");
	// } else {
	// 	return 0; //no se cumple la condicion
	// 	puts("NOOO se cumple");
	// }
	
}
