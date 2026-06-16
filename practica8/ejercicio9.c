/* Hallar el vértice con el mayor grado de entrada, en un digrafo representado por una lista de
adyacencia. */

#include <stdio.h>
#include <stdlib.h>
#define N 8

typedef struct nodo{
    int vertice;
    struct nodo *sig;
} nodo;

typedef nodo *Lista;

typedef Lista DirectorioNodos[N];

void iniciaListas(DirectorioNodos LAdy){
    int i;
    Lista nuevo;
    for(i=0;i<N;i++) {
        nuevo = (Lista) malloc (sizeof(nodo));
        nuevo->vertice=i;
        nuevo->sig=NULL;
        LAdy[i]=nuevo;
    }
}

void insertar(Lista L, int v){
    Lista act,ant, nuevo = (Lista) malloc(sizeof(nodo));
    nuevo->vertice = v;
    nuevo->sig = NULL;
    act = L;
    while (act!=NULL){
        ant = act;
        act = act->sig;
    }
    ant->sig = nuevo;
}

int grado_entrada(DirectorioNodos LAdy, int VGradosE[]) {
    int i,max,maxgrado=0;
    Lista nodo_act;

    //recorro la lista de cada vertice, cargando entradas para los adyacentes
    for(i=0;i<N;i++){
        nodo_act = LAdy[i]->sig;
        while(nodo_act!=NULL) {
            VGradosE[nodo_act->vertice] += 1;
            nodo_act = nodo_act->sig;
        }
    }

    //busco maximo
    for(i=0; i<N;i++)
       if (VGradosE[i]>maxgrado) {
          maxgrado = VGradosE[i];
          max = i;
       }

    return max;
}

void main(){
    int VGradosE[N]={0},grado,vertice = 1;

    DirectorioNodos LAdy;
    iniciaListas(LAdy);
    /* LAdy[0] -> 1 -> 3 */
    insertar(LAdy[0], 1);
    insertar(LAdy[0], 3);

    /* LAdy[1] -> 2 -> 4 -> 5 */
    insertar(LAdy[1], 2);
    insertar(LAdy[1], 4);
    insertar(LAdy[1], 5);

    /* LAdy[2] -> 3 */
    insertar(LAdy[2], 3);

    /* LAdy[3] -> 7 */
    insertar(LAdy[3], 7);

    /* LAdy[4] -> 6 -> 7 */
    insertar(LAdy[4], 6);
    insertar(LAdy[4], 7);

    /* LAdy[5] -> 6 */
    insertar(LAdy[5], 6);

    /* LAdy[6] -> 7 */
    insertar(LAdy[6], 7);

    /* LAdy[7] -> NULL */

    printf("vertice con mayor grado de entrada : %d", grado_entrada(LAdy,VGradosE));
}
