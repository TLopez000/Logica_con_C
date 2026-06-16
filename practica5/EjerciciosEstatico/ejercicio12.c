 /*  Desarrollar un programa que reciba una expresión aritmética que contemple las cuatro
operaciones básicos (+, -, * y /) en notación postfija (polaca invertida) y devuelva su valor, a
menos que ocurra un error porque la expresión no sea válida. Las expresiones postfijas no
necesitan paréntesis para especificar el orden de las operaciones. Ej: 5 *(1+3) en notación
posfija es 5 1 3 + *. Los operandos se limitan a números de un solo dígito y son leídos como
caracteres, de la misma manera que los operadores.
*/

#include <stdio.h>
#include "TDAEstPilas.h"

void main(){
    TPila P;
    TelementoP x,res,n1,n2;
    int error=0;

    iniciaP(&P);

    do { //f para terminar
        scanf(" %c", &x);
        if (x>='0' && x<='9')
            poneP(&P,x);
        else
            if (x=='+' || x=='-' || x=='/' || x=='*'){ //si ingreso operador debo sacar 2 operandos
                if(!vaciaP(P)){
                  sacaP(&P,&n1);
                  n1=n1-'0';     //conversion char a int
                  }
                  if (vaciaP(P))    //si saco el primero y queda la pila vacia, secuencia invalida
                   error=1;
                  else{
                    sacaP(&P,&n2);
                    n2=n2-'0';
                  }
                switch (x){
                 case '+': res = n2 + n1; break;
                 case '-': res = n2 - n1; break;
                 case '*': res = n2 * n1; break;
                 case '/': if (n1==0)
                            error=1;
                           else
                            res=n2 / n1; break;
                }
                if (!error)
                 poneP(&P,'0'+res);   //conversion int a char
             }
       }while (!error && x!='f');

  //da error cuando saco el primer operando y queda vacia la pila o cuando se divide por cero, caracteres distintos de digito o de operadores se ignoran

    if (error)
      printf("secuencia invalida");
    else {
        sacaP(&P,&x);
        if(vaciaP(P))
          printf("%d",x-'0');
        else
            printf("secuencia invalida");
        }
}


