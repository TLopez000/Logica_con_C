 /* Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
a. Utilizar la implementación estática.
b. Utilizar la implementación dinámica.
c. Mantener la información en la pila. */

#include <stdio.h>
#include "TDAEstPilas.h"

void cargapila(TPila *);
void muestrapila(TPila *);

void main2(){
    TPila P;
    iniciaP(&P);
    cargapila(&P);
    muestrapila(&P);
}

void cargapila(TPila *P){
    TelementoP x;
    FILE *arch;

    arch = fopen("texto1.txt","r");
    if (arch!=NULL)
        while (fscanf(arch,"%c",&x)==1)
            poneP(P,x);
    fclose(arch);
}

void muestrapila(TPila *P){    //con la pila aux puedo mantener la informacion de la pila
    TelementoP Aux;
    TPila Paux;
    iniciaP(&Paux);
    while (!vaciaP(*P)) {
       sacaP(P,&Aux);
       poneP(&Paux,Aux);
       printf("%c", Aux);
    }
    while (!vaciaP(Paux)){
        sacaP(&Paux,&Aux);
        poneP(P,Aux);
    }
}

