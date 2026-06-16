 /*Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o -1 en caso de no encontrarlo.
Implementar:

Considerando el arreglo desordenado, una búsqueda lineal recursiva.
Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva. */

#include <stdio.h>
#define DIM 7

int buscalin(int [],int n,int x);
int buscabinaria(int [],int inicio, int fin, int x);

void main(){
    int x=12, vec[]={1,10,18,24,29,35,50};
    printf("X esta en la posicion %d", buscabinaria(vec,0,DIM,x));
}

int buscalin(int vec[],int n,int x){
    if (n<0)
        return -1;
    else {
        if (vec[n]==x)
            return n;
        else
            return buscalin(vec,n-1,x);
    }
}

int buscabinaria(int vec[],int inicio, int fin, int x){
    int medio;
    if (inicio>fin)                   //si me pase de largo, significa que x no esta
        return -1;
    else
    {
     medio=(inicio+fin)/2;                      //calculo el medio de un vector cada vez mas chico
     if (vec[medio]==x)
            return medio;
     else
        if (x<vec[medio])
           return buscabinaria(vec,inicio,medio-1,x);  //si x esta a la izquierda del medio, achico la ventana modificando el fin
        else
            return buscabinaria(vec,medio+1,fin,x);   //si x esta a la derecha del medio, achico la ventana modificando el inicio
    }
}
