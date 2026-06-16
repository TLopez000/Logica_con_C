
/* Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct{
    char pal[MAX];
    int frec;} TelementoL;

typedef struct nodo{
    TelementoL palabra;
    struct nodo *sig;} nodo;

typedef nodo *Tlista;

void insertaord(Tlista *L, char nuevapal[]){
    Tlista aux,ant,act;
    aux=(Tlista) malloc(sizeof(nodo));
    strcpy(aux->palabra.pal,nuevapal);
    if (*L==NULL || strcmp(nuevapal,(*L)->palabra.pal)<0){ //<0 si nuevapal es menor a la de la cabecera
        aux->sig=*L;
        aux->palabra.frec=1;
        *L=aux;
    }
    else {
        act=*L;
        while(act!=NULL && strcmp(nuevapal,act->palabra.pal)>0){  //busca mientras la palabra nueva sea mayor
            ant=act;
            act=act->sig;
        }
        //sali del while si act null, si encontre la posicion de insercion, o si las palabras son iguales
        if (act!=NULL && !strcmp(nuevapal,act->palabra.pal))
            act->palabra.frec+=1;  //si son iguales solo incremento su frecuencia
        else{
            ant->sig=aux;          //si no, inserto y su frecuencia es 1
            aux->sig=act;
            aux->palabra.frec=1;
        }
    }
}


void leearch(Tlista *L){
    char nuevapal[MAX];
    FILE *arch;
    arch=fopen("texto3.txt","r");
    if (arch==NULL)
        printf("error archivo");
    else
        while (fscanf(arch,"%s", &nuevapal)==1)
            insertaord(L,nuevapal);
}

void muestra(Tlista L){
    while (L!=NULL){
        printf("%s   -  Frec: %d\n", L->palabra.pal,L->palabra.frec);
        L=L->sig;
    }
}
void main(){
    Tlista L;
    leearch(&L);
    muestra(L);
}
