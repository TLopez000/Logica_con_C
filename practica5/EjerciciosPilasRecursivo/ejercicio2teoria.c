#include <stdio.h>
#include "TDAEstPilas.h"

void ordenada(TPila *P,int *cumple){
    TelementoP x;
    if (!vaciaP(*P) && *cumple) {
        sacaP(P,&x);
        if(!vaciaP(*P))
           if (x>consultaP(*P))
              *cumple=0;
        ordenada(P,cumple);
        poneP(P,x);
    }
}

void main2t(){
    TPila P;
    int cumple=1;
    iniciaP(&P);
//    cargaP(&P);
    ordenada(&P,&cumple);
    if (cumple)
        printf("esta ordenada");
}
