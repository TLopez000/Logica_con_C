 /* Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
a. en orden inverso, comenzan
*/

#include <stdio.h>
#include "TDAEstPilas.h"

void cargapilarec(TPila *);
void muestrapilarec(TPila *,int );

void main(){
    TPila P;
    int n=2;
    iniciaP(&P);
    cargapilarec(&P);
    muestrapilarec(&P,n-1);
}

void cargapilarec(TPila *P){
    TelementoP x;
    FILE *arch;

    arch = fopen("texto3.txt","r");
    if (arch!=NULL)
        while (fscanf(arch,"%d",&x)==1)
            poneP(P,x);
    fclose(arch);
}

void muestrapilarec(TPila *P, int n){    //a la salida de la recursividad vuelvo a poner los datos de la pila
    TelementoP x;
    if (!vaciaP(*P) && n>=0) {
        sacaP(P,&x);
        printf("%d\n",x);
        muestrapilarec(P,n-1);
        poneP(P,x);             //guardo el elemento en el orden original
    }
}


