typedef struct nodo{
    int dato;
    struct nodo *sig}nodo;

typedef nodo *Tlista;

void reemplazaX(Tlista L, int x){
    while (L!=NULL){
        if (L->dato==x)
            L->dato+=1;
        L=L->sig;
    }
}

void reemplazaXenLordenada(Tlista L, int x){
    while (L!=NULL && L->dato<x)
        L=L->sig;
    while (L!=NULL && L->dato==x){
        L->dato+=1;
        L=L->sig;
    }
}

void eliminaX(Tlista *L, int x) {  //elimina TODAS las apariciones de X
    Tlista ant,act;
    act=*L;
    if (*L!=NULL) {
        while (act!=NULL){
            if (act->dato==x) {        //si elimino, el anterior queda igual, solo modifico para que apunte al nodo siguiente al eliminado
                if (act==*L) {         //si el dato esta en la cabecera, corro la cabecera y elimino
                    *L=*L->sig;
                    free(act);
                    act==*L;           //siempre dejo act parado en el primer nodo despues del eliminado
                }
                else {
                    ant->sig=act->sig;
                    free(act);
                    act=ant->sig;
                }
            }                  //si no elimino, muevo el anterior y avanzo
            ant=act;
            act=act->sig;
        }
    }
}

void main(){
    Tlista L;
    int x;
    reemplazaX(L,x);
}
