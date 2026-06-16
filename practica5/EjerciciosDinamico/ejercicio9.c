/* Desarrollar un programa que sume dos números enteros positivos, permitiendo una cantidad
de dígitos mayor a la que soportan los tipos numéricos. Los números pueden tener diferente
magnitud y deben ser ingresados comenzando desde su dígito más significativo (en orden).
Utilizar pilas de caracteres. */

//IDEA GRAL - Pila 1 para n1 , Pila 2 para n2, Pila 3 para resultado. Sumo el ultimo nro de cada pila y divido por 10, para calcular el arrastre
// conversion char a int : 'nro'-'0' // conversion int a char: nro+'0'


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TDADinPilas.h"

void cargan1(TPila *P1){
    TelementoP n;
    printf("cargando N1\n");
    scanf(" %c", &n);
    while(n!='.') {
        poneP(P1,n);
        scanf(" %c", &n);
    }
}

void cargan2(TPila *P2){
    TelementoP n;
    printf("cargando N2\n");
    scanf(" %c", &n);
    while(n!='.') {
        poneP(P2,n);
        scanf(" %c", &n);
    }
}

int main(){
    TPila P1,P2,P3;
    TelementoP x1,x2,x3;
    int n1,n2,res,arrastre=0;

    iniciaP(&P1);
    iniciaP(&P2);
    cargan1(&P1);
    cargan2(&P2);

    while (!vaciaP(P1) || !vaciaP(P2)) {          //si no esta vacia saco y sumo, si alguna esta sumo 0
        if (!vaciaP(P1)){
           sacaP(&P1,&x1);
           n1=x1-'0';
           }
        else
            n1=0;

        if (!vaciaP(P2)){
           sacaP(&P2,&x2);
           n2=x2-'0';
           }
        else
            n2=0;

       res=(n1+n2+arrastre)%10;
       arrastre=(n1+n2+arrastre)/10;

       x3=res+'0';
       poneP(&P3,x3);

    }

    if (arrastre>0) {         //considera el ultimo arrastre y lo inserta
        x3=arrastre+'0';
        poneP(&P3,x3);
    }

    while (!vaciaP(P3)){
        sacaP(&P3,&x3);
        printf("%d",x3-'0');
    }
}
