
#include "TDAEstColaCirc.h"

void iniciaC (TCola *C){
    (*C).pri=-1;
    (*C).ult=-1;
}

int vaciaC (TCola C){
    return C.pri==-1;
}

void poneC (TCola *C, TelementoC x){
   if (!(*C).ult==MAX-1 && (*C).pri==0 || (*C).ult+1==(*C).pri) {    //si la cola no esta llena ult!=maximo y pri!=ult+1 o pri=0 (pri detras de ult)
       if ((*C).pri==-1){
         (*C).pri=0;
         (*C).ult=0;
       }
       else
           if ((*C).ult==MAX-1)          //si ult=maximo esta llena, doy la vuelta
             (*C).ult=0;
           else
             (*C).ult+=1;
    (*C).datos[(*C).ult]=x;
   }
}

void sacaC (TCola *C, TelementoC *x){
    if ((*C).pri!=-1) {                  //si la cola no esta vacia
        *x=(*C).datos[(*C).pri];
        if ((*C).pri==(*C).ult)
            iniciaC(C);
        else
            if ((*C).pri==MAX-1)
               (*C).pri=0;
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
