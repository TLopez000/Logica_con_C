/*  Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros:
a. cuente la cantidad de ceros que contiene.
b. obtenga el valor promedio (sin perder la información de la pila)
c. calcule los valores máximo y mínimo de la pila (sin perder la información de la pila)
d. quite todos los valores mayores al último. */

#include <stdio.h>
#include "TDADinPilas.h"

void carga(TPila *);
void reconstruye(TPila *,TPila *);
void cuentaceros(TPila *, int *);
void promedio(TPila *, float *);
void maxmin(TPila *,int *,int *);
void quita(TPila *);
void muestra(TPila *);

void main2(){
    TPila P;
    int max=0,min=999,cantceros=0;
    float prom;

    carga(&P);
    cuentaceros(&P,&cantceros);
    printf("Cantidad de ceros: %d\n", cantceros);

    promedio(&P,&prom);
    printf("Promedio: %f\n", prom);

    maxmin(&P,&max,&min);
    printf("Maximo: %d Minimo: %d\n", max, min);

    quita(&P);
    muestra(&P);
}

void carga(TPila *P){
    TelementoP x;
    FILE *arch;
    iniciaP(P);
    arch=fopen("texto6.txt","r");
    if (arch!=NULL){
        while(fscanf(arch,"%d",&x)==1)
         poneP(P,x);
    fclose(arch);
    }
}

void reconstruye(TPila *P, TPila *Aux){
    TelementoP x;
    while (!vaciaP(*Aux)){
        sacaP(Aux,&x);
        poneP(P,x);
    }
}

void cuentaceros(TPila *P, int *cantceros){
    TPila aux;
    TelementoP x;
    iniciaP(&aux);
    while (!vaciaP(*P)){
        sacaP(P,&x);
        if (x==0)
            *cantceros+=1;
        poneP(&aux,x);
    }
    reconstruye(P,&aux);
}

void promedio(TPila *P, float *prom){
    TelementoP x;
    TPila aux;
    iniciaP(&aux);
    float n=0,sum=0;
    while (!vaciaP(*P)){
        sacaP(P,&x);
        sum+=x;
        n+=1;
        poneP(&aux,x);
    }
    *prom=sum/n;
    reconstruye(P,&aux);
}

void maxmin(TPila *P,int *max,int *min){
    TelementoP x;
    TPila aux;
    iniciaP(&aux);
    while (!vaciaP(*P)) {
        sacaP(P,&x);
        *max=(x>*max)? x:*max;
        *min=(x<*min)? x:*min;
        poneP(&aux,x);
    }
    reconstruye(P,&aux);
}

void quita(TPila *P) {
    TelementoP ult,x;
    TPila aux;
    iniciaP(&aux);
    sacaP(P,&ult);
    poneP(&aux,ult);
    printf("ULTIMO: %d\n",ult);
    while (!vaciaP(*P)){
        sacaP(P,&x);
        if (x<ult)
            poneP(&aux,x);
    }
   reconstruye(P,&aux);
}

void muestra(TPila *P){
    TelementoP x;
    sacaP(P,&x);
    while (!vaciaP(*P)){
        printf("%d ", x);
        sacaP(P,&x);
    }
}
