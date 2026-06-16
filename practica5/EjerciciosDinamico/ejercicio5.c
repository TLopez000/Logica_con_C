/* Corregir los errores en el siguiente código manualmente, el cual carga una cola y luego calcula y
muestra la suma de sus elementos.

#include <stdio.h>
#include "tdacola.h"

void leerCola(TCOLA *c);

int main(void) {    //main()
    TCOLA  cola;
    TELEMENTOC n, suma;

    iniciac(cola);  //&cola - iniciac seria mejor invocarlo dentro de leercola
    leerCola(&cola);
    suma == 0;      //suma=0

    while(!vaciac(*cola)) {   //vaciac(cola)
         sacac(cola,  &n);    //sacac(&cola,&n)
         suma += n;
    }
    printf("%d", suma);
    return 0;
}

void leerCola(TCOLA *c) {
    TELEMENTOC n;
    iniciac(&c);             //&c esta mal, es c la direccion de la cola que espera la funcion
    while(scanf("%d", n))    //scanf("%d", &n)==1
        ponec(c, &n);        //ponec(c,n)
}
*/
