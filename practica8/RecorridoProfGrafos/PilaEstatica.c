
#include "TDAEstPilas.h"

void iniciaP (TPila *P) {
    (*P).tope=-1;
}

int vaciaP (TPila P){
    return P.tope==-1;
}

TelementoP consultaP (TPila P){
    if (P.tope!=-1)
        return P.datos[P.tope];
}

void poneP (TPila *P,TelementoP X){
    if ((*P).tope!=MAX-1)
        (*P).datos[++(*P).tope]=X;
}

void sacaP (TPila *P, TelementoP *X){
    if ((*P).tope!=-1)
        *X=(*P).datos[((*P).tope)--];
}

int llenaP (TPila P){
    return P.tope==MAX-1;
}
