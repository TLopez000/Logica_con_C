#include <stdio.h>
#include <stdlib.h>
#include "TDAEstPilas.h"

#define N 8

int novisitado(int VV[]){         //devuelve la posicion de un vertice no visitado o -1 si ya estan todos visitados
    int i=0;
    while (i<N && VV[i]==1)
        i++;
    if (VV[i]==0)
        return i;
    else
        return -1;
}

void recorre_prof(int grafo[][N], TPila *P, int VV[], char VNodos[]){
    TelementoP nodo_act;
    int j,visitados=0;

    iniciaP(P);
    VV[0]=1;
    printf("%c ", VNodos[0]);
    poneP(P,0);
    visitados++;

        while (!vaciaP(*P)) {
          nodo_act = consultaP(*P);
          j=0;
          while (j<N && (grafo[nodo_act][j]==0 || VV[j])) //avanzo si no hay arista o si ya fue visitado
             j++;

          if (j<N) {
              VV[j]=1;
              visitados++;
              printf("%c ", VNodos[j]);
              poneP(P,j);
           }
           else
              sacaP(P, &nodo_act);
          }

}

void recorre_prof_inconexo(int grafo[][N], TPila *P, int VV[], char VNodos[]){
    TelementoP nodo_act;
    int j,subgrafo=1, pos=0;

    iniciaP(P);


     while (pos!=-1) {
        //Elijo el primer nodo, lo marco y lo pongo en la pila
         VV[pos]=1;
         printf(" %c (%d)", VNodos[pos], subgrafo);
         poneP(P,pos);

        while (!vaciaP(*P)) {
          //consulto el ultimo nodo visitado y busco un adyacente
          nodo_act = consultaP(*P);
          j=0;
          while (j<N && (grafo[nodo_act][j]==0 || VV[j])) //avanzo si no hay arista o si ya fue visitado
             j++;
          //si esta y no fue visitado, lo marco, lo visito y lo pongo en la pila para luego consultarlo
          if (j<N) {
              VV[j]=1;
              printf(" %c (%d)", VNodos[j], subgrafo);
              poneP(P,j);
           }
           //si no hay mas adyacentes, lo saco de la pila
           else
              sacaP(P, &nodo_act);
          }
          //si se vacio la pila y aun hay no visitados, elijo el primer nodo no visitado y repito
          pos = novisitado(VV);
          if (pos!=-1)
            subgrafo++;
     }
}

/*void main () {

    TPila P;

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

    int GrafoNoconexo[N][N] = {
    //A  B  C  D  E  F  G  H
    {0, 1, 0, 0, 0, 0, 0, 0}, // A
    {0, 0, 0, 0, 1, 1, 0, 0}, // B
    {0, 0, 0, 1, 0, 0, 0, 0}, // C
    {0, 0, 0, 0, 0, 0, 0, 0}, // D
    {0, 0, 0, 0, 0, 0, 0, 0}, // E
    {0, 0, 0, 0, 0, 0, 0, 0}, // F
    {0, 0, 0, 0, 0, 0, 0, 1}, // G
    {0, 0, 0, 0, 0, 0, 0, 0}  // H
    };

    char VNodos[N] = {'A','B','C','D','E','F','G','H'};

    int VV[N] = {0};

    //recorre_prof(Grafo, &P, VV, VNodos);

    printf("\n");

    recorre_prof_inconexo(GrafoNoconexo,&P,VV,VNodos);
}*/


