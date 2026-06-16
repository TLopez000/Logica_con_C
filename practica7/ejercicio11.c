
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
//asi es sobre un arbol sin ordenar

int minimo(arbol a){
    int izq,der,min;

    if (a!=NULL){
        izq = minimo(a->izq);
        der = minimo(a->der);

        min = a->dato;

        if (izq < min)
            min = izq;
        if (der < min)
            min = der;

        return min;
    }
    else
        return 99999; //valor imposible
}

//asi sobre un ABB

int minimoABB(arbol a){
    if (a!=NULL)
        if (a->izq == NULL) //estoy en el nodo mas a la izquierda posible
          return a->dato;
        else
          return minimoABB(a->izq);
}

//no analizo cuando a==NULL porque retorno el valor del nodo cuando ya no hay izquierda

int main(){
 arbol a=NULL;
 int i,v[100],dimv=-1;

 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 10);
 addnodo(&a->izq, 8);
 addnodo(&a->izq->izq, 3);
 addnodo(&a->izq->izq->izq, 9);
 addnodo(&a->izq->der, 6);
addnodo(&a->izq->der->der, -5);

 addnodo(&a->der, 12);
 addnodo(&a->der->izq, 11);
 addnodo(&a->der->izq->izq, 11);

 printf("Minimo del arbol: %d", minimo(a));
 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}



