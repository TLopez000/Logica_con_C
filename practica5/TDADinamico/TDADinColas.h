#define MAX 50

typedef  struct{
    char pal[MAX];}TElementoC;

typedef struct nodo{
    TElementoC dato;
    struct nodo *sig;}nodo;

typedef struct{
    nodo *pri,*ult;}TCola;

void iniciaC(TCola *);

void poneC(TCola *,TElementoC);

void sacaC(TCola *,TElementoC *);

int vaciaC(TCola);

TElementoC consultaC(TCola);

