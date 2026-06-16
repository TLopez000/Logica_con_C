/*  Desarrollar un programa que lea un vector y, mediante opciones de un menú, calcule e imprima
lo siguiente:
a) los elementos en posiciones impares 1,3,5 o sea segundo, cuarto, sexto...
b) genere otro vector con los elementos divisibles por k (k dato). Muestre el nuevo vector con
otra función
c) busca la posición de un valor x (puede no existir) */

#include <stdio.h>
#include <string.h>

#define DIM 6

void lee(int [],int *);
void imprime(int [],int);
void generavec(int [],int, int [], int *,int);
void muestravec(int [],int);
int busca(int [],int,int);

int main(){
 char op;
 int n=0, v1[DIM];
 lee(v1,&n);

 do {
 printf("\nMENU\n");
 printf("A)imprimir elementos en posicion impar\nB)generar otro vector\nC)buscar x\nZ)EXIT\n");
 scanf(" %c",&op);
   switch (op){
   case 'A': imprime(v1,n);
           break;
   case 'B':{int k,j=0, v2[DIM];
          printf("Ingrese K: ");
          scanf("%d",&k);
          generavec(v1,n,v2,&j,k);
          muestravec(v2,j);}
           break;
   case 'C':{int x;
          printf("Ingrese valor a buscar: ");
          scanf("%d",&x);
          if (busca(v1,n,x))
            printf("El valor se encuentra\n");
            else
            printf("no se encuentra %d\n", x);}
           break;
   }
}
while (op!='Z');
 return 0;
}

void lee(int v1[], int *n) {
  int valor;
  printf("Ingrese valor a cargar (-1 finaliza)\n");
  scanf("%d",&valor);
  while (*n<DIM && valor!=-1) {
    v1[*n]=valor;
    (*n)++;
    if (*n<DIM)
    scanf("%d",&valor);
  }
}

void imprime(int v1[], int n) {
 int i;
 printf("Elementos en posicion impar: ");
 for(i=0;i<n;i++)
    if (i%2==1)
    printf("%d ", v1[i]);
 printf("\n");
}

void generavec(int v1[], int n, int v2[], int *j,int k){
  int i;
  for(i=0;i<n;i++)
    if (v1[i]%k==0) {
        v2[*j]=v1[i];
        *j+=1;
    }
}

void muestravec(int v2[],int j) {
  int i;
  printf("Vector de divisibles por k: ");
  for(i=0;i<j;i++)
    printf("%d ", v2[i]);
  printf("\n");
}

int busca(int v1[],int n,int x) {
 int i=0;
 while (i<n && v1[i]!=x)
    i++;
 if (v1[i]==x)
    return 1;
    else
    return 0;
}


