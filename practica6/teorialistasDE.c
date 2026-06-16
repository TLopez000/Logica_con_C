/* A) armar una lista DE ordenada a partir de una lista simple con enteros
   B) eliminar los elementos que tengan la misma paridad que su anterior */

typedef struct nodo{
    int num;
    struct nodo *sig;}nodo;
typedef nodo * Tlista;

typedef struct nodoD{
    int num;
    struct nodoD *ant, *sig;}nodoD;
typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri,ult;}TlistaD;

void arma(TlistaD *LD, Tlista L){
    PnodoD nuevo, act;
    //inicializo lista doble
    (*LD).pri=NULL;
    (*LD).ult=NULL;
    //recorro lista simple
    while (L!=NULL) {
        nuevo = (PnodoD) malloc (sizeof(nodoD));
        nuevo->num=L->num;
        //si va en primer lugar
        if ((*LD).pri==NULL || L->num<(*LD).pri->num){
            nuevo->sig=(*LD).pri;
            nuevo->ant=NULL;
            if ((*LD).pri==NULL)
                (*LD).ult=nuevo;
            else
                (*LD).pri->ant=nuevo;
            (*LD).pri=nuevo;
        }
        //si va en ultimo lugar
        else
           if (L->num > (*LD).ult->num){
               nuevo->sig=NULL;
               nuevo->ant=(*LD).ult;
               (*LD).ult->sig=nuevo;
               (*LD).ult=nuevo;
           }
           //si va en el intermedio, busco posicion de insercion
           else {
            act=(*LD).pri;
            while (nuevo->num > act->num) //no pregunto si act!=null ya que L->num nunca va a ser mayor al ultimo, ya que ese caso se analizo antes
                act=act->sig;
            nuevo->sig=act;
            nuevo->ant=act->ant;
            act->ant->sig=nuevo;
            act->ant=nuevo;

           }
     L=L->sig; //avanzo en la lista simple
    }
}

void elimina(TListaD *LD) {
    TlistaD elim;
    if ((*LD).pri!=NULL){
       act=(*LD).pri->sig; //comienzo desde el segundo numero para poder comparar con el 1ero, el cual no puede ser eliminado ya que no tiene comparacion
       while (act!=NULL) {
            if (act->ant->num % 2 == act->num % 2) {
              elim=act;
              //si elimino en ultima posicion
              if (act==(*LD).ult){
                  act->ant->sig=NULL;
                 (*LD).ult=act->ant;
              }
              //si elimino en posicion intermedia
              else {
                act->sig->ant = act->ant;
                act->ant->sig = act->sig;
              }
            act=act->sig;
            free(elim);
            }
            else
              act=act->sig;
    }
  }
}


