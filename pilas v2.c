#include <stdio.h>
#include <stdlib.h>
// crear una pila

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


int verificarOperador(int* operador) {
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

int main(int argc, char* argv[]) {
	int N, i, temporal, temporal_2;
	Pila pila;
	Item ci;
	// 
	crearPila(&pila);
	//
	scanf("%d", &N);
	insertar(&pila, N);

	scanf("%d", &N);
	insertar(&pila, N);



	ci = cima(&pila);
	//printf("%d", ci);
	temporal = ci;

	eliminarPrimerNodo(&pila);

	ci = cima(&pila);
	//printf("%d", ci);
	temporal_2 = ci;

	eliminarPrimerNodo(&pila);


	insertar(&pila, suma(temporal, temporal_2));


	ci = cima(&pila);
	printf("%d", ci);

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
