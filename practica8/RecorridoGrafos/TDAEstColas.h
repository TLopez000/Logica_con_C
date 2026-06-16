//TDA estatico Colas - Cola como un vector con inicio y final, elementos entran por el final y salen por inicio
#define MAX 50

typedef int TelementoC;

typedef struct{
    TelementoC datos[MAX];
    int pri;
    int ult;} TCola;

void iniciaC (TCola *);

int vaciaC (TCola);

void poneC (TCola *, TelementoC);

void sacaC (TCola *, TelementoC *);

TelementoC consultaC (TCola);

int llenaC (TCola);
