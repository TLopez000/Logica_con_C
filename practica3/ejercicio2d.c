/* Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
de una matriz de MxN. */

#include <stdio.h>
#define N 4
#define M 3

void generavec(int mat[][M],int i,int j,int max, int vec[]);

void main(){
     int mat[N][M]={{23,2,3},
                    {5,90,33},
                    {30,21,42},
                    {30,21,23}};
     int i,vec[N];
     generavec(mat,N-1,M-1,0,vec);
     for(i=0;i<N;i++)
        printf("%d ",vec[i]);
}

void generavec(int mat[][M],int i,int j,int max, int vec[]) {
    if (i>-1) {
        if (j>=0) {
            if (mat[i][j]>max)
               max=mat[i][j];
            generavec(mat,i,j-1,max,vec);
        }
        else {
            vec[i]=max;
            generavec(mat,i-1,M-1,0,vec);
        }
    }
}
