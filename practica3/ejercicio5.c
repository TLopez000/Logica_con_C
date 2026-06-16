/* Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es
simétrica (aij = aji) con respecto a su diagonal. */

#include <stdio.h>

#define n 4

int simetrica(int [][n], int,int);

void main(){
    int mat[4][4] = {
    {1, 2, 3, 4},
    {2, 5, 6, 7},
    {3, 6, 8, 9},
    {4, 7, 9, 10}
    };
    if (simetrica(mat,n-2,n-1)) //arranco desde la anteultima fila, ultima columna
        printf("es simetrica");
    else
        printf("no es simetrica");
}

int simetrica(int mat[][n],int i, int j){
    if (i<0)
        return 1;
    else
    if (j>i) { //mientras estoy dentro de la matriz y fuera de la diagonal
        if (mat[i][j]==mat[j][i])
            return simetrica(mat,i,j-1);
        else
            return 0;
    }
    else
        return simetrica(mat,i-1,n-1);
}
