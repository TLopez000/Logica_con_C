#include <stdio.h>
#include <stdlib.h>
#include "TDAEstPilas.h"
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

int novisitado2(int VV[]){         //devuelve la posicion de un vertice no visitado o -1 si ya estan todos visitados
    int i=0;
    while (i<N && VV[i]==1)
        i++;
    if (VV[i]==0)
        return i;
    else
        return -1;
}

void recorre_prof_lista(DirectorioNodos LAdy, TPila *P){
    int VV[N] = {0}, vertice;
    Lista nodo_act;

    VV[0] = 1;
    printf("%d ", LAdy[0]->vertice);
    poneP(P, LAdy[0]->vertice);

    while (!vaciaP(*P)) {
        vertice = consultaP(*P);
        nodo_act = LAdy[vertice]->sig;
        while (nodo_act!=NULL && VV[nodo_act->vertice]==1)
            nodo_act = nodo_act->sig;

        if (nodo_act!=NULL){
            VV[nodo_act->vertice] = 1;
            printf("%d ", nodo_act->vertice);
            poneP(P,nodo_act->vertice);
        }
        else
            sacaP(P,&vertice);
    }
}

void recorre_prof_lista_no_conexo(DirectorioNodos LAdy, TPila *P){
    int VV[N] = {0}, vertice, pos = 0, subgrafo = 0;
    Lista nodo_act;

    while (pos!=-1) {
       subgrafo++;

       VV[pos] = 1;
       printf(" %d (%d)", LAdy[pos]->vertice, subgrafo);
       poneP(P, LAdy[pos]->vertice);

    while (!vaciaP(*P)) {
        vertice = consultaP(*P);
        nodo_act = LAdy[vertice]->sig;
        while (nodo_act!=NULL && VV[nodo_act->vertice]==1)
            nodo_act = nodo_act->sig;

        if (nodo_act!=NULL){
            VV[nodo_act->vertice] = 1;
            printf(" %d (%d)", nodo_act->vertice, subgrafo);
            poneP(P,nodo_act->vertice);
        }
        else
            sacaP(P,&vertice);
    }

    pos = novisitado2(VV);
    }
}

void main(){

    TPila P;

    DirectorioNodos LAdy;

    iniciaListas(LAdy);
    /* LAdy[0] -> 1 -> 3 */
    insertar(LAdy[0], 1);
    insertar(LAdy[0], 3);

    /* LAdy[1] -> 2 -> 4 -> 5 */
    insertar(LAdy[1], 2);
    insertar(LAdy[1], 4);
    insertar(LAdy[1], 5);

    /* LAdy[3] -> 7 */
    insertar(LAdy[3], 7);

    /* LAdy[4] -> 6 -> 7 */
    insertar(LAdy[4], 6);

    /* LAdy[5] -> 6 */
    insertar(LAdy[5], 6);

    /* LAdy[6] -> 7 */
    insertar(LAdy[6], 7);

    /* LAdy[7] -> NULL */
    iniciaP(&P);
    recorre_prof_lista_no_conexo(LAdy,&P);

}
