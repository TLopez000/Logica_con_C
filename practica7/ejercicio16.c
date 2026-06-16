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

void main(){

 arbol a;
 /* carga arbol ejemplo. Ej 1 */
 insertaABB(&a,10);
 insertaABB(&a,8);
 insertaABB(&a,3);
 insertaABB(&a,9);
 insertaABB(&a,2);
 insertaABB(&a,16);
 insertaABB(&a,12);
 insertaABB(&a,4);
 insertaABB(&a,5);

 mostrarArbol(a);

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
