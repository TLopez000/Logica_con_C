/* 10. Dada una lista doblemente enlazada de caracteres que representa una palabra, verificar si es
palíndroma. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodoD {
    char c;
    struct nodoD *sig,*ant;}nodoD;
typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri,ult;}TlistaDE;

void ingresapal(TlistaDE *LD, char c) {
    PnodoD nuevo = (PnodoD) malloc(sizeof(nodoD));
    nuevo->c = c;

    if (LD->pri == NULL) {
        nuevo->sig = NULL;
        nuevo->ant = NULL;
        LD->pri = nuevo;
        LD->ult = nuevo;
    }
    else {
        nuevo->sig = NULL;
        nuevo->ant = LD->ult;
        LD->ult->sig = nuevo;
        LD->ult = nuevo;
    }
}

int palindroma(TlistaDE LD) {
    while (LD.pri!=LD.ult) {
        if (LD.pri->c==LD.ult->c) {
          LD.pri=LD.pri->sig;
          LD.ult=LD.ult->ant;
        }
        else
            return 0;
    }
    if (LD.pri->c==LD.ult->c)
        return 1;
    else
        return 0;

}

void main() {
    TlistaDE LD;
    char c;
    LD.pri=NULL;
    LD.ult=NULL;
    printf("ingrese palabra\n");
    while (scanf(" %c",&c)==1 && c!='F'){
        c=toupper(c);
        ingresapal(&LD,c);
    }

    if (palindroma(LD))
        printf("Es palindroma");
    else
        printf("no es palindroma");
}
