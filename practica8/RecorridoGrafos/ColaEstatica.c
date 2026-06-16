
#include "TDAEstColas.h"

void iniciaC (TCola *C){
    (*C).pri=-1;
    (*C).ult=-1;
}

int vaciaC (TCola C){
    return C.pri==-1;
}

void poneC (TCola *C, TelementoC x){
   if ((*C).ult!=MAX-1) {  // si la cola no esta llena
       if (vaciaC(*C))   // si la cola esta vacia , C.pri==-1;
         (*C).pri=0;
       (*C).datos[++((*C).ult)]=x;  //incrementa ult y despues asigna
   }
}

void sacaC (TCola *C, TelementoC *x){
    if ((*C).pri!=-1) {
        *x=(*C).datos[(*C).pri];
        if ((*C).pri==(*C).ult)    //si pri = ult, se acabaron los datos, se vacia la cola
            iniciaC(C);
        else
            (*C).pri+=1;
    }
}

TelementoC consultaC (TCola C){
    if (C.pri!=-1)
        return C.datos[C.pri];
}

int llenaC (TCola C) {
    return C.ult==MAX-1;
}
