//TDA ESTATICO PILAS - PILA como vector con TOPE

#define MAX 50

typedef char TelementoP;

typedef struct {
    TelementoP datos[MAX];
    TelementoP tope;
} TPila;

void iniciaP (TPila *);

int vaciaP (TPila);

TelementoP consultaP(TPila);

void poneP (TPila *,TelementoP);

void sacaP (TPila *, TelementoP *);

int llenaP (TPila);
