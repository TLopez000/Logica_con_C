typedef int TelementoP;

typedef struct nodop{
    TelementoP dato;
    struct nodop *sig;}nodop;

typedef nodop *Tpila;

void iniciaP(Tpila *);

void poneP(Tpila *, TelementoP);

void sacaP(Tpila *, TelementoP*);

int vaciaP(Tpila);

TelementoP consultaP(Tpila);
