/*Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par. */

#include <stdio.h>

#define n 5
#define m 4

int suma(int [][m],int ,int,int,int);

void main(){
    int mat[n][m]={
        {4,4,4,4},
        {2,4,2,2},
        {2,2,2,2},
        {2,1,2,1},
        {1,1,1,1},};

        if (suma(mat,n-1,m-1,0,0))
            printf("cumple");
        else
            printf("no cumple");
}

int suma(int mat[][m],int i,int j,int suma_act,int suma_ant) {
    if (i<0)
        return 1;
    else
    if (j>=0) {
        suma_act+=mat[i][j];
        return suma(mat,i,j-1,suma_act,suma_ant);
    }
    else
       if ((suma_act>suma_ant)&&(suma_act%2==0)) {
          suma_ant=suma_act;
          return suma(mat,i-1,m-1,0,suma_ant);
       }
       else
          return 0;
}
