#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
// crear una pila
//https://parzibyte.me/blog/2018/11/19/digito-char-entero-c/#:~:text=Si%20queremos%20convertir%20un%20char,el%20car%C3%A1cter%20ASCII%20n%C3%BAmero%2053.

//funciones de nodos
typedef char Item;
typedef struct nodo {
    Item elemento;
    struct nodo* siguiente;
} Nodo;

typedef struct pila {
    Nodo* cima;
} Pila;
void crearPila(Pila*);
int pilaVacia(Pila);
Item cima(Pila*);
void insertar(Pila*, Item);
void eliminarPrimerNodo(Pila*);
void limpiarPila(Pila*);
int tamanioPila(Pila);

//funciones
void concatenarCharACadena(char, char*);
int verificarPresedencia(char, char);
void errorLexico(char*);
int isOperator(char);
int validarCaracter(char);
void infijaAPosfija(char*);

int main(int argc, char* argv[]) {
    char cadena[31];
    gets(cadena);
    infijaAPosfija(cadena);
    puts(cadena);
}

void infijaAPosfija(char* cadenaInfija) {
    Pila pila;
    Item ci;
    char cadenaSalida[31] = "";
    int error = 0;

    crearPila(&pila);

    int i = 0;
    while (cadenaInfija[i] != '\0' && !error) {
        char e = cadenaInfija[i];

        if (isdigit(e))
            concatenarCharACadena(e, cadenaSalida);
        else if (e == '(')
            insertar(&pila, e);
        else if (e == ')') {
            while (tamanioPila(pila) != 0 && cima(&pila) != '(') {
                ci = cima(&pila);
                eliminarPrimerNodo(&pila);
                concatenarCharACadena(ci, cadenaSalida);
            }
            if (cima(&pila) == '(')
                eliminarPrimerNodo(&pila);
            else
                error = 1;
        }
        else if (isOperator(e)) {
            while (tamanioPila(pila) != 0 && verificarPresedencia(cima(&pila), e)) {
                ci = cima(&pila);
                eliminarPrimerNodo(&pila);
                concatenarCharACadena(ci, cadenaSalida);
            }
            insertar(&pila, e);
        }
        i++;
    }

    while (tamanioPila(pila) != 0) {
        ci = cima(&pila);
        eliminarPrimerNodo(&pila);
        concatenarCharACadena(ci, cadenaSalida);
    }

    limpiarPila(&pila);
    strcpy(cadenaInfija, cadenaSalida);
}

void crearPila(Pila* pila) {
    pila->cima = NULL;
}

int pilaVacia(Pila pila) {
    return pila.cima == NULL;
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

int verificarPresedencia(char ci, char e) {
    int prioridad_a, prioridad_b;

    switch (ci) {
    case '(':
    case ')':
        prioridad_a = 4;
        break;

    case '^':
        prioridad_a = 3;
        break;

    case '*':
    case '/':
        prioridad_a = 2;
        break;
    case '+':
    case '-':
        prioridad_a = 1;
    }

    switch (e) {
    case '(':
    case ')':
        prioridad_b = 4;
        break;

    case '^':
        prioridad_b = 3;
        break;

    case '*':
    case '/':
        prioridad_b = 2;
        break;
    case '+':
    case '-':
        prioridad_b = 1;
    }

    return prioridad_a <= prioridad_b;
}

void errorLexico(char* cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {

        if (validarCaracter(cadena[i]) == 1) {
            printf("Error lexico en el caracter: %c", cadena[i]);
            return;
        }
    }
}

int isOperator(char caracter) {
    return caracter == '*' || caracter == '+' || caracter == '-' || caracter == '/' || caracter == '^';
}

int validarCaracter(char caracter) {
    return !isdigit(caracter) && !isOperator(caracter);
}