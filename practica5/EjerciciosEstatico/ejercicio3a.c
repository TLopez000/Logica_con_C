 /*Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
a. en orden inverso, comenzando por el último votante. */

#include <stdio.h>
#include "TDAEstPilas.h"

void main3() {
    int i,N=2;
    TelementoP x;
    TPila P;
    //inicio y cargo la pila
    iniciaP(&P);
    scanf("%d", &x);
    while (x!=0 && !llenaP(P)) {
        poneP(&P,x);
        scanf("%d",&x);
    }

    //muestro la pila
    for(i=0;i<N-1 && !vaciaP(P);i++){
        sacaP(&P,&x);
        printf("%d ", x);
    }

}
