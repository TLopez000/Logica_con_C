/*Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes

b. en el orden que sufragaron. */

#include "TDAEstColas.h"
#include <stdio.h>

void main3b(){
    int i,N=2;
    TCola C;
    TelementoC x;

    //inicio la cola y la cargo
    iniciaC(&C);
    scanf("%d", &x);
    while (x!=0 && !llenaC(C)) {
        poneC(&C,x);
        scanf("%d",&x);
    }

    //muestro la cola
    for(i=0;i<N;i++){
        sacaC(&C,&x);
        printf("%d ", x);
    }
}

