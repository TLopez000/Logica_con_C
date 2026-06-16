//TDA dinamico Pilas - Pila como una serie de nodos interconectados

typedef char  TelementoP;

typedef struct nodop{
    TelementoP dato;
    struct nodop *sig;} nodop;

typedef nodop *TPila;

//TPila es un tipo puntero al struct con el dato y el siguiente puntero

void iniciaP (TPila *);

int vaciaP (TPila);

TelementoP consultaP(TPila);

void poneP (TPila *,TelementoP);

void sacaP (TPila *, TelementoP *);
