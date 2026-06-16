/* Desarrollar un subprograma para mostrar el camino del vértice origen al vértice v (dato) a partir
del vector P generado por el algoritmo de Dijkstra.*/

#include <stdio.h>
#define N 4

//se suma y se resta uno a i ya que trabajo con los indices del vector y no con el numero de vertice (los cuales estan corridos en 1 unidad)

void caminoDijkstra(int P[], int i) {
    if (i > 0) {
          caminoDijkstra(P, P[i]-1);
          printf("%d ", i+1);
    }
    else
        printf("%d ", 1);
}

void main(){
              //1 2 3 4
    int P[N] = {0,4,2,0};

    caminoDijkstra(P,2); //estoy llamando para que me imprima el camino mas corto hasta el vertice 3
}
