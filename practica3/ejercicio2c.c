/* Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada.*/
#include <stdio.h>

int minmat(int [][3], int,int,int);

void main() {
    int mat[3][3]={{23,2,3},{5,90,33},{30,21,42}};
    printf("el minimo es: %d", minmat(mat,3-1,3-1,3-1));
}

int minmat(int mat[][3],int i, int j,int n) {
    int min;
    if ((i==0)&&(j==0))
        return mat[i][j];
    else {
        if (j>0)
            min=minmat(mat,i,j-1,n);
        else
            min=minmat(mat,i-1,n,n);

        if (min>mat[i][j])
            return mat[i][j];
        else
            return min;
    }
}
