
#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e){
     *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

/* 20. Dado un árbol binario proveniente de la conversión de un árbol general:
a) hallar la cantidad de nodos que habia en niveles impares.
b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
c) obtener la altura del árbol original
d) determinar el grado del árbol original.*/

//INCISO A

int cant_nodos(arbol a, int nivel){
    if (a!=NULL){
        if (nivel % 2 == 0)
            return 1+cant_nodos(a->der, nivel)+cant_nodos(a->izq,nivel+1);
        else
            return cant_nodos(a->der, nivel)+cant_nodos(a->izq,nivel+1);
    }
    else
        return 0;
}

//INCISO B

int grado_nodo(arbol a){
    int i=0;
    while (a!=NULL){
        i++;
        a=a->der;
    }
    return i;
}

float suma_grado_k(arbol a, int k){
    int grado;
    if (a!=NULL){
        grado = grado_nodo(a->izq);
        if (grado==k)
            return a->dato+suma_grado_k(a->izq,k)+suma_grado_k(a->der,k);
        else
            return suma_grado_k(a->izq,k)+suma_grado_k(a->der,k);
    }
    else
        return 0;
}

float cant_nodos_gradok(arbol a, int k){
   int grado;
    if (a!=NULL){
        grado = grado_nodo(a->izq);
        if (grado==k)
            return 1+cant_nodos_gradok(a->izq,k)+cant_nodos_gradok(a->der,k);
        else
            return cant_nodos_gradok(a->izq,k)+cant_nodos_gradok(a->der,k);
    }
    else
        return 0;
}

//INCISO C

int altura_arbgral(arbol a){
    int izq,der;
    if (a==NULL)
        return 0;
    else {
        izq = 1+altura_arbgral(a->izq);
        der = altura_arbgral(a->der);

        if (izq>der)
            return izq;
        else
            return der;
    }
}

//INCISO D

int grado_arbgral(arbol a){
    int grado_max,izq, der;
    if (a==NULL)
        return 0;
    else{
        izq = grado_arbgral(a->izq);
        der = grado_arbgral(a->der);

        grado_max = grado_nodo(a->izq);

        if (izq>grado_max)
            grado_max = izq;
        if (der>grado_max)
            grado_max = der;

        return grado_max;
    }
}

void main(){
 arbol a;

 //arbol B del ejercicio 18
 addnodo(&a, 10);
 addnodo(&a->izq, 5);
 addnodo(&a->izq->der, 30);
 addnodo(&a->izq->der->izq, 2);
 addnodo(&a->izq->der->izq->der, 5);
 addnodo(&a->izq->der->izq->der->der, 10);
 addnodo(&a->izq->der->izq->der->der->der, 15);
 addnodo(&a->izq->der->izq->der->izq, 6);
 addnodo(&a->izq->der->izq->der->izq->der, 20);
 addnodo(&a->izq->der->izq->der->izq->der->der, 3);

 printf("cantidad de nodos en niveles impares: %d\n", cant_nodos(a,1));
 printf("promedio de claves de grado k: %.2f\n", suma_grado_k(a,0)/cant_nodos_gradok(a,0));
 printf("altura del arbol gral: %d\n", altura_arbgral(a)-1);
 printf("Grado maximo del arbol gral: %d\n", grado_arbgral(a));

}
