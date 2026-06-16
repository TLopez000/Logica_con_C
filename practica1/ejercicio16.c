/* Desarrollar un subprograma que reciba una cantidad de segundos y devuelva su equivalente en
el formato horas:minutos:segundos */

#include <stdio.h>

int main(){
 unsigned long int hs,min,segs;
 printf("ingrese segundos: ");
 scanf("%d", &segs);
 hs=segs/3600; //3600 segs es 1 hora , la division me da la cantidad de hs
 min=(segs%3600)/60; //el resto de segs que quedan de dividir las horas, son min
 segs%=60; //el resto son segundos

 printf("%d hs %d min %d segs", hs,min,segs);

 return 0;
}
