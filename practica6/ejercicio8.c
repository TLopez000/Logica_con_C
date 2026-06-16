/* Dada una lista doblemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro.  */

typedef struct nodo {
    char dato;
    struct nodo *ant,*sig;}nodo;

typedef nodo *PnodoD;

typedef struct {
    PnodoD pri,ult;} TlistaD;

void muestra(TlistaD LD){
    PnodoD act;
    if (LD.pri!=NULL) {
        act=LD.pri;
        while(act!=NULL) {
            printf("%c ", act->dato);
            act=act->sig;
        }
    }
}

int cuentavoc(TlistaD LD) {
    PnodoD act;
    int cont=0;
    if (LD.pri!=NULL) {
        act=LD.pri;
        while(act!=NULL) {
            if (esvocal(act->dato))
                cont++;
            act=act->sig;
        }
    }
    return cont;
}

int ordenada(TlistaD LD) {
    PnodoD act;
    int cumple=1;
    if (LD.pri!=NULL){
        act=LD.pri->sig;
        while (act!=NULL && cumple){
            if (act->dato < act->ant->dato)
            cumple=0;
            act=act->sig;
        }
        return cumple;
    }
    else
        return 0;
}

void eliminaP(TlistaD *LD, int P) {
    int i=0;
    PnodoD act;

    if ((*LD).pri!=NULL) {
        act=(*LD).pri;
        i++;
        while (act!=NULL && i<P) {
            i++;
            act=act->sig;
        }
        if (act!=NULL && i==P){
            if ((*LD).pri==(*LD).ult) {
                (*LD).pri=NULL;
                (*LD).ult=NULL;
                free(act);
            }
            else
                if (act==(*LD).pri) {
                   (*LD).pri->sig->ant=NULL;
                   (*LD).pri=(*LD).pri->sig;
                   free(act);
                }
                else
                    if (act == (*LD).ult) {
                      (*LD).ult->ant->sig=NULL;
                      (*LD).ult=act->ant;
                      free(act);
                    }
                    else {
                      act->ant->sig = act->sig;
                      act->sig->ant = act->ant;
                      free(act);
                    }
        }
    }
}
