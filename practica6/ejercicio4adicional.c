/*  Desarrollar un programa que gestione las reservas de pasajes para los vuelos de una aerolínea.
Para ello se cuenta con una lista de destinos con la siguiente estructura:
• Destino
• Sublista ordenada de Vuelos (a dicho destino)
o Código de vuelo
o Fecha y horario de salida
o Capacidad de pasajeros
o Sublista de pasajes vendidos (para dicho vuelo)
 Documento del pasajero
Tanto para la reserva como para su cancelación se solicita: destino, código de vuelo y
documento del pasajero. El programa debe además permitir agregar destinos y vuelos. Cada
vuelo tiene una fecha y horario de salida y capacidad de pasajeros. El programa debe también
listar el estado (cantidad de reservas, lugares disponibles, etc.) de todos los vuelos de un
destino solicitado al operador.
NOTA: Dado que no se requieren cálculos con las fechas y horarios de salida, se sugiere almacenar dicho campo
como una cadena. */

typedef struct nodito2{
    int dni;
    struct nodito2 *sig;}nodito2;
typedef nodito2 *subPasajes;

typedef struct nodito1 {
    char cod[5],fecha[9],salida[6];
    int capacidad;
    struct nodito1 *sig;
    subPasajes subPas;}nodito1;
typedef nodito1 *subVuelos;

typedef struct nodo {
    char destino[20];
    struct nodo *sig;
    subVuelos subVuelo;}nodo;
typedef nodo *TlistaDestinos;

void reserva (TlistaDestinos L, char destino[20], char cod[5], int dni) {
    subVuelos actVuelo;
    subPasajes nuevopas;
    int cantres;

    if (L!=NULL){
            //busco destino
        while (L!=NULL && strcmp(L->destino,destino)!=0)
            L=L->sig;
        if (L!=NULL && !strcmp(L->destino,destino)){
            //busco vuelo
            actVuelo=L->subVuelo;
            while (actVuelo!=NULL && strcmp(actVuelo->cod,cod)<0)
                actVuelo=actVuelo->sig;
            //verifico si lo encuentro y si tiene capacidad (inserto al principio de la sublista de pasajeros)
            if (actVuelo!=NULL && !strcmp(actVuelo->cod,cod)){
                 nuevopas = (subPasajes) malloc (sizeof(nodito2));
                 nuevopas->dni=dni;
                if (actVuelo->subPas == NULL){
                    nuevopas->sig=NULL;
                    actVuelo->subPas = nuevopas;
                    actVuelo->capacidad-=1;
                }
                else {
                    if (actVuelo->capacidad > 0) {
                        nuevopas->sig = actVuelo->subPas;
                        actVuelo->subPas = nuevopas;
                        actVuelo->capacidad-=1;
                    }
                    else {
                       printf("el vuelo no tiene lugar");
                       free(nuevopas);
                    }
                }
            }
            else
                printf("no existe el vuelo");
        }
        else
            printf("el destino no existe");
    }
}

void cancela(TlistaDestinos L, char destino[20], char cod[5], int dni) {
    subVuelos actVuelo;
    subPasajes antPas,actPas,elim;

    if (L!=NULL){
            //busco destino
        while (L!=NULL && strcmp(L->destino,destino)!=0)
            L=L->sig;
        if (L!=NULL && !strcmp(L->destino,destino)){
            //busco vuelo
            actVuelo=L->subVuelo;
            while (actVuelo!=NULL && strcmp(actVuelo->cod,cod)<0)
                actVuelo=actVuelo->sig;
            if (actVuelo!=NULL && !strcmp(actVuelo->cod,cod)) {
                //si lo encuentro busco pasajero
                actPas=actVuelo->subPas;
                while (actPas!=NULL && dni!=actPas->dni){
                    antPas=actPas;
                    actPas=actPas->sig;
                }
                //si encuentro al pasajero, lo elimino
                if (actPas!=NULL && dni==actPas->dni)){
                    actVuelo->capacidad+=1;
                    if (actPas==actVuelo->subPas)
                        actVuelo->subPas = actPas->sig;
                    else
                        antPas->sig = actPas->sig;
                    free(actPas);
                }
                else
                    printf("el pasajero no existe");
            }
            else
                printf("el vuelo no existe");
        }
        else
            printf("el destino no existe");
    }
}

void listado(TlistaDestinos L, char destino[20]){
    subVuelos actVuelo;
    subPasajes actPas;
    int cantres;

    if (L!=NULL){
            //busco destino
        while (L!=NULL && strcmp(L->destino,destino)!=0)
            L=L->sig;
        if (L!=NULL && !strcmp(L->destino,destino)){
                printf("DESTINO: %s\n", destino);
                actVuelo=L->subVuelo;
                while (actVuelo!=NULL){
                    cantres=0;
                    actPas=actVuelo->subPas;
                    while(actPas!=NULL){
                        cantres++;
                        actPas=actPas->sig;
                    }
                    printf("VUELO: %s CANT RESERVAS: %d LUGARES DISP: %d FECHA Y HORARIO DE SALIDA: %s %s\n", actVuelo->cod, cantres, actVuelo->capacidad, actVuelo->fecha, actVuelo->salida);
                    actVuelo=actVuelo->sig;
                }
        }
    }
}

void agregadestino(TlistaDestinos *L, char destino[20]) {
    TlistaDestinos nuevo;
    nuevo = (TlistaDestinos) malloc (sizeof(nodo));
    strcpy(nuevo->destino,destino);
    nuevo->subVuelo=NULL;
    if (*L==NULL) {
        *L=nuevo;
        nuevo->sig=NULL;
    }
    else {
        nuevo->sig = *L;
        *L = nuevo;
    }
}

void agregavuelo(TlistaDestinos L, char destino[20], char cod[5], char fecha[9], char salida[6], int capacidad) {
    subVuelos antVuelo,actVuelo,nuevo;
    if (L!=NULL){
        while (L!=NULL && strcmp(L->destino,destino)!=0)
          L=L->sig;
        if (L!=NULL && !strcmp(L->destino,destino)) {
            nuevo = (subVuelos) malloc (sizeof(nodito1));
            strcpy(nuevo->cod, cod);
            strcpy(nuevo->fecha, fecha);
            strcpy(nuevo->salida, salida);
            nuevo->capacidad = capacidad;
            nuevo->subPas = NULL;

            if (L->subVuelo == NULL || cod < L->subVuelo) {
                if (L->subVuelo == NULL)
                    nuevo->sig = NULL;
                else
                    nuevo->sig = L->subVuelo;
                L->subVuelo = nuevo;
            }
            else {
                actVuelo = L->subVuelo;
                while (actVuelo!=NULL && strcmp(actVuelo->cod, cod) < 0){
                    antVuelo = actVuelo;
                    actVuelo = actVuelo -> sig;
                }
                antVuelo->sig = nuevo;
                nuevo->sig=actVuelo;
            }

        }
    }
}
