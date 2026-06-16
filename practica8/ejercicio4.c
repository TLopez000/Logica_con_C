/* Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente.  */


#include <stdio.h>
#define N 8


void subyacente(int Grafo[][N]){
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
          if (Grafo[i][j]==1)
            Grafo[j][i]=1;
}

void main () {
    int Grafo[N][N] = {
    //A  B  C  D  E  F  G  H
    {0, 1, 0, 1, 0, 0, 0, 0}, // A
    {0, 0, 1, 0, 1, 1, 0, 0}, // B
    {0, 0, 0, 1, 0, 0, 0, 0}, // C
    {0, 0, 0, 0, 0, 0, 0, 1}, // D
    {0, 0, 0, 0, 0, 0, 1, 1}, // E
    {0, 0, 0, 0, 0, 0, 1, 0}, // F
    {0, 0, 0, 0, 0, 0, 0, 1}, // G
    {0, 0, 0, 0, 0, 0, 0, 0}  // H
    };

    subyacente(Grafo);
}
