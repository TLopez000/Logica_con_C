#include <stdio.h>

float potencia(float n, int pot) {
    if (pot==0)
        return n*1;
    else {
      if (pot>0)
        return n*potencia(n,pot-1);
      else
        return 1/potencia(a,-pot);
    }
}

void factorial(int n, int *res) {
    if (n==1)
        *res==1;
    else {
        *res*=n;
        factorial(n-1,&res);
    }
}

// CON VECTORES

int sumavector(int A[], int n) {   //con recorrido del final hacia el principio
    if (n==0)
        return A[n];
    else
        return A[n]+sumavector(A[],n-1);
}

void sumavector(int A[], int n, int *res) { //devuelve la suma como parametro
    if (n==0)
        *res=A[n]; //inicializa la suma con el primer valor del vector
    else {
        sumavector(A[],n-1,&res);
        *res+=A[n];
    }
}

void sumavector(int A[], int n, int *res) { //devuelve la suma como parametro, inicializado en el main
    if (n>=0) {
        *res+=A[n];
        sumavector(A[],n-1,&res);
    }
}

int sumavector2(int A[],int i,int n) {  //recorriendo del principio al final
    if (i==n)
        return A[i];
    else
        return A[i]+sumavector2(A,i+1,n);
}

int cuentaX(int A[],int i,int n,int X){
    if (i>n)
        return 0;
    else {
        if (A[i]==X)
            return cuentaX(A,i+1,n,X)+1;
        else
            return cuentaX(A,i+1,n,X);
    }
}

int minvec(int A[],int n) { //devuelve el minimo de un vector
     int min;
    if (n==0)
        return A[0];
    else {
      min=minvec(A,n-1);
      if (min>A[n])
        return A[n];
      else
        return min;
    }
}

void main() {
    int A[6]={1,4,2,5,7,9};
    printf("el minimo del vector es %d", minvec(A,6-1));
}

