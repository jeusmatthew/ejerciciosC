#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char leerExpresion(char* Expresion); // lee expresion
void errorSintaxis(char* Expresion); // error sintactico
int isOperator(char caracter); //detecta si es un operador
int isOperator2(char caracter); // detecta un operador pero sin '('
int isOperator3(char caracter); // detecta un operador pero sin '()'

int main() {
    char Expresion[30];

    puts("Ingrese una expresion aritmetica");
    leerExpresion(Expresion);
    errorSintaxis(Expresion);

    return 0;
}

char leerExpresion(char* Expresion) { //leemos expresion

    gets(Expresion);

    return *Expresion;
}

void errorSintaxis(char* Expresion) { // para evaluar errores
    int i = 0, balance = 0, numeroEspacios;

    numeroEspacios = strlen(Expresion); //variable para guardar la cantidad es elementos que tiene nuestra cadena.

    while (Expresion[i] != '\0') { // repetir el proceso hasta que encuentre el último caracter de control de la cadena

        if (isOperator2(Expresion[0])) { // determina si el primer término de la expresion es un operador (error)
            printf("Error: no se permite iniciar la expresion con el operador: '%c'.\n", Expresion[0]);
            exit(0);

        }
        else if (isOperator3(Expresion[numeroEspacios - 1])) {  // determina si el último término de la expresion es un operador (error)
            printf("Error: no se permite finalizar la expresion con el operador: '%c'.\n", Expresion[numeroEspacios - 1]);
            exit(0);

        }

        // El balance debe estar en 0 si hay la misma cantidad de parentesis izquierdos que de derechos
        if (Expresion[i] == '(') { //Entra al bloque de código cuando encuentra en parentesis izquierdo
            balance++; //aumentar el contador para contar parentesis izquierdos
            if (Expresion[i + 1] == ')') { // si entrentra un ')' despues de un '(' es error, no pueden haber parentesis vacios
                puts("Error: '()' no se permiten parentesis vacios.\n");
                exit(0);
            }

        }
        else if (Expresion[i] == ')') { // entra al bloque de código cuando encuentra un paréntesis derecho
            balance--; // disminuir el contador para los parentesis izquierdos

            if (Expresion[i + 1] == '(') { // si encuentra en parentesis izquierdo despues de uno derecho marca error, debe haber un operador entre un derecho y un izquierdo
                puts("Error: se esperaba un operador en ')(' para efectuar la operacion.\n");
                exit(0);
            }

            if (balance < 0) { // si el balance es menor a cero, significa que hay más parentesis derechos que izquierdos, al menos uno no tuvo apertura 
                printf("Error: cierre de parentesis sin correspondiente apertura.n");
                exit(0);
            }

        }

        if (Expresion[i] == '(') {
            if (isOperator3(Expresion[i + 1])) { //detecta el error si despues de una apertura de parentesis hay un operador 

                printf("Error: no se permite un operador despues de un parentesis izquierdo '(%c'.\n", Expresion[i + 1]);
                exit(0);
            }

        }
        else if (isdigit(Expresion[i])) {
            // revisa si hay dos digitos seguidos, es error ya que solo trabajamos unidades
            if (isdigit(Expresion[i + 1])) {
                printf("Error: No se permiten dos digitos seguidos '%c%c'.\n", Expresion[i], Expresion[i + 1]);
                exit(0);
            }
            else if (Expresion[i + 1] == '(') { // si despues de un digito hay un parentesis izquierdo, indica que se esperaba un operador
                printf("Error: se esperaba un producto en '%c(' para efectuar la operacion.\n", Expresion[i]);
                exit(0);
            }

        }
        else if (isOperator3(Expresion[i])) { //detecta si es un operador diferente de parentesis
            if (isOperator2(Expresion[i + 1])) {
                if (Expresion[i + 1] == ')') { // si es un operador y el siguiente es parentesis, indica que se esperaba un digito
                    printf("Error: se esperaba un digito en '%c)'.\n", Expresion[i]);
                    exit(0);
                }
                else {
                    printf("Error: No se permiten dos operadores seguidos '%c%c', se esperba un digito.\n", Expresion[i], Expresion[i + 1]);
                    exit(0);
                } // si el siguiente es un operador diferente de parentesis, indica que no pueden ir dos operadores seguidos y que se esperaba un digito
            }
        }
        i++; // contador para recorrer los subindices de la cadena.
    }
    if (balance > 0) { // si el balance es menor a cero, signifa que hay más parentesis izquierdos, y al menos uno no tiene cierre correspondiente.
        printf("Error: apertura de parentesis sin correspondiente cierre.\n");
        exit(0);
    }
    printf("La expresion es valida.\n"); //si no cumple con ninguna de las condiciones anteriores, la expresion es valida

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


