#include <stdio.h>
#include "TDAEstColas.h"

#define N 8

void marcas(int VV[]) {
    int i;
    printf("\n");
    for(i=0;i<N;i++)
        printf("%d ", VV[i]);
}

int novisitados(int VV[]) {  //retorna -1 si ya visite todos o la posicion del no visitado
    int i, pos = -1;
    while(i<N && VV[i]!=0)
        i++;
    if (VV[i]==0)
        pos = i;
    return pos;
}


//GRAFOS CONEXOS (Se vacia la cola y VV esta completo con 1unos)

void recorre_amplitud(int Grafo[N][N], char VNodos[], int VV[], TCola *C) {
    int i, Pos;

    //Elijo primer nodo, marco, visito y lo pongo en la cola.
    VV[0] = 1;
    printf("%c ", VNodos[0]);
    poneC(C,0);

        while (!vaciaC(*C)) {
            sacaC(C,&Pos);        //Saco el nodo ,  visito los nodos adyacentes aun no visitados y los pongo en la cola
            for(i=0;i<N;i++)
                if (Grafo[Pos][i] == 1 && VV[i] == 0){
                   printf("%c ", VNodos[i]);
                   VV[i] = 1;
                   poneC(C,i);
                 }

            }
}


//GRAFOS INCONEXOS (se vacia la Cola y aun hay CEROS en VV)

void recorre_amplitud_inconexo(int GrafoNoConexo[N][N], char VNodos[], int VV[], TCola *C) {
    int i,subgrafo = 0, Pos = 0;

    while (Pos!= -1) {
        subgrafo++;
       //Elijo primer nodo, marco, visito y lo pongo en la cola.
        VV[Pos] = subgrafo;
        printf("%c ", VNodos[Pos]);
        poneC(C,Pos);

        while (!vaciaC(*C)) {

            sacaC(C,&Pos);        //Saco el nodo ,  visito los nodos adyacentes aun no visitados y los pongo en la cola
            for(i=0;i<N;i++)
                if (GrafoNoConexo[Pos][i] == 1 && VV[i] == 0){
                   printf("%c ", VNodos[i]);
                   VV[i] = subgrafo;
                   poneC(C,i);
                 }

            }
            //Salgo del while cuando se vacia la cola. Si el grafo era conexo, Pos = -1 y salgo del while principal. Si era inconexo, incremento la marca y vuelvo a entrar con el nodo en Pos.
        Pos = novisitados(VV);
}

/*void main () {
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

    TCola C;

    iniciaC(&C);
    recorre_amplitud(Grafo,VNodos,VV,&C);

    //recorre_amplitud_inconexo(GrafoNoconexo,VNodos,VV,&C);
    marcas(VV);
}*/
