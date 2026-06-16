/* Se tiene una lista con equipos de fútbol (nombre y puntaje en el torneo), la cual está ordenada
descendentemente por puntaje (los equipos con el mismo puntaje están ordenados
alfabéticamente). Cada equipo cuenta con una sublista de jugadores (nombre y edad, estado
([A]ctivo, [S]uspendido)).
a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
cumplan el criterio solicitado.
b) Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
mostrando edad promedio de cada equipo.
c) Verificar si el equipo E (dato) tiene P (dato) puntos.
d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos. */

typedef struct nodito{
    char nombre[20],estado;
    int edad;
    struct nodito *sig;}nodito;
typedef nodito *Sublista;

typedef struct nodo{
    char nombre[20];
    int puntaje;
    Sublista sub;
    struct nodo *sig;}nodo;
typedef nodo *Tlista;

void listaK(Tlista L, char K){
    Sublista actS;
    int cont,contTotal=0,max=0;
    char clubmax[20];

    if (L!=NULL){
        while (L!=NULL) {
            cont=0;
            printf("%s\n", L->nombre); //escribo club
            actS=L->sub;
            while (actS!=NULL){
                if (actS->nombre[0]==K){
                    cont++;
                    printf("%s ", actS->nombre);
                }
                actS=actS->sig;
            }
            if (cont>max) {
                max=cont;
                clubmax=L->nombre;
            }
            contTotal+=cont;
            L=L->sig;
        }
        //recorri todos los clubes
        printf("\n");
        printf("CANTIDAD DE JUG LISTADOS: %d  - CLUB MAX: %s\n", contTotal,clubmax);
    }
}

void listaclub(Tlista L, int x){
    Sublista actS;
    float cantjug,acum;

    if (L!=NULL){
        while (L!=NULL){
            if (L->puntaje>=x){
              printf("%s\n", L->nombre);
              acum=0;
              cantjug=0;
              actS=L->sub;
              while (actS!=NULL){
                printf("%s ",actS->nombre);
                acum+=actS->edad;
                cantjug+=1;
                actS=actS->sig;
              }
              printf("\n EDAD PROMEDIO: ", acum/cantjug);
            }
            L=L->sig;
        }
    }
}

int verifica(Tlista L, char E[20], int P) {
    if (L!=NULL){
        while (L!=NULL && L->puntaje>P)
            L=L->sig;

        if (L!=NULL && L->puntaje==P) {
            while (L!=NULL && L->puntaje==P && strcmp(E,L->nombre)>0)
                L=L->sig;
            if (!strcmp(E,L->nombre))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

void eliminasub(Tlista L){
    Sublista antS,actS,elimS;
    if (L!=NULL){
        while(L!=NULL){
            actS=L->sub;
            while (actS!=NULL){
                if (actS->estado=='S'){
                    elim=actS;
                    if (actS==L->sub)
                        L->sub=actS->sig;
                    else
                        antS->sig=actS->sig;
                    actS=actS->sig;
                    free(elim);
                }
                else{
                    antS=actS;
                    actS=actS->sig;
                }
        }
        L=L->sig;
    }
  }
}
