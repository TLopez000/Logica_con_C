#include "TDADinColas.h"
#include <stdlib.h>

void iniciaC(TCola *C){
    (*C).pri=NULL;
    (*C).ult=NULL;
}

void poneC(TCola *C,TElementoC x){
    nodo *aux;
    aux=(nodo *) malloc(sizeof(nodo));
    aux->dato=x;
    aux->sig=NULL;
      if ((*C).pri==NULL)
        (*C).pri=aux;
      else
        (*C).ult->sig=aux;
    (*C).ult=aux;
}

void sacaC(TCola *C,TElementoC *x){
    nodo *aux;
    if ((*C).pri!=NULL) {
        aux=(*C).pri;
        *x=aux->dato;
           if ((*C).pri==(*C).ult)
            iniciaC(C);
           else
            (*C).pri=aux->sig; //(*C).pri=(*C).pri->sig;
        free(aux);
    }
}

int vaciaC(TCola C){
    return C.pri==NULL;
}

TElementoC consultaC(TCola C){
    if (C.pri!=NULL)
        return C.pri->dato;
}
