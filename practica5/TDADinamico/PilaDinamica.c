#include <stdlib.h>
#include <stdio.h>
#include "TDADinPilas.h"

void iniciaP (TPila *P){
    *P=NULL;
}

int vaciaP (TPila P){
    return P==NULL;  //si el puntero esta vacio devuelve 1;
}

TelementoP consultaP(TPila P){
    if (P!=NULL)
        return P->dato;
}

void poneP (TPila *P,TelementoP X){
    TPila N;
    N=(TPila) malloc(sizeof(nodop));  //N es un puntero auxiliar a pila
    N->dato=X;
    N->sig=*P;                       //Engancho N al elemento que estaba apuntando P (Si es el primero, N->sig sera NULL)
    *P=N;                            //Ahora P apuntara al ultimo elemento ingresado (N)
}

void sacaP (TPila *P, TelementoP *X){
    TPila N;
    if (*P) {    //si la pila no esta vacia , P!=null
       N=*P;                    //al puntero auxiliar N le asigno la ultima posicion de la Pila
       *X=(*P)->dato;           //devuelvo el ultimo dato en X
       *P=(*P)->sig;            //P apuntara al dato anteultimo, dejando N apuntando al ultimo
       free(N);                 //se elimina N;
    }
}
