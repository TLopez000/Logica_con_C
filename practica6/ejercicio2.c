/* Generar una lista simplemente enlazada a partir del contenido de un arreglo de N enteros no
ordenados:
a) invirtiendo el orden de sus elementos (no se permite recorrer el arreglo comenzando por el
último elemento)
b) manteniendo el orden de sus elementos.
c) de forma ordenada  */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct nodo{
    int dato;
    struct nodo *sig;}nodo;

typedef nodo *Tlista;

/*void invierte(Tlista *L, int vec[]){     //para invertir inserto al principio
    int i;
    Tlista aux;
    for(i=0;i<MAX;i++){
        aux=(Tlista) malloc(sizeof(nodo));
        aux->dato=vec[i];

        aux->sig=*L;     //aux engancha el nodo al que apunta la cabecera
        *L=aux;          //la cabecera apunta al ultimo nodo creado
    }
}*/

/*void mantieneorden(Tlista *L,int vec[]){
    int i;
    Tlista ant,aux;
    for(i=0;i<MAX;i++){
        aux=(Tlista) malloc(sizeof(nodo));
        aux->dato=vec[i];
        aux->sig=NULL;
        if (*L==NULL){            //si va en la cabecera asigno en la cabecera y guardo el nodo en ant.
            aux->sig=*L;
            ant=aux;
            *L=aux;
        }
        else {               //si no, engancho el anterior con el nuevo y guardo el nuevo en ant.
            ant->sig=aux;
            ant=aux;
        }
    }
}*/

void insertaordenado(Tlista *L, int vec[]){
    Tlista ant,act,aux;
    int i;
    for(i=0;i<MAX;i++){
        aux=(Tlista) malloc(sizeof(nodo));
        aux->dato=vec[i];
        if (*L==NULL || (*L)->dato>vec[i]){  //si lista vacia o dato menor al primero, debo correr la cabecera
            aux->sig=*L;
            *L=aux;
        }
        else {
            act=*L;
            while(act!=NULL && vec[i]>act->dato){
                ant=act;
                act=act->sig;
            }
         aux->sig=act;
         ant->sig=aux;
        }
    }
}

void muestra(Tlista L){
    while(L!=NULL){
        printf("%d ", L->dato);
        L=L->sig;
    }
}

void main() {
    int vec[MAX]={10,30,20,15,50};
    Tlista L=NULL;
   // invierte(&L,vec);
   // mantieneorden(&L,vec);
   insertaordenado(&L,vec);
    muestra(L);
}
