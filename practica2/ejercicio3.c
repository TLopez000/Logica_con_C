/*Implementar un programa que cree dinámicamente 3 variables enteras (pint1, pint2 y pint3),
muestre su suma y su producto. No utilizar estructuras iterativas. Asegurarse de administrar
correctamente la memoria e implementar una función para evitar duplicaciones de código en la
creación y lectura de cada variable. Desarrollar en primera instancia una función que retorne
un puntero a entero. Para cumplir con el paradigma de programación estructurada, convertir
en una función void que retorne el resultado como parámetro de salida.*/

//CON FUNCION

#include <stdio.h>
#include <stdlib.h>

int* leepuntero();

void main(){
    int suma,prod,*pint1,*pint2,*pint3;
    pint1=leepuntero();
    pint2=leepuntero();
    pint3=leepuntero();

    suma=*pint1+*pint2+*pint3;
    prod=(*pint1)*(*pint2)*(*pint3);

    printf("Suma = %d", suma);
    printf("Prod = %d", prod);

    free(pint1);free(pint2);free(pint3);
}

int* leepuntero() {
  int *p=(int*)malloc(sizeof(int));
  printf("Ingrese valor:\n");
  scanf("%d", p);
  return p;
}
