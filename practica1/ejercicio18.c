/*Desarrollar un subprograma que duplique los elementos de un vector ubicados en las
posiciones pares. Implementar 3 veces utilizando for, while y do while */

#include <stdio.h>

void carga(int [],int);
void duplica(int [], int);
void muestra(int[],int);

int main(){
  int n=10,vec[n];
  carga(vec,n);
  duplica(vec,n);
  muestra(vec,n);
return 0;
}

void carga(int vec[],int n) {
 int i;
 for(i=0;i<n;i++)
    vec[i]=i;
}

/*void duplica(int vec[], int n) {
 int i;
 for(i=0;i<n;i++)
    if (i%2==0)
    vec[i]*=2;
}*/

/*void duplica(int vec[], int n) {
 int i=0;
 while (i<n){
    if (i%2==0)
        vec[i]*=2;
    i++;
   }
}*/

void duplica(int vec[], int n) {
 int i=0;
 do {
    if (i%2==0)
    vec[i]*=2;
 i++; }
 while (i<n);
}

void muestra(int vec[], int n) {
 int i;
 for(i=0;i<n;i++)
    printf("%d ", vec[i]);
}
