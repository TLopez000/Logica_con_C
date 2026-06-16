/* Dadas dos listas simplemente enlazadas de enteros L1 y L2:
a) verificar si son iguales. Considerar que están ordenadas.
b) añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de
L1. En otro caso, añadir L1 al final de L2.
c) eliminar de L1 los nodos cuyas posiciones se encuentran en L2, la cual está ordenada.  */

typedef struct nodo {
    int num;
    struct nodo *sig;}nodo;

typedef nodo *Tlista;

int iguales(Tlista L1, Tlista L2) {
    int cumple=1;
    if (L1!=NULL && L2!=NULL) {
        while (L1!=NULL && L2!=NULL && cumple) {
            if (L1->num != L2->num)
                cumple=0;
            L1=L1->sig;
            L2=L2->sig;
        }
        return cumple;
    }
    else
        return 0;
}

void añade(Tlista L1, Tlista L2) {
    Tlista ant1,act1,ant2;

    if (L1!=NULL && L2!=NULL){
        //voy al final de L1
        act1=L1;
        while (act1!=NULL){
            ant1=act1;
            act1=act1->sig;
        }
        //añado L2 al final de L1
        if (L2->num > ant1->num) {
            while (L2!=NULL) {
                ant1->sig = L2;
                ant1=L2;
                L2=L2->sig;
            }
        //añado L1 al final de L2
          else {
              //voy al final de L2
              while (L2!=NULL){
                  ant2=L2;
                  L2=L2->sig;
              }
              //añado L1 al final de L2
              while (L1!=NULL) {
                  ant2->sig=L1;
                  ant2=L1;
                  L1=L1->sig;
              }
          }
        }
    }
}

void eliminal1 (Tlista *L1, Tlista L2) {
    Tlista elim,ant1=NULL,act1;
    int pos=1;

    if (*L1!=NULL && L2!=NULL) {
        act1=*L1;
        while (act1!=NULL && L2!=NULL) {
            if (L2->num == pos) {
                elim=act1;
                act1=act1->sig;
                if (elim == *L1)
                    *L1=act1;
                else
                    ant1->sig=act1;
                free(elim);
                L2=L2->sig;
            }
            else {
               ant1=act1;
               act1=act1->sig;
            }
            pos++;
       }
   }
}
