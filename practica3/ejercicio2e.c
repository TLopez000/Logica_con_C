/* Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos. */

#include <stdio.h>
#define n 6
#define m 8
#define distinto(a,b) (a!=b)? 1:0

void intercala(int v1[],int i,int v2[],int j, int v3[],int *k);

void main() {
    int v1[n]={1,6,6,10,11,17}, v2[m]={2,5,6,9,10,22,31,100}, v3[20],k=-1;
    intercala(v1,0,v2,0,v3,&k);
    int i;
    for(i=0;i<=k;i++)
        printf("%d ", v3[i]);
}

void intercala(int v1[],int i,int v2[],int j, int v3[], int *k) {
     if ((i<n)&&(j<m)) { //si estoy dentro de ambos vectores
        if (v1[i]<v2[j]) {
               if (distinto(v1[i],v3[*k])) { //si es distinto al ultimo insertado, lo inserto
               (*k)++;
               v3[*k]=v1[i];
               }
               intercala(v1,i+1,v2,j,v3,k);
        }
        else
            if (v1[i]>v2[j]) {
               if (distinto(v2[j],v3[*k])) {
               (*k)++;
               v3[*k]=v2[j];
               }
               intercala(v1,i,v2,j+1,v3,k);
            }
            else { // iguales
                if (distinto(v1[i],v3[*k])){
               (*k)++;
                v3[*k]=v1[i];
                }
                intercala(v1,i+1,v2,j+1,v3,k);
            }
     }
    else
       if ((i>=n)&&(j<m)) {   //se termino v1 y v2 aun no
           if (distinto(v2[j],v3[*k])) {
           (*k)++;
            v3[*k]=v2[j];
           }
            intercala(v1,i,v2,j+1,v3,k);
        }
        else
        if ((i<n)&&(j>=m)) { //se termino v2 y v1 aun no
            if (distinto(v1[i],v3[*k])){
            (*k)++;
            v3[*k]=v1[i];
            }
            intercala(v1,i+1,v2,j,v3,k);
        }
}


