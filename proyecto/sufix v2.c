#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
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

void concatenarCharACadena(char c, char* cadena) {
	char cadenaTemporal[2];
	cadenaTemporal[0] = c;
	cadenaTemporal[1] = '\0';
	strcat(cadena, cadenaTemporal);
}


int main(int argc, char* argv[]) {
	int i;
	Pila pila;
	Item ci;
	//pila iniciada vacia
	crearPila(&pila);


	//lista inicida vacia
	char cadena_salida[31] = "";

	char numero[30];
	scanf("%s", numero);
	i = 0;

	while (numero[i] != '\0') {
		//no eliminaremos ningun termino simplemente recorreres el string
		//int var = numero[i] - '0'; solo como nota


		//seccion segun sea

		// si es digito
		if (isdigit(numero[i]) != 0) {
			//insertamos al final de la lista de salida
			char c = numero[i];
			concatenarCharACadena(c, cadena_salida);
		}

		//que es esto de la variable x?????
		/*

		*/

		//si es parentesis izquierdo 
		if (numero[i] == '(') {
			insertar(&pila, numero[i]);
		}

		//si es parentesis derecho 

		//mientras la pila no este vacia y cima no sea (
		if (numero[i] == ')') {
			while ((tamanioPila(pila) != 0) && (cima(&pila) != '(')) {

				//extraemos elemento extraer != destruir
				/*
				ci = cima(&pila);
				temporal = ci;
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA ");
				*/

				//insertamos en la lista de salida
				char c = numero[i];
				concatenarCharACadena(c, cadena_salida);

			}
			if (numero[i] == '(') {
				// extraemos y destuimos
				eliminarPrimerNodo(&pila);
				puts("BORRE LA CIMA ");
			}
			else {
				puts("ERROR 2");
			}

		}
		// si es un operador
		
		if (numero[i] != '^') {
			
		}

		
		if (numero[i] != '/') {

		}
		
		
		if (numero[i] != '*') {

		}
		
		
		
		if (numero[i] == '+') {
			
			while ((tamanioPila(pila) != 0) && verificarPresedencia(cima(&pila), numero[i])) { //<----------------------
				//extraemos elemento de la pila
				ci = cima(&pila);
				//insertamos al final de la lista de salida
				//char c = numero[i];
				concatenarCharACadena(ci, cadena_salida);
			}
			insertar(&pila, numero[i]);
		}
		
		
		if (numero[i] != '-') {
			
		}

		i++;
	}

	//mientras la pila no este vacia
	while (tamanioPila(pila) == 0) {
		//extraemos elemento de la pila
		ci = cima(&pila);
		//temporal_2 = (int)ci;
		//insertamos al final de la lista de salida
		//char c = numero[i];
		concatenarCharACadena(ci, cadena_salida);

	}


	// limpiamos la pila para reutilizarla en la segunda parte
	limpiarPila(&pila);
	return 0;
}
