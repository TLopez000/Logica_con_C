/* Implementar un programa de biblioteca que administre la siguiente estructura: un arreglo de
listas simples ordenadas alfabéticamente con los autores que comiencen con la misma letra, o
sea que habrá un elemento del arreglo por cada letra del abecedario, aunque no existan
autores que comiencen con dicha letra.  Para cada autor existe una sublista, ordenada por
título, con los libros disponibles para ser prestados de cada autor:
• Autor
• Sublista de libros de dicho autor
o Titulo
o Autor
o Año de edición
Se debe poder agregar libros a esta estructura.
Además, gestionar una lista de socios con una sublista de libros prestados. Permitir las
operaciones de registrar préstamos (mover el nodo de la sublista del autor al final de la sublista
de libros prestados para el socio) y devoluciones (mover nodo del libro prestado de dicha
sublista a la sublista del autor de acuerdo al orden indicado). Dicha lista posee la siguiente
estructura:
• Socio
• Sublista de libros prestados
o Titulo
o Autor
o Año de edición */

typedef struct nodito {
    char titulo[20], autor[20], año[5];
    struct nodito *sig;
} nodito;
typedef nodito *sublista;

typedef struct nodoA {
    char autor[20];
    struct nodoA *sig;
    sublista sub;
}nodoA;
typedef nodoA *TlistaA;

typedef struct nodoS {
    char socio[20];
    struct nodoS *sig;
    sublista sub;
}nodoS;
typedef nodoS *TlistaS;

typedef TlistaA Autores[25];

void ingresalibro(Autores vec){
    TlistaA L,act,ant,nuevoA;
    sublista nuevoS, actS,antS;

    nuevoS=(sublista) malloc(sizeof(nodito));
    nuevoA=(TlistaA) malloc (sizeof(nodoA));

    char titulo[20],autor[20],año[5];
    scanf("%s %s %s", autor,titulo,año);
    strcpy(nuevoS->titulo,titulo);
    strcpy(nuevoS->autor,autor);
    strcpy(nuevoS->año,año);

    strcpy(nuevoA->autor,autor);
    nuevoA->sub=nuevoS;

    L=vec[autor[0]]; //me paro en la lista del vector que tenga los autores comenzando en esa palabra
    //si lo tengo que insertar es porque no tenia libros anteriormente, primero verifico en cabecera luego recorro
    if (L==NULL || strcmp(autor,L->autor)<0) {
        if (L==NULL) {
            nuevoA->sig=NULL;
            L=nuevoA;
        }
        else {
            nuevoA->sig=L;
            L=nuevoA;
        }
    else {
        //recorro la lista de autores
        act=L;
        while (act!=NULL && strcmp(act->autor,autor)<0) {
            ant=act;
            act=act->sig;
        }
        if (act!=NULL) {
            if (!strcmp(act->autor,autor)){ //si ya existia solo agrego el libro
                free(nuevoA);
                //recorro su sublista de libros

                if (strcmp(titulo,act->sub->titulo)<0){ //asumo que si el autor existe es porque tiene libros por eso no pregunto si actS!=NULL
                    nuevoS->sig=act->sub;
                    act->sub=nuevoS;
                }
                else {
                    actS=act->sub;
                    while (actS!=NULL && strcmp(actS->titulo,autor)<0) {
                     antS=actS;
                     actS=actS->sig;
                    }
                   antS->sig=nuevoS;
                   nuevoS->sig=actS;
                }
            }
            else {
                    //si no existia inserto autor con su primer libro cabecera
                ant->sig=nuevoA;
                nuevoA->sig=act;
            }
        }
    }

}

void prestamo (TlistaS Socios, Autores vec, char autor[20], char titulo[20], char socio[20]) {
    TlistaA L;
    TlistaS actSocio;
    sublista presta,actS,antS;

    L=vec[autor[0]]
    act=L;
    //busco autor
    while (act!=NULL && strcmp(autor,act->autor)>0)
        act=act->sig;
    //enceuntro autor
    if (act!=NULL && !strcmp(autor,act->autor)) {
        //busco libro en cabecera
        if (act->sub!=NULL && !strcmp(titulo,act->sub->titulo)){
            presta=act->sub;
            act->sub=act->sub->sig;
        }
        else {
            //busco libro en las demas posiciones
            actS=act->sub;
            while(actS!=NULL && strcmp(titulo,actS->titulo)>0) {
             antS=actS;
             actS=actS->sig;
            }
            //encontre libro
           if (actS!=NULL && !strcmp(titulo,actS->titulo)) {
             presta=actS;
             antS=actS->sig;
           }
       }
       presta->sig=NULL;
   }
   //presta ya lo obtuve ahora lo inserto en el socio
   actSocio=Socios;
   //busco socio
   while (actSocio!=NULL && strcmp(socio,actSocio->socio)!=0)
    actSocio=actSocio->sig;
    //encuentro socio
   if (actSocio!=NULL && !strcmp(socio,actSocio->socio)) {
    //voy hasta el final de su sublista
    actS=actSocio->sub;
    while (actS!=NULL){
        antS=actS;
        actS=actS->sig;
    }
    //inserto el libro
    antS->sig=presta;
   }
}

void devolucion (TlistaS Socios, Autores vec, char autor[20], char titulo[20], char socio[20]) {
    TlistaA L;
    TlistaS actSocio;
    sublista devol,actS,antS;

   actSocio=Socios;
   //busco socio
   while (actSocio!=NULL && strcmp(socio,actSocio->socio)!=0)
    actSocio=actSocio->sig;
    //encuentro socio
   if (actSocio!=NULL && !strcmp(socio,actSocio->socio)) {
        //busco libro en cabecera
        if (act->sub!=NULL && !strcmp(titulo,act->sub)){
            devol=actSocio->sub;
            actSocio->sub=actSocio->sub->sig;
        }
        else {
            //busco libro en las demas posiciones
            actS=actSocio->sub;
            while(actS!=NULL && strcmp(titulo,actS->titulo)>0) {
             antS=actS;
             actS=actS->sig;
            }
            //encontre libro
           if (actS!=NULL && !strcmp(titulo,actS->titulo)) {
             devol=actS;
             antS=actS->sig;
           }
       }
      devol->sig=NULL;
   }

    //busco lista autor

    L=vec[devol->autor[0]]; //VAR act INNECESARIA, PUEDO RECORRER LA LISTA CON L
    act=L;
    //busco autor
    while (act!=NULL && strcmp(devol->autor,act->autor)>0)
        act=act->sig;
    //encuentro autor
    if (act!=NULL && !strcmp(devol->autor,act->autor)) {
        //inserto el libro
        if (strcmp(devol->titulo,act->sub->titulo)<0) {
            devol->sig=act->sub;
            act->sub=devol;
        }
        else {
            actS=act->sub;
            while (actS!=NULL && strcmp(devol->titulo,actS->sub->titulo)<0) {
                antS=actS;
                actS=actS->sig;
            }
            //encontre la posicion
            antS->sig=devol;
            devol->sig=actS;
        }
    }

}

