 /* Transformar, mediante un subprograma recursivo, una pila de manera que tenga los mismos
datos pero cambiados de signo.
*/

#include <stdio.h>
#include "TDAEstPilas.h"

void cargapila(TPila *);
void transforma(TPila *);
void muestra(TPila *);

void main(){
    TPila P;
    cargapila(&P);
    transforma(&P);
    muestra(&P);
}

void cargapila(TPila *P){
    TelementoP x;
    iniciaP(P);
    scanf("%d", &x);
    while (x!=0 && !llenaP(*P)) {
         poneP(P,x);
         scanf("%d",&x);
    }
}

void transforma(TPila *P){
    TelementoP x;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        transforma(P);
        poneP(P,-x);
    }
}

void muestra(TPila *P){
        TelementoP x;
    if (!vaciaP(*P)){
        sacaP(P,&x);
        printf("%d ",x);
        muestra(P);
        poneP(P,x);
    }
}
