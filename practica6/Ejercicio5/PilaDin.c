#include "TDAPilaDin.h"

void iniciaP(Tpila *P){
    *P=NULL;
}

void poneP(Tpila *P, TelementoP x){
    Tpila aux;
    aux=(Tpila) malloc(sizeof(nodop));
    aux->dato=x;
    aux->sig=*P;
    *P=aux;
}

void sacaP(Tpila *P, TelementoP *x){
    Tpila aux;
    if (*P){
        aux=*P;
       *x=aux->dato;
       *P=*P->sig;
       free(aux);
    }
}

int vaciaP(Tpila P){
    return P==NULL;
}

TelementoP consultaP(Tpila P){
    if (P)
        return P->dato;
}
