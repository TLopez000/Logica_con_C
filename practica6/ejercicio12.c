/*  Una lista doble contiene en cada nodo un rango de números enteros [A,B] y una sublista de
enteros. Generar una lista simple paralela a la lista doble donde cada nodo contenga el
promedio de los valores de la sublista y la cantidad de elementos de la misma que no
pertenecen al rango [A,B].*/

#define enrango(LimInf,LimSup,X) (LimInf<=X && LimSup>=X)

typedef struct nodito{
    int x;
    struct nodito *sig;}nodito;
typedef nodito *sublista;

typedef struct nodoD {
    int LimInf,LimSup;
    sublista sub;
    struct nodoD *ant, *sig;}nodoD;
typedef nodoD *PnodoD;
typedef struct {
    PnodoD pri,ult;} TlistaD;

typedef struct nodoS{
    float prom;
    int cant;
    struct nodoS *sig;}nodoS;
typedef nodoS *TlistaS;


//inicialmente la lista simple esta vacia L=NULL
void cargalistaS(TlistaS *L, TlistaD LD) {
    TlistaS nuevo;
    PnodoD actD;
    sublista actSub;
    float suma,cant;
    int cantnorango;

    if (LD.pri!=NULL) {

        actD=LD.ult;
        while (actD!=NULL){
            suma=0;
            cant=0;
            cantnorango=0;
            actSub=actD->sub;
            while (actSub!=NULL){
                suma+=actSub->x;
                cant++;
                if (!enrango(actD->LimInf, actD->LimSup, actSub->x))
                    cantnorango++;
                actSub=actSub->sig;
            }
            nuevo=(TlistaS) malloc(sizeof(nodoS));
            nuevo->prom=suma/cant;
            nuevo->cant=cantnorango;
            nuevo->sig=NULL;

            /* Recorrido lista doble:
            De pri a ult -> insertar al final en la lista simple para que quede igual de ordenada
            De ult a pri -> inserto al principio en la lista simple para que quede igual de ordenada (evito recorrerla) <---------- CONVIENE ESTA */

            if (*L==NULL){
                (*L)=nuevo;
                nuevo->sig=NULL;
            }
            else {
                nuevo->sig=*L;
                *L=nuevo;
            }
            actD=actD->ant;
        }
    }
}
