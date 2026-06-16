#include "TDAColaCirc.h"

void iniciaC(Tcola *C){
    *C.pri=-1;
    *C.ult=-1;
}

int vaciaC(Tcola C){
    return C.pri==-1;
}

TelementoC consultaC(Tcola C){
    if (C.pri!=-1)
        return C.datos[C.pri];
}

void poneC(Tcola *C, TelementoC x){
    if (!(*C).pri==0 && (*C).ult==MAX-1 || (*C).ult+1=(*C).pri){ //si la cola no esta llena
       if ((*C).pri==-1){
        (*C).pri=0;
        (*C).ult=0;
       }
       else {
         if ((*C).ult==MAX-1)
            (*C).ult=0;
         else
            (*C).ult+=1;
       }
       (*C).datos[(*C).ult]=x;
    }
}

void sacaC(Tcola *C, TelementoC *x){
    if ((*C).pri!=-1){
        *x=(*C).datos[(*C).pri];
        if ((*C).pri==(*C.ult))
            iniciaC(C);
        else
            if ((*C).pri==MAX-1)
              (*C).pri=0;
            else
                (*C).pri+=1;
    }
}
