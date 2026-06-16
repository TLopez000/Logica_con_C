/* 2. Recodificar en el lenguaje C los siguientes ejercicios de Programación I desarrollados en Pascal:
a) Sea V un arreglo de enteros, se pide:
I.
Calcular e informar la suma de sus elementos.
Mostrar sus elementos.
Mostrar sus elementos en orden inverso.*/
#include <stdio.h>

int suma(int[],int);
void muestra(int[],int);
void muestrainverso(int[],int);

void main(){
    int vec[6]={1,2,3,4,5,6};
    printf("la suma da %d\n", suma(vec,6-1));
    muestra(vec,6-1);
    printf("\n");
    muestrainverso(vec,6-1);
}

int suma(int vec[],int n) {
    if (n==0)
        return vec[n];
    else
        return vec[n]+suma(vec,n-1);
}

void muestra(int vec[],int n) {  //lo muestra desde el ultimo al primero ya que arranca desde n-1
    if (n>-1) {
        printf("%d ", vec[n]);
        muestra(vec,n-1);
    }
}

void muestrainverso(int vec[],int n) { //lo muestra desde el primero al ultimo
    if (n>-1) {
        muestrainverso(vec,n-1);
        printf("%d ", vec[n]);
    }
}
