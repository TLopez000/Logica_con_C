/* dada una lista DE que contiene una cadena y las veces que se repite:
A) definir el tipo
B) insertar la cadena X */

#define MAX 20

typedef struct nodoD{
    char pal[MAX];
    int cant;
    struct nodoD *ant,*sig;}nodoD;
typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri,ult;} TListaD;

void inserta(TlistaD *LD, char pal[]) {
    TlistaD nuevo,act;
    nuevo=(PnodoD) malloc(sizeof(nodoD));
    strcpy(nuevo->pal,pal);
    nuevo->cant=1;
    //analizo primer lugar
    if ((*LD).pri==NULL || strcmp(pal,(*LD).pri->pal)<0){
        nuevo->ant=NULL;
        nuevo->sig=(*LD).pri;
        if ((*LD).pri==NULL)
            (*LD).ult=nuevo;
        else
            (*LD).pri->ant=nuevo;
        (*LD).pri=nuevo;
    }
    //analizo ultimo lugar (si la palabra entrante es mayor a la ultima)
    else
        if (strcmp(pal,(*LD).ult->pal)>0) {
           nuevo->ant=(*LD).ult;
           nuevo->sig=NULL;
          (*LD).ult->sig=nuevo;
          (*LD).ult=nuevo;
        }
        //busco posicion de insercion o si la palabra ya existia
        else {
           act=(*LD).pri;
           while (strcmp(pal,act->pal)>0)  //no se pregunta si act!=null ya que la palabra nunca sera mayor a la ultima por analizar el caso antes
              act=act->sig;

           if (!strcmp(pal,act->pal)){
            free(nuevo);
            act->cant+=1;
           }
           else{
            nuevo->sig=act;
            nuevo->ant=act->ant;
            act->ant->sig=nuevo;
            act->ant=nuevo;
            nuevo->cant=1;
           }
        }
}
