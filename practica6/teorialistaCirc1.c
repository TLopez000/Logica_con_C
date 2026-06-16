typedef struct nodo {
    int dato;
    int frecuencia;
    struct nodo *sig;} nodo;

typedef nodo *TlistaC;

void muestra(TlistaC LC){
    TlistaC aux;
    if (LC!=NULL){
        aux=LC->sig;
        do  {
            printf("%d ", aux->dato);
            aux=aux->sig;
        }
        while (aux!=LC->sig);
    }
}

void elimina(TlistaC *LC, int dato){
    TlistaC act,ant;
    if (*LC!=NULL){
          ant=(*LC);
          act=(*LC)->sig;
          do {
            ant=act;
            act=act->sig;
          }
          while(act!=(*LC)->sig && act->dato<dato); //salgo cuando di la vuelta o cuando encontre el dato

        if (act->dato==dato){   //si encontre el dato, analizo si esta en la ultima posicion o en otra
            if (act==(*LC)){
            ant->sig=act->sig;
            (*LC)==ant;
            }
            else
             ant->sig=act->sig;
        free(act);
    }
}
