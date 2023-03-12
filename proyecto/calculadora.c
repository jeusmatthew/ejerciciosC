/*
Uniendo todo . . .
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STR_LEN 31

//funciones de nodos
typedef int Item;
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
char leerExpresion(char* Expresion); // lee expresion
int errorSintaxis(char* Expresion); // error sintactico
int errorLexico(char*); //Verifica si todos los caracteres son validos
int isOperator(char caracter); //detecta si es un operador
int isOperator2(char caracter); // detecta un operador pero sin '('
int isOperator3(char caracter); // detecta un operador pero sin '()'

void concatenarCharACadena(char, char*);
int verificarPresedencia(char, char);
void infijaAPosfija(char*);

int obtenerResultado(char*);
int realizarOperacion(int, int, char);

int main() {
    char Expresion[30];

    puts("Ingrese una expresion aritmetica");
    leerExpresion(Expresion);

    if (errorLexico(Expresion) || errorSintaxis(Expresion)) return 0;

    infijaAPosfija(Expresion);
    printf("El resultado de la expresion es: %d", obtenerResultado(Expresion));
    return 0;
}

char leerExpresion(char* Expresion) { //leemos expresion

    gets(Expresion);

    return *Expresion;
}

int errorSintaxis(char* Expresion) { // para evaluar errores
    int i = 0, balance = 0, numeroEspacios;

    numeroEspacios = strlen(Expresion); //variable para guardar la cantidad es elementos que tiene nuestra cadena.

    while (Expresion[i] != '\0') { // repetir el proceso hasta que encuentre el último caracter de control de la cadena

        if (isOperator2(Expresion[0])) { // determina si el primer término de la expresion es un operador (error)
            printf("Error: no se permite iniciar la expresion con el operador: '%c'.\n", Expresion[0]);
            return 1;

        }
        else if (isOperator3(Expresion[numeroEspacios - 1])) {  // determina si el último término de la expresion es un operador (error)
            printf("Error: no se permite finalizar la expresion con el operador: '%c'.\n", Expresion[numeroEspacios - 1]);
            return 1;
        }

        // El balance debe estar en 0 si hay la misma cantidad de parentesis izquierdos que de derechos
        if (Expresion[i] == '(') { //Entra al bloque de código cuando encuentra en parentesis izquierdo
            balance++; //aumentar el contador para contar parentesis izquierdos
            if (Expresion[i + 1] == ')') { // si entrentra un ')' despues de un '(' es error, no pueden haber parentesis vacios
                puts("Error: '()' no se permiten parentesis vacios.\n");
                return 1;
            }

        }
        else if (Expresion[i] == ')') { // entra al bloque de código cuando encuentra un paréntesis derecho
            balance--; // disminuir el contador para los parentesis izquierdos

            if (Expresion[i + 1] == '(') { // si encuentra en parentesis izquierdo despues de uno derecho marca error, debe haber un operador entre un derecho y un izquierdo
                puts("Error: se esperaba un operador en ')(' para efectuar la operacion.\n");
                return 1;
            }

            if (balance < 0) { // si el balance es menor a cero, significa que hay más parentesis derechos que izquierdos, al menos uno no tuvo apertura 
                printf("Error: cierre de parentesis sin correspondiente apertura.n");
                return 1;
            }

        }

        if (Expresion[i] == '(') {
            if (isOperator3(Expresion[i + 1])) { //detecta el error si despues de una apertura de parentesis hay un operador 

                printf("Error: no se permite un operador despues de un parentesis izquierdo '(%c'.\n", Expresion[i + 1]);
                return 1;
            }

        }
        else if (isdigit(Expresion[i])) {
            // revisa si hay dos digitos seguidos, es error ya que solo trabajamos unidades
            if (isdigit(Expresion[i + 1])) {
                printf("Error: No se permiten dos digitos seguidos '%c%c'.\n", Expresion[i], Expresion[i + 1]);
                return 1;
            }
            else if (Expresion[i + 1] == '(') { // si despues de un digito hay un parentesis izquierdo, indica que se esperaba un operador
                printf("Error: se esperaba un producto en '%c(' para efectuar la operacion.\n", Expresion[i]);
                return 1;
            }

        }
        else if (isOperator3(Expresion[i])) { //detecta si es un operador diferente de parentesis
            if (isOperator2(Expresion[i + 1])) {
                if (Expresion[i + 1] == ')') { // si es un operador y el siguiente es parentesis, indica que se esperaba un digito
                    printf("Error: se esperaba un digito en '%c)'.\n", Expresion[i]);
                    return 1;
                }
                else {
                    printf("Error: No se permiten dos operadores seguidos '%c%c', se esperba un digito.\n", Expresion[i], Expresion[i + 1]);
                    return 1;
                } // si el siguiente es un operador diferente de parentesis, indica que no pueden ir dos operadores seguidos y que se esperaba un digito
            }
        }
        i++; // contador para recorrer los subindices de la cadena.
    }
    if (balance > 0) { // si el balance es menor a cero, signifa que hay más parentesis izquierdos, y al menos uno no tiene cierre correspondiente.
        printf("Error: apertura de parentesis sin correspondiente cierre.\n");
        return 1;
    }
    // printf("La expresion es valida.\n");
    return 0; //si no cumple con ninguna de las condiciones anteriores, la expresion es valida
}

int isOperator(char caracter) {
    return (caracter >= '(' && caracter <= '+') || caracter == '-' || caracter == '/' || caracter == '^';
}

int isOperator2(char caracter) {
    return (caracter >= ')' && caracter <= '+') || caracter == '-' || caracter == '/' || caracter == '^';
}

int isOperator3(char caracter) {
    return caracter == '*' || caracter == '+' || caracter == '-' || caracter == '/' || caracter == '^';
}

/*
0   Sin errores
1   Error
*/
int errorLexico(char* cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!isdigit(cadena[i]) && !isOperator(cadena[i])) {
            printf("Error lexico en el caracter: %c", cadena[i]);
            return 1;
        }
    }
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

int obtenerResultado(char* expresion) {

    Pila pila;
    Item ci;

    char caracterEvaluado;
    int numero = 0, operando1 = 0, operando2 = 0, resultado = 0;

    for (int i = 0; expresion[i] != '\0'; i++) {
        caracterEvaluado = expresion[i];
        // printf("Caracter a evaluar %c\n", caracterEvaluado);
        if (isdigit(caracterEvaluado)) {
            numero = atoi(&caracterEvaluado);
            insertar(&pila, numero);
            ci = cima(&pila);
            // printf("\t%d es la cima ahora\n", ci);
        }
        else {

            ci = cima(&pila);
            operando1 = (int)ci;
            eliminarPrimerNodo(&pila);
            // puts("Cima 1 borrada");

            ci = cima(&pila);
            operando2 = (int)ci;
            eliminarPrimerNodo(&pila);
            // puts("Cima 2 borrada");

            resultado = realizarOperacion(operando1, operando2, caracterEvaluado);

            insertar(&pila, resultado);
        }

    }
    ci = cima(&pila);
    return ci;
}

int realizarOperacion(int op1, int op2, char op) {
    switch (op) {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);

    default:
        puts("World error!");
        break;
    }
}