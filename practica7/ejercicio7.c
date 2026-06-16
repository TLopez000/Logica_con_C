/* Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato.  */

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

int sumanivelx(arbol a, int nivel, int x) {
    if (a!=NULL)
        if (nivel==x && (a->izq!=NULL && a->der == NULL) || (a->izq == NULL && a->der != NULL))
            return a->dato;
        else
            return sumanivelx(a->izq, nivel + 1, x) + sumanivelx(a->der, nivel + 1, x);
   else
    return 0;
}


int main(){
 arbol a=NULL;
 int i,v[100],dimv=-1;

 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 10);
 addnodo(&a->izq, 8);
 addnodo(&a->izq->izq, 3);
 addnodo(&a->izq->izq->izq, 2);
 addnodo(&a->izq->der, 6);
addnodo(&a->izq->der->der, 3);

 addnodo(&a->der, 12);
 addnodo(&a->der->izq, 11);
 addnodo(&a->der->izq->izq, 11);

 printf("suma del nivel 3 de nodos de 1 grado: %d", sumanivelx(a,1,3));
 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}


