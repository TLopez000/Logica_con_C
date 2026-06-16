#include <stdio.h>
#include "TDADinPilas.h"

void cargaPila(TPila *);
void muestraPila(TPila *);

void main2 (){
    TPila P;
    iniciaP(&P);
    cargaPila(&P);
    muestraPila(&P);
}

void cargaPila(TPila *P) {
    TelementoP aux;
    FILE *arch;

    arch=fopen("texto1.txt","r");
    if (arch!=NULL)
        while (fscanf(arch,"%c",&aux)==1)
             poneP(P,aux);
    fclose(arch);
}

void muestraPila(TPila *P){
    TelementoP aux;
    while (!vaciaP(*P)){
        sacaP(P,&aux);
        printf("%c", aux);
    }
}
