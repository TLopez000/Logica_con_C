/*  Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la cola.

b. Utilizar la implementación dinámica.
c. Mantener la informacion en la cola.
*/

#include <stdio.h>
#include "TDADinColas.h"
#define CENTINELA 99999

void cargacola(TCola *C){
    TElementoC x;
    FILE *arch;

    iniciaC(C);
    arch=fopen("texto4.txt","r");
    if (arch!=NULL) {
        while(fscanf(arch,"%d",&x)==1)
            poneC(C,x);
        fclose(arch);
        poneC(C,CENTINELA); //centinela para poner al final de la cola
    }
}

void muestracola(TCola *C) {    //para no perder la informacion pongo un centinela al final de la cola, de forma que una vez que de la vuelta se detiene
    TElementoC x;
    sacaC(C,&x);
    while (x!=CENTINELA){
        printf("%d ", x);
        poneC(C,x);
        sacaC(C,&x);
    }
}

void main4(){
    TCola C;
    cargacola(&C);
    muestracola(&C);
}
