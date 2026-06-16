/*Dado un vector A de N elementos, obtener el promedio de sus elementos. */

#include <stdio.h>
#define n 4

float vecprom(int [],int,float);

void main(){
    int v[n]={2,10,2,10};
    printf("el promedio del vector es %.2f", vecprom(v,n-1,0));
}

float vecprom(int v[],int i,float suma) {
    if (i<0)
        return suma/n;
    else {
        suma+=v[i];
        return vecprom(v,i-1,suma);
    }
}
