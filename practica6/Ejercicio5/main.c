/*Una lista contiene en cada nodo una cola de números enteros. Desarrollar un programa que
genere una pila con los elementos máximos de cada cola de la lista. (Utilizar TDA pila dinámica
y TDA cola circular).*/

#include <stdio.h>
#include "TDAColaCirc.h"
#include "TDAPilaDin.h"

typedef struct nodo{
    Tcola c;
    struct nodo *sig;}nodo;

typedef nodo *Tlista;

void cargapila(Tlista L, Tpila *P) {
    TelementoC aux,max,centinela=99999;
    while(L!=NULL) {
        if (!vacia(L->c)){
            poneC(&L->c,centinela);
            sacaC(&L->c,&aux);
            max=aux;
            while (aux!=centinela){
                poneC(&L->c,aux);
                sacaC(&L->c,&aux);
                if (aux>max)
                   max=aux;
            }
        poneP(P,max);
        }
    L=L->sig;
    }
}

void main(){
    Tlista l;
    Tpila p;
    cargapila(l,&p);
}
