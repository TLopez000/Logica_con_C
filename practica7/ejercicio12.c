/* . Determinar cuántos elementos de un ABB son mayores que A y menores que B. A y B son
parámetros de entrada.*/

#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void mayoresAB(arbol arb, int A, int B, int *cant){
    if (arb!=NULL) {
        if (arb->dato > A && arb->dato < B) {

            mayoresAB(arb->izq,A,B,cant);
            printf("%d\n", arb->dato);      //recorrido inorden para que lo escriba ordenado
            *cant+=1;
            mayoresAB(arb->der,A,B,cant);

        }
        else
            if (arb->dato <= A) //clave menor al rango AB
              mayoresAB(arb->der,A,B,cant);
            else
               if (arb->dato >= B) //clave mayor al rango AB
                  mayoresAB(arb->izq,A,B,cant);
    }
}

////// una funcion que solo cuente la cantidad de elementos que estan en AB

int entreAB(arbol a, int A, int B) {
    if (a!=NULL) {
        if (a->dato > A && a->dato < B)
            return 1 + entreAB(a->izq,A,B) + entreAB(a->der,A,B);
        else
            if (a->dato <= A)
              return entreAB(a->der,A,B);
              else
                if (a->dato >= B )
                  return entreAB(a->izq,A,B);
    }
    else
        return 0;
}

void addnodo(arbol* a, TElememtoA e);

int profgral(arbol a) {
    int izq,der;

    if (a!=NULL){
        izq = 1+profgral(a->izq);
        der = profgral(a->der);

        if (izq>der)
            return izq;
        else
            return der;
    }
    else
        return 0;

}

int main(){
 arbol a;
 int x,cant=0;
 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 10);
 addnodo(&a->izq, 8);
 addnodo(&a->izq->izq, 3);
 addnodo(&a->izq->izq->izq, 2);
 addnodo(&a->izq->der, 9);

 addnodo(&a->der, 15);
 addnodo(&a->der->izq, 11);
 addnodo(&a->der->izq->izq, 13);
 addnodo(&a->der->izq->izq->izq, 12);
 addnodo(&a->der->izq->izq->izq->izq, 11);

 mayoresAB(a,3,12,&cant);
 printf("%d elementos en el rango AB\n", cant);

 printf("Solo la cantidad con funcion int: %d\n", entreAB(a,3,12));

 printf("prof de un general transformado: %d", profgral(a));

 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

