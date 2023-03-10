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

//funciones
void crearPila(Pila*);
int pilaVacia(Pila);
Item cima(Pila*);
void insertar(Pila*, Item);
void eliminarPrimerNodo(Pila*);
void limpiarPila(Pila*);
int tamanioPila(Pila);
void concatenarCharACadena(char, char*);
int verificarPresedencia(char, char);
void errorLexico(char*);
int isOperator(char);
int validarCaracter(char);

void infijaAPosfija(char* cadenaInfija) {
    Pila pila;
    Item ci;
    char cadenaSalida[31] = "";
    int error;

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
    return;
}

int main(int argc, char* argv[]) {
    int i = 0;
    Pila pila;
    Item ci;
    //pila iniciada vacia
    crearPila(&pila);

    //lista inicida vacia
    char cadena_salida[31] = "";

    char numero[30];
    gets(numero);
    while (numero[i] != '\0') {
        char e = numero[i];
        //no eliminaremos ningun termino simplemente recorreres el string
        //int var = numero[i] - '0'; solo como nota

    //seccion segun sea
        // si es digito
        if (isdigit(e)) {
            //insertamos al final de la lista de salida
            char c = numero[i];
            concatenarCharACadena(c, cadena_salida);
        }
        //si es parentesis izquierdo 
        else if (e == '(') {
            insertar(&pila, numero[i]);
        }
        //si es parentesis derecho 
        else if (e == ')') {
            //mientras la pila no este vacia y cima no sea (
            while ((tamanioPila(pila) != 0) && (cima(&pila) != '(')) {
                ci = cima(&pila);
                eliminarPrimerNodo(&pila);
                //insertamos en la lista de salida
                concatenarCharACadena(ci, cadena_salida);
            }

            if (cima(&pila) == '(') {
                // extraemos y destuimos
                eliminarPrimerNodo(&pila);
                // puts("BORRE LA CIMA ");
            }
            else {
                puts("ERROR 2");
            }

        }
        // si es un operador
        else if (isOperator(e)) {
            while ((tamanioPila(pila) != 0) && verificarPresedencia(cima(&pila), numero[i])) { //<----------------------
                //extraemos elemento de la pila
                ci = cima(&pila);
                eliminarPrimerNodo(&pila);
                //insertamos al final de la lista de salida
                //char c = numero[i];
                concatenarCharACadena(ci, cadena_salida);
            }
            insertar(&pila, numero[i]);
        }
        i++;
    }

    //mientras la pila no este vacia
    while (tamanioPila(pila) != 0) {
        //extraemos elemento de la pila
        ci = cima(&pila);
        eliminarPrimerNodo(&pila);
        //temporal_2 = (int)ci;
        //insertamos al final de la lista de salida
        //char c = numero[i];
        concatenarCharACadena(ci, cadena_salida);
    }

    // limpiamos la pila para reutilizarla en la segunda parte
    limpiarPila(&pila);
    puts(cadena_salida);
    return 0;
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