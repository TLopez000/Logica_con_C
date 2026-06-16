typedef struct nodito{
    char fecha[10];
    float importe;
    struct nodito *sig;} nodito;

typedef nodito *sublista;

typedef struct nodo {
    int nro;
    float total_credito;
    float deuda;
    struct nodo *sig;
    sublista sub;} nodo;

typedef nodo *Tlista;

void insertapago(Tlista L, int nrocli, char fecha[], float pago){
    sublista nuevo,ant,act;
    nuevo=(sublista) malloc(sizeof(nodito));
    strcpy(nuevo->fecha,fecha);
    nuevo->importe=pago;
    nuevo->sig=NULL;
    while (L!=NULL && nrocli>L->nro)  //avanzo con L ya que no se modificara el puntero cabecera
        L=L->sig;
    if (L!=NULL){   //encontre el cliente
        act=L->sub;
        while (act!=NULL && strcmp(fecha,act->fecha)<0){  //busco posicion de insercion del pago
            ant=act;
            act=act->sig;
        }
        if (act==L->sub){
            nuevo->sig=L->sub;
            L->sub=nuevo;
        }
        else {
            nuevo->sig=act;
            ant->sig=nuevo;
        }
        //actualizo deuda
        L->deuda-=pago;
    }
}

void eliminapago(Tlista L,int nrocli, char fecha[]){
    sublista ant,act;
    while (L!=NULL && nrocli>L->nro)
        L=L->sig;
    if (L!=NULL) {
        act=L->sub;
        while (act!=NULL && strcmp(fecha,act->fecha)<0){
            ant=act;
            act=act->sig;
        }
        if (act!=NULL && !strcmp(fecha,act->fecha)){
            L->deuda+=act->importe;
            if (act==L->sub)
                L->sub=act->sig;
            else
                ant->sig=act->sig;
            free(act);
        }
    }
}

void eliminacliente(Tlista *L, int nrocli, int *cont) {
    sublista auxS,actS;
    Tlista act,ant;
    act=*L;
    *cont=0;
    while (act!=NULL && nrocli>act->nro){
        ant=act;
        act=act->sig;
    }
    if (act!=NULL && nrocli==act->nro) {
        actS=act->sub;
        while (actS!=NULL){   //debo eliminar toda la sublista de pagos
            auxS=actS;
            actS=actS->sig;
            free(auxS);
            *cont+=1;
        }

       //analizo si el cliente esta en la cabecera o en el medio de la lista
       if (act==*L)
         *L=(*L)->sig;
       else
        ant->sig=act->sig;

        free(act);
    }
}

void eliminadeuda0(Tlista *L){
    Tlista elim,act,ant;
    sublista antS,actS;
    act=*L;
    while (act!=NULL){

        if (act->deuda==0) {  //si elimino no muevo ant
            actS=act->sub;
            while (actS!=NULL){
                antS=actS;
                actS=actS->sig;
                free(antS);
            }

            if (act==*L)
                *L=act->sig;
            else
                ant->sig=act->sig;

        elim=act;
        act=act->sig;
        free(elim);
        }
        else{            //si no elimino, avanzo ant
            ant=act;
            act=act->sig;
        }
    }
}
