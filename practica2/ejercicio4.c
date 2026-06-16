/*Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga
N elementos (N es ingresado por teclado). Ingresar sus elementos y mostrar aquellos que sean
positivos utilizando aritmética de punteros. Al finalizar, liberar la memoria solicitada en tiempo
de ejecución. */

#include <stdio.h>
#include <stdlib.h>

void leevec(float *[],int n);
void muestrapos(float [],int n);

void main(){
    float *vec;
    int n;
    printf("Ingrese la cantidad de elementos N: ");
    scanf("%d", &n);
    leevec(&vec,n);
    muestrapos(vec,n);
    free(vec);
}

void leevec(float **p,int n){
    int i;
    *p=(float *) malloc(sizeof(float)*n);
    for(i=0;i<n;i++){
        printf("Ingrese el elemento: %d\n", i);
        scanf("%f", *p+i);
    }
}

void muestrapos(float vec[],int n){
    int i;
    for(i=0;i<n;i++)
        if (vec[i]>0)
        printf("%3.2f ", *(vec+i));
}
