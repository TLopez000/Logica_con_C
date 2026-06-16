#include <stdio.h>
#include "TDAEstPilas.h"

void cuenta(TPila *P,TelementoP prim, TelementoP seg, int *cont) {
  TelementoP x;

  if (!vaciaP(*P)) {
     sacaP(P,&x);

        if (x==(prim+seg)/2.0)
          *cont+=1;

     cuenta(P,x,prim,cont);
     poneP(P,x);
    }

}

void main1(){
    TPila P;
    int cont;
    cont=0;
    cuenta(&P,0,0,0,&cont);

}
