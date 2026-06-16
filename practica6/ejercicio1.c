/* Dada una lista simplemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro. */

#include <stdio.h>
#include <ctype.h>

typedef struct nodo {
    char dato;
    struct nodo *sig;} nodo;

typedef nodo *Tlista;

void muestra(Tlista L){
    if (L!=NULL)
    while (L!=NULL){
        printf("%c", L->dato);
        L=L->sig;
    }
}

int esvocal(char c){
    c=toupper(c);
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int vocales(Tlista L){
    int cont=0;
    if (L!=NULL)
        while (L!=NULL){
           if (esvocal(L->dato))
            cont++;
           L=L->sig;
        }
    return cont;
}

int ordenada(Tlista L){
    char aux;
    int cumple=1;
    if (L!=NULL) {
        aux=L->dato;
        L=L->sig;
        while (L!=NULL && cumple){        //recorro toda la lista, almaceno el dato anterior en aux y comparo con el actual.
            if (aux>L->dato)             //si en alguna iteracion detecta un desorden, corta el while y cumple=0;
                cumple=0;
            aux=L->dato;
            L=L->sig;
        }
    }
    return cumple;
}

void eliminaP(Tlista *L, int p){
    Tlista ant,act;
    int i=1;

    if (*L!=NULL)
        if (i==p){              //si esta en la cabecera corro la cabecera y elimino
           ant=*L;
           *L=*L->sig;
            free(ant);
        }
        else {
            act=*L;
            while (act!=NULL && i<p) {   //si no, busco hasta que i=p y si es posicion valida enlazo el anterior con el siguiente al nodo en la posicion p y elimino
                ant=act;
                act=act->sig;
                i++;
            }

            if (act!=NULL && i==p){
                ant->sig=act->sig;
                free(act);
            }
        }
}

void main(){
    Tlista L;
    int p,cantvoc;
    char x;
    muestra(L);
    cantvoc=vocales(L);
    if (ordenada(L))
        printf("esta ordenada");
    eliminaP(&L,p);
}



