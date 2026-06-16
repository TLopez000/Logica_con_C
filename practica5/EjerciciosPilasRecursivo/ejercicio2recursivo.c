 /* Ingresar en una pila los caracteres almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la pila.
*/

#include <stdio.h>
#include "TDAEstPilas.h"

void cargapilarec(TPila *);
void muestrapilarec(TPila *);

void main(){
    TPila P;
    iniciaP(&P);
    cargapilarec(&P);
    muestrapilarec(&P);
}

void cargapilarec(TPila *P){
    TelementoP x;
    FILE *arch;

    arch = fopen("texto1.txt","r");
    if (arch!=NULL)
        while (fscanf(arch," %c",&x)==1)
            poneP(P,x);
    fclose(arch);
}

void muestrapilarec(TPila *P){    //a la salida de la recursividad vuelvo a poner los datos de la pila
    TelementoP x;
    if (!vaciaP(*P)) {
        sacaP(P,&x);
        printf("%c ",x);
        muestrapilarec(P);
        printf("\n");            //voy mostrando como la pila queda igual a la original
        printf("%c ",x);
        poneP(P,x);             //guardo el elemento en el orden original
    }
}
