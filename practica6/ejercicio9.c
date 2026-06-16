/* Copiar el contenido completo de una lista simplemente enlazada en una lista doblemente
enlazada y en una lista circular, ambas inicialmente vacías. Ambas copias deben realizarse en la
misma función. En ambos casos se debe mantener el orden de la lista original, siendo el último
elemento de la lista simple el último de la circular. La lista original no debe ser modificada.  */


//lista simple
typedef struct nodoS {
    int dato;
    struct nodoS *sig;}nodoS;
typedef nodoS *TlistaS;

//lista doble
typedef struct nodoD {
    int dato;
    struct nodoD *ant,*sig;}nodoD;
typedef nodoD *PnodoD;
typedef struct {
    PnodoD pri,ult;} TlistaD;

//lista circular
typedef struct nodoC {
    int dato;
    struct nodoC *sig;} nodoC;
typedef nodoC *TlistaC;

void iniciaD(TlistaD *LD) {
    (*LD).pri = (*LD).ult = NULL;
}

void iniciaC(TlistaC *LC) {
    (*LC) = NULL;
}

void copia(TlistaS L, TlistaD *LD, TlistaC *LC) {
    PnodoD nuevoD;
    TlistaC ant,nuevoC;

    iniciaC(LC);
    iniciaD(LD);

    if (L!=NULL) {
        while (L!=NULL) {
            nuevoC = (TlistaC) malloc(sizeof(nodoC));
            nuevoD = (TlistaD) malloc(sizeof(nodoD));

            nuevoC->dato=L->dato;
            nuevoD->dato=L->dato;

            //En ambas listas debo insertar siempre al final para respetar el orden de la lista simple

            //------------------------INSERTO EN CIRCULAR--------------------------------
            if (*LC==NULL) {
                (*LC)=nuevoC;
                nuevoC->sig=nuevoC;
            }
            else {
                nuevoC->sig=(*LC)->sig;
                (*LC)->sig=nuevoC;
                (*LC)=nuevoC;
            }

            //------------------------INSERTO EN DOBLE--------------------------------

            if ((*LD).pri==NULL) {
                nuevoD->ant=NULL;
                nuevoD->sig=NULL;
                (*LD).pri=nuevoD;
                (*LD).ult=nuevoD;
            }
            else {
                nuevoD->sig=NULL;
                nuevoD->ant=(*LD).ult;
                (*LD).ult->sig=nuevoD;
                (*LD).ult=nuevoD;
            }

            L=L->sig;
        }
    }
}
