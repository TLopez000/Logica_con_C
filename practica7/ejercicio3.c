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

int suma(arbol a){
  if (a!=NULL){
    if (a->dato % 3 == 0)
        return a->dato + suma(a->izq)+suma(a->der);
    else
        return suma(a->izq)+suma(a->der);
  }
  else
    return 0; //las hojas null suman 0
}

int canthojas(arbol a){
    if (a!=NULL)
        if (a->izq==NULL && a->der==NULL)
          return 1;
        else
            return canthojas(a->izq)+canthojas(a->der);
    else
        return 0;
}

int buscaX(arbol a, int x) {
    if (a!=NULL)
        if (a->dato == x)
          return 1;
        else
            return buscaX(a->izq,x) || buscaX(a->der,x);
    else
        return 0;
}

int main(){
 arbol a;
 int x;
 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 5);
 addnodo(&a->izq, 8);
 addnodo(&a->izq->izq, 3);
 addnodo(&a->izq->der, 6);

 addnodo(&a->der, 4);
 addnodo(&a->der->izq, 1);
 addnodo(&a->der->izq->der, 2);

 printf("%d cantidad de hojas, %d suma multiplos\n", canthojas(a), suma(a));
 if (buscaX(a,4))
    printf("esta en el arbol");

 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}



