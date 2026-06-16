#include "TDAEstPilas.h"
#include <stdio.h>

void main(){
    TPila P;
    TelementoP aux,c;
    int error=0;

    iniciaP(&P);
    scanf(" %c",&c);
    while (c!='.' && !error && !llenaP(P)) {
        if (c=='(' || c=='{' || c=='[')
            poneP(&P,c);
        else
        if (c==')' || c=='}' || c==']') {
            if (vaciaP(P))
              error=1; //falta parentesis a izquierda (
            else {
              sacaP(&P,&aux);
              if (c==')' && aux!='(' || c=='}' && aux!='{' || c==']' && aux!='[')
               error=1;
            }
        }
        if (!error)
          scanf(" %c", &c);
    }
    if (vaciaP(P) && !error)
        printf("validado");
    else
        printf("secuencia invalida");
}
