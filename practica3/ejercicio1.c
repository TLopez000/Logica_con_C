/*  Desarrollar funciones (algunas pueden ser void) para:
a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int) */

#include <stdio.h>

int producto(int, int);
void divide(int,int,int*,int*);
int maxvec(int [],int);
void maxvector(int [],int, int*);

void main() {
    int cociente,resto,max,a=20,b=4;
    int vec[8]={1,8,5,20,6,19,21,2};
    printf("producto entre a y b: %d\n", producto(a,b));
    divide(a,b,&cociente,&resto);
    printf("cociente entre a y b: %d  resto: %d\n", cociente,resto);

    printf("FUNCION INT el maximo del vector es %d\n", maxvec(vec,8-1));

    maxvector(vec,8-1,&max);
    printf("FUNCION VOID el maximo del vector es %d", max);
}

int producto(int a, int b) {
    if (b==1)
        return a;
    else
        return producto(a,b-1)+a;
}

void divide(int a,int b,int *cociente, int *resto) {
    if (a<b){
        *cociente=0;
        *resto=a;
    }
    else {
        divide(a-b,b,cociente,resto);
        (*cociente)++;
    }
}

int maxvec(int vec[], int n) {
    int aux;
    if (n==0)
        return vec[n];
    else {
        aux=maxvec(vec,n-1);
        if (vec[n]>aux)
            return vec[n];
        else
            return aux;
    }
}

void maxvector(int vec[], int n, int *max) {
    if (n==0)
        *max=vec[n];
    else {
        maxvector(vec,n-1,max);
        if (*max<vec[n])
            *max=vec[n];
    }
}

