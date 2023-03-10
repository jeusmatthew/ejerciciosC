/*
Estructuras de datos en C: implementación de pila de enteros
Recuerda que el último en entrar es el primero en salir
LIFO: https://es.wikipedia.org/wiki/Last_in,_first_out
Basado en las operaciones que dice la Wikipedia:
https://es.wikipedia.org/wiki/Pila_(inform%C3%A1tica)#Operaciones

@author parzibyte
Visita: parzibyte.me
*/
#include <stdio.h>   // printf
#include <stdlib.h>  // malloc y free
#include <stdbool.h> // Booleanos

// Un nodo tiene un dato, el cual es el número. Y otro nodo al que apunta
struct nodo {
    int numero;
    struct nodo* siguiente;
};

// Prototipos de funciones
void agregar(int numero);  // push
void eliminarUltimo(void); // pop
void imprimir(void);
int tamanio(void); // El tamaño de la pila
bool vacia(void);  // Indica si la pila está vacía
int ultimo(void);  // El último elemento. Devuelve 0 si no hay elementos

// Todo comienza con el nodo superior
struct nodo* superior = NULL;

int main() {
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
        //no eliminaremos ningun termino simplemente recorreres el string
        //int var = numero[i] - '0'; solo como nota


    //seccion segun sea
        // si es digito
        if (isdigit(numero[i])) {
            //insertamos al final de la lista de salida
            char c = numero[i];
            concatenarCharACadena(c, cadena_salida);
        }
        //si es parentesis izquierdo 
        else if (numero[i] == '(') {
            insertar(&pila, numero[i]);
        }
        //si es parentesis derecho 
        else if (numero[i] == ')') {
            //mientras la pila no este vacia y cima no sea (
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
        else if (isOperator(numero[i])) {
            while ((tamanioPila(pila) != 0) && verificarPresedencia(cima(&pila), numero[i])) { //<----------------------
                //extraemos elemento de la pila
                ci = cima(&pila);
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

int tamanio(void) {
    int contador = 0;
    if (superior == NULL)
        return contador;
    struct nodo* temporal = superior;
    while (temporal != NULL) {
        contador++;
        temporal = temporal->siguiente;
    }
    return contador;
}

bool vacia(void) { return superior == NULL; }

int ultimo() {
    if (superior == NULL)
        return -1;
    return superior->numero;
}

// Operación push
void agregar(int numero) {
    printf("Agregando %d\n", numero);
    // El que se agregará; reservamos memoria
    struct nodo* nuevoNodo = malloc(sizeof(struct nodo));
    // Le ponemos el dato
    nuevoNodo->numero = numero;
    // Y ahora el nuevo nodo es el superior, y su siguiente
    // es el que antes era superior
    nuevoNodo->siguiente = superior;
    superior = nuevoNodo;
}

void imprimir(void) {
    printf("Imprimiendo...\n");
    struct nodo* temporal = superior;
    while (temporal != NULL) {
        printf("%d\n", temporal->numero);
        temporal = temporal->siguiente;
    }
}

// Operación pop, eliminar el de hasta arriba
void eliminarUltimo(void) {
    printf("Eliminando el último\n");
    if (superior != NULL) {
        // Para liberar la memoria más tarde debemos
        // tener la referencia al que vamos a eliminar
        struct nodo* temporal = superior;
        // Ahora superior es a lo que apuntaba su siguiente
        superior = superior->siguiente;

        // Liberar memoria que estaba ocupando el que eliminamos
        free(temporal);
    }
}