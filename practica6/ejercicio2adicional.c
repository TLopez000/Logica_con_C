/* A partir de una lista simplemente enlazada ordenada de enteros, generar dos listas
simplemente enlazadas de salida: una conteniendo los valores impares ordenados
descendentemente, y la segunda con los valores pares ordenados de manera ascendente. No
se deberá crear nuevos nodos, sino utilizar los de la lista original generando nuevos enlaces. */

typedef struct nodo {
    int num;
    struct nodo *sig;}nodo;
typedef nodo *Tlista;

void genera(Tlista L, Tlista *L1, Tlista *L2){
    Tlista ant1,ant2,act1,act2;
    if (L!=NULL){
        while (L!=NULL){
            //IMPAR - ORDEN DESCENDENTE EN L1
            if (L->num % 2) {
                if (*L1==NULL){
                    *L1=L;
                    (*L1)->sig=NULL;
                }
                else {
                    act1=*L1;
                    while (act1!=NULL && L->num < act1->num){
                        ant1=act1;
                        act1=act1->sig;
                    }
                    ant1->sig = L->num;
                    L->sig = act1;
                }
            else {
                //PAR - ORDEN ASCENDENTE EN L2
                if (*L2==NULL){
                    *L2 = L;
                    (*L2)->sig = NULL;
                }
                else {
                    act2=*L2;
                    while (act2!=NULL && L->num > act2->num ){
                        ant2=act2;
                        act2=act2->sig;
                    }
                    ant2->sig = L->num;
                    L->sig = act2;
                }
            }
            }
          L=L->sig;
        }
    }
}
