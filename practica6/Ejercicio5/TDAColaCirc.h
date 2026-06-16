#define MAX 50

typedef int TelementoC;

typedef struct {
    TelementoC datos[MAX];
    int pri,ult;}Tcola

void poneC(Tcola*,TelementoC);

void sacaC(Tcola*,TelementoC*);

TelementoC consultaC(Tcola);

int vaciaC(Tcola);

void iniciaC(Tcola*);
