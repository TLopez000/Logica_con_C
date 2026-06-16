/*Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0.*/

#include <stdio.h>

int main(){
  int suma=0,n;
  printf("Ingrese numero (0 para finalizar)\n");
  scanf("%d",&n);
  while (n!=0) {
    suma+=n;
    scanf("%d",&n);
  }
  printf("La suma da %d\n", suma);
  return 0;
}
