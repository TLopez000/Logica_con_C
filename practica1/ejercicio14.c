/*Desarrollar un subprograma que muestre un cuadrado con bordes de N numerales (N es
parámetro de entrada). Por ej: para N = 4 */

#include <stdio.h>

int main(){
    int i,k,n;
    printf("Ingrese n: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        for (k=1;k<=n;k++){
         if (i==1 || i==n || k==1 || k==n)
          printf("#");
         else
          printf(" ");
        }
        printf("\n");
        }

return 0;
}

