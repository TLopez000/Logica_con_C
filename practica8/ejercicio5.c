/* Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice */

#include <stdio.h>

#define N 8

int grado_entrada(int g[][N], int vertice){
    int i,cont=0;
    for(i=0;i<N;i++)
      if (g[i][vertice])
        cont++;
    return cont;
}

int grado_salida(int g[][N], int vertice){
    int j,cont=0;
    for(j=0;j<N;j++)
      if (g[vertice][j])
        cont++;
    return cont;
}

void main () {
    int grado,vertice=3;

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

    grado = grado_entrada(Grafo,vertice) + grado_salida(Grafo,vertice) - Grafo[vertice][vertice];

    printf("grado: %d", grado);
}
