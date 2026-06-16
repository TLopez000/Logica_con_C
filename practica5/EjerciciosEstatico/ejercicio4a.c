/*Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la cola.
a. Utilizar la implementación estática no circular. */

#include "TDAEstColas.h"
#include <stdio.h>

void carga(TCola *C) {
    TelementoC x;
    FILE *arch;

    iniciaC(C);
    arch=fopen("texto4.txt","r");
    if (arch!=NULL) {
       while (fscanf(arch,"%d",&x)==1)
        poneC(C,x);
      fclose(arch);
    }
}

void muestra(TCola *C) {
    TelementoC aux;
    while (!vaciaC(*C)){
        sacaC(C,&aux);
        printf("%d\n", aux);
    }
}

void main4(){
    TCola C;
    carga(&C);
    muestra(&C);
}


