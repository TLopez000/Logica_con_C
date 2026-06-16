/*Desarrollar un subprograma para mostrar el camino de un vértice v a un vértice w a partir de la
matriz P generada por el algoritmo de Floyd. (v, w datos). */

#include <stdio.h>
#define N 4

void caminoFloyd(int P[][N], int i, int j) {
    int k = P[i][j];

    if (k != 0) {
        caminoFloyd(P, i, k-1);
        printf("%d ", k);
        caminoFloyd(P, k-1, j);
    }
}

void main () {
    int P[N][N]={
    {0, 4 , 4 , 0},
    {0, 0 , 0 , 0},
    {2, 0 , 0 , 2},
    {0, 0 , 2 , 0},
    };

    int i=0,j=2;

    printf("%d ", i+1);
    caminoFloyd(P,0,2);  //Escribe solo los intermedios. Escribo fuera los extremos ya que si lo hago dentro de la funcion lo escribe bien pero repetido
    printf("%d ", j+1);

}

