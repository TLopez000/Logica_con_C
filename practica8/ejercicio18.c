/* Para un digrafo dado, desarrollar un programa que genere la matriz de alcance R a partir de la
matriz A resultante del algoritmo de Floyd. */

#include <stdio.h>
#define N 4

void escribirMatriz(int M[][N]) {
    int i, j;

    for (i = 0; i < N; i++) {
        printf("| ");
        for (j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("|\n");
    }
}

//La matriz de Floyd devuelve las distancias minimas que hay desde cada vertice a los demas. Por ende, si hay un valor entre 0 e infinito, significa que hay camino.
void Alcanzables(int Floyd[N][N], int R[][N]){
    int i,j;
        for(i=0;i<N;i++)
          for(j=0;j<N;j++)
            if (Floyd[i][j] > 0 && Floyd[i][j] < 999 && i!=j)
                R[i][j] = 1;
}

//si tuviese que obtener la matriz de alcanzabilidad desde la matriz de adyacencia, utilizo Warshall (una matriz inicializada con los caminos directos y luego verifico que existan M[i][k]+M[k][j] > 0 para determinar si j es alcanzable desde i)

void main(){
    int Floyd16[N][N] = {
       /*A B C D     */
       {0,19,29,13}, // A
       {22,0,10,12}, // B
       {47,25,0,37}, // C
       {13,6,999,0},  // D
    };

    int R[N][N] = {0};

    Alcanzables(Floyd16,R);
    escribirMatriz(R);

}
