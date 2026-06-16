/* Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente. */

#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void generavec(arbol a, int *dimv, int v[]){
    if (a!=NULL){
        generavec(a->der, dimv, v);
        v[++(*dimv)] = a->dato;
        generavec(a->izq, dimv, v);
    }
}

void addnodo(arbol* a, TElememtoA e);

int main(){
 arbol a=NULL;
 int i,v[100],dimv=-1;

 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 10);
 addnodo(&a->izq, 8);
 addnodo(&a->izq->izq, 3);
 addnodo(&a->izq->der, 9);

 addnodo(&a->der, 12);
 addnodo(&a->der->izq, 11);

 generavec(a,&dimv,v);
 for(i=0; i<=dimv; i++)
    printf("%d ", v[i]);

 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
