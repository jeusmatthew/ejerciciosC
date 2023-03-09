#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
// crear una pila
//https://parzibyte.me/blog/2018/11/19/digito-char-entero-c/#:~:text=Si%20queremos%20convertir%20un%20char,el%20car%C3%A1cter%20ASCII%20n%C3%BAmero%2053.

typedef int Item;

typedef struct nodo {
	Item elemento;
	struct nodo* siguiente;
}Nodo;

typedef struct {
	Nodo* cima;
}Pila;

void crearPila(Pila* pila) {
	pila->cima = NULL;
}


int pilaVacia(Pila pila) {
	return (pila.cima == NULL);
	// 1 VACIA  0 CON ELEMENTOS
}


//retornar el primer elemento de la pila

Item cima(Pila* pila) {
	if (pilaVacia(*pila)) {
		puts("undeflow");
		exit(1);
	}
	return pila->cima->elemento;
}


// Insertar un elemento a la pila 

void insertar(Pila* pila, Item elemento) {
	Nodo* nuevo;
	nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo->elemento = elemento;
	nuevo->siguiente = pila->cima;
	pila->cima = nuevo;
}

//eliminar un elemeto de la pila
void eliminarPrimerNodo(Pila* pila) {
	if (pilaVacia(*pila) == 0) {
		Nodo* f;
		f = pila->cima;
		pila->cima = f->siguiente;
		free(f);
		//puts("SE ELIMINO EL ELEMENTO");
	}
	else {
		puts("Esta vacia");
	}
}


//LIMPIAR PILA

void limpiarPila(Pila* pila) {
	while (!pilaVacia(*pila)) {
		eliminarPrimerNodo(pila);
	}
}


//cantidad de elementos en la pila

int tamanioPila(Pila pila) {
	Nodo* act;
	int cantElementos = 0;
	for (act = pila.cima; act != NULL; act = act->siguiente) {
		cantElementos++;
	}
	return cantElementos;
}


int suma(int argumento1, int argumaneto2) {
	int res;
	res = argumento1 + argumaneto2;
	return res;
}
int resta(int argumento1, int argumaneto2) {
	int res;
	res = argumento1 - argumaneto2;
	return res;
}
int multiplicacion(int argumento1, int argumaneto2) {
	int res;
	res = argumento1 * argumaneto2;
	return res;
}
int division(int argumento1, int argumaneto2) {
	int res;
	res = argumento1 / argumaneto2;
	return res;
}
int potencia(int argumento1, int argumaneto2) {
	int res;
	res = pow(argumento1 , argumaneto2);
	return res;
}



int main(int argc, char* argv[]) {
	int  temporal, temporal_2;
	Pila pila;
	Item ci;
	crearPila(&pila);
	
	
	/**
	scanf("%d", &N);
	insertar(&pila, N);

	scanf("%d", &N);
	insertar(&pila, N);
*/
	char numero[30];
	int i;
	scanf("%s", numero);
	i = 0;
	while (numero[i] != '\0'){
		int contador = 0;
		if (numero[i] != '+'){
			contador++;
		}
		if (numero[i] != '-'){
			contador++;
		}
		if (numero[i] != '/'){
			contador++;
		}
		if (numero[i] != '*'){
			contador++;
		}
		if (numero[i] != '^'){
			contador++;
		}
		if (isdigit(numero[i]) == 0){
			contador++;
		}
		if (contador != 5){
			break;
		}
		
		
		printf("%c numero a evaluar \n", numero[i]);
	
		
		if (isdigit(numero[i]) != 0){
			//var = (int)(numero[i]);
			
			int var = numero[i] - '0';
			
			insertar(&pila, var);
		
			
			ci = cima(&pila);
			printf("%d es la cima \n", ci);
		} else {
			
			if (numero[i] == '+'){
				printf(" entre a la suma \n");
				ci = cima(&pila);
				temporal = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 1 ");
				
				
				ci = cima(&pila);
				temporal_2 = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 2 ");
				
				insertar(&pila, suma(temporal, temporal_2));
				ci = cima(&pila);
				printf("%d es la cima \n", ci);
				
			}
			if (numero[i] == '*'){
				printf(" entre a la multiplicacion \n");
				ci = cima(&pila);
				temporal = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 1 ");
				
				
				ci = cima(&pila);
				temporal_2 = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 2 ");
				
				insertar(&pila, multiplicacion(temporal, temporal_2));
				ci = cima(&pila);
				printf("%d es la cima \n", ci);
				
				
				
			}
			if (numero[i] == '-'){
				printf(" entre a la resta \n");
				ci = cima(&pila);
				temporal = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 1 ");
				
				
				ci = cima(&pila);
				temporal_2 = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 2 ");
				
				insertar(&pila, resta(temporal_2, temporal));
				ci = cima(&pila);
				printf("%d es la cima \n", ci);
				
			}
			if (numero[i] == '/'){
				printf(" entre a la division \n");
				ci = cima(&pila);
				temporal = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 1 ");
				
				
				ci = cima(&pila);
				temporal_2 = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 2 ");
				
				insertar(&pila, division( temporal_2,temporal ));
				ci = cima(&pila);
				printf("%d es la cima \n", ci);
				
				
				
			}
			if (numero[i] == '^'){
				printf(" entre a la potencia \n");
				ci = cima(&pila);
				temporal = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 1 ");
				
				
				ci = cima(&pila);
				temporal_2 = (int)ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA 2 ");
				
				insertar(&pila, potencia( temporal_2,temporal ));
				ci = cima(&pila);
				printf("%d es la cima \n", ci);
				
				
				
			}
			
			
		}
		
		i++;
	}
	ci = cima(&pila);
	printf("%d es el resultado final \n", ci);

	return 0;
}

/*
//
crearPila(&pila);
//
scanf("%d", &N);
insertar(&pila, N);
///
eliminarPrimerNodo(&pila);
//
tamanioPila(pila);
//
Item ci;
ci = cima(&pila);
printf("%d", ci);
//https://www.youtube.com/watch?v=M1al4S4i9o0
*/
