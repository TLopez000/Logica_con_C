/* Dada una lista circular de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro.  */

typedef struct nodoC {
    char dato;
    struct nodoC *sig;} nodoC;

typedef nodoC *TlistaC;

void muestra(TlistaC LC) {
    TlistaC act;
    if (LC!=NULL) {
        act=LC->sig; //arranco desde el primer elemento
        do {
            printf("%c ", act->dato);
            act=act->sig;
        } while (act!=LC->sig);
    }
}

int cuentavoc(TlistaC LC){
    int cont=0;
    TlistaC act;
    if (LC!=NULL) {
        act=LC->sig; //arranco desde el primer elemento
        do {
            if (esvocal(act->dato))
                cont++;
            act=act->sig;
        } while (act!=LC->sig);
    }
    return cont;
}

int ordenada(TlistaC LC) {
    int cumple=1;
    TlistaC ant,act;
    if (LC!=NULL) {
        ant=LC;
        act=LC->sig;
        do {
            if (ant>act)
            cumple=0;
            act=act->sig;
        } while (act!=LC->sig && cumple);
    return cumple;
    }
    else
        return 0;
}

void eliminaP(TlistaC *LC, int P) {
    int i=1;
    TlistaC ant,act,elim;
    if ((*LC)!=NULL) {
        ant=(*LC);
        act=(*LC)->sig;
        do {
            i++;
            ant=act;
            act=act->sig;
        } while (act!=(*LC)->sig && i<P);

        if (i==P) {
                //unico nodo
            if (act==ant)
              (*LD)=NULL;
            else
               //nodo a eliminar coincide con cabecera
               if (act==(*LC)){                                    // ant->sig = act->sig;
                  ant->sig=(*LC)->sig;                             // if (act==(*LC))
                  (*LC)=ant;                                       //  (*LC)=ant;
               }                                                   // free(act);
               //nodo a eliminar en otra posicion
               else
                  ant->sig=act->sig;
            free(act);
        }
    }
}
