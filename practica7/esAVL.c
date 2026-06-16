#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);

void insertaABB(arbol* a, int x) {
    arbol nuevo,padre,act;

    nuevo = (arbol) malloc(sizeof(NODO));
    nuevo->dato = x;
    nuevo->izq, nuevo->der = NULL;

    if (*a==NULL)
        *a = nuevo;
    else {
          act = *a;
          while (act !=NULL && act->dato!=x) {
            padre = act;
            if (act->dato > x)
                act = act->izq;
            else
                if (act->dato < x)
                 act = act->der;
          }
        if (act!=NULL && act->dato == x)
            free(nuevo);
        else
           if (x < padre->dato)
              padre->izq = nuevo;
           else
              padre->der = nuevo;
    }
}

void imprimirArbol(arbol raiz, int espacio) {
    if (raiz == NULL) return;

    // Aumentamos el espacio para el siguiente nivel
    espacio += 8;

    // Procesamos el subárbol derecho primero
    imprimirArbol(raiz->der, espacio);

    // Imprimimos el nodo actual con el espacio adecuado
    printf("\n");
    for (int i = 5; i < espacio; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->dato);

    // Procesamos el subárbol izquierdo
    imprimirArbol(raiz->izq, espacio);
}

// Wrapper para llamar con el espacio inicial
void mostrarArbol(arbol raiz) {
    imprimirArbol(raiz, 0);
}

int altura(arbol a){
    int izq,der;
    if (a!=NULL){
        izq = 1+altura(a->izq);
        der = 1+altura(a->der);

        if (izq>der)
            return izq;
        else
            return der;
    }
    else
        return 0;
}

int esAVL (arbol a) {
    int FE;
    if (a!=NULL){

        FE = altura(a->izq) - altura(a->der);

        if (FE>=-1 && FE<=1)
            return esAVL(a->izq) && esAVL(a->der);
        else
            return 0;
    }
    else
        return 1;
}

void muestraFE(arbol a) {
    int FE;
    if (a!=NULL) {
        FE = altura(a->izq) - altura(a->der);
        printf("NODO %d FE %d\n", a->dato, FE);
        muestraFE(a->izq);
        muestraFE(a->der);
    }
}

void main(){

 arbol a;
 /* carga arbol ejemplo. Ej 1 */
 insertaABB(&a,10);
 insertaABB(&a,9);
 insertaABB(&a,8);
 insertaABB(&a,11);
 insertaABB(&a,12);
 insertaABB(&a,13);

 mostrarArbol(a);

 if (esAVL(a))
    printf("ES AVL");
 muestraFE(a);
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
