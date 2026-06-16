/* Realizar un programa iterativo que calcule e imprima el equivalente binario de un número
entero positivo dado. */

#include <stdio.h>

void cantbits(int *, int);
void binario(int *, int);
void muestra(int, int []);

int main(){
 int n,cant=0;
 printf("Ingrese n ");
 scanf("%d", &n);
 cantbits(&cant,n);
 binario(&cant,n);
 return 0;
}

void cantbits(int *cant, int n) {
    if (n==0) {
    *cant=1;
    bits[0]=0;
    }
    else
      while (n>0) {
      n/=2;
      *cant+=1;
      }
}

void binario(int *cant,int n) {
 int i=0, bits[*cant];
 while (n>0) {
      bits[i]=n%2; //guarda bits en arreglo
      n/=2;        //achico n
      i++;
    }
 muestra(*cant,bits);
}

void muestra(int cant,int bits[]) {
  int i;
  for(i=cant-1;i>=0;i--)          //los bits se muestran invertidos ya que se guardaron al reves
    printf("%d", bits[i]);
}
