/*  Simular un juego de naipes donde N jugadores van tomando un naipe del mazo por turno.  El
juego finaliza cuando el mazo queda vacío. El puntaje de cada jugador consiste en la sumatoria
de los números de los naipes que fue tomando. Si el palo del naipe tomado coincide con el palo
del levantado en el turno anterior el número se duplica. Implementar utilizando las estructuras
(pilas y/o colas) que considere necesarias.  */

//IDEA GRAL : Mazo como pila y un arreglo de N jugadores que guarda su puntaje
/* TelementoP = typedef struct{
                char palo;
                int nro;} TelementoP;*/

#define N 5

#include <stdio.h>
#include "TDADinPilas.h"

void juego(TPila *Mazo,int vec[]){
    TelementoP naipe;
    int puntaje,jugador=0;
    char palo_ant=' ';

    while (!vaciaP(Mazo)){
        sacaP(Mazo,&naipe);
        if (naipe.palo==palo_ant)
            puntaje=naipe.nro*2;
        else
            puntaje=naipe.nro;
        palo_ant=naipe.palo;
        vec[jugador]+=puntaje;
        jugador++;
        if (jugador==N)
            jugador=0;
    }
}

void ganador(int vec[]){
    int i,jugador,max=0;
    for(i=0;i<N;i++)
        if (vec[i]>max){
            max=vec[i];
            jugador=i;
        }
    printf("el ganador es el jugador: %d", jugador+1);
}

void main(){
    TPila Mazo;
    int vec[N]={0};

    inicia(&Mazo);
    carga(&Mazo);

    juego(&Mazo,vec);

    ganador(vec);
}
