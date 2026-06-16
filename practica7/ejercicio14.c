//FUNCION QUE COMPRUEBE QUE UN ARBOL ES ABB

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

int cumple(arbol a, int topeinf, int topesup) {
    if (a!=NULL){
        if (a->dato > topeinf && a->dato < topesup)
            return cumple(a->izq, 0, a->dato) && cumple(a->der, a->dato, topesup);
        else
            return 0;
    }
    return 1;
}

void main(){

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

 if (cumple(a,0,9999))
    printf("es ABB");
 else
    printf("no es abb");

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
