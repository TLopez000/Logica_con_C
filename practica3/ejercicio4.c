/* Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A
(realizar una versión void y otra int) */

#include <stdio.h>

#define n 3
#define m 4

void cuentaX(int [][m],int ,int , int , int *);
int contadorX(int [][m],int , int , int);

void main() {
    int mat[n][m] = {
    {7, 12, 5, 7},
    {3, 7, 9, 1},
    {7, 4, 8, 7} };
    int cont=0,x;
    printf("ingrese numero a encontrar apariciones: \n");
    scanf("%d", &x);
    cuentaX(mat,n-1,m-1,x,&cont);
    printf("contador funcion void: %d\n", cont);
    printf("contador funcion int: %d", contadorX(mat,n-1,m-1,x));
}

void cuentaX(int mat[][m],int i,int j, int x, int *cont){
    if (i>=0) {
        if (j>=0) {
            if (mat[i][j]==x)
               (*cont)++;
            cuentaX(mat,i,j-1,x,cont);
        }
        else
            cuentaX(mat,i-1,m-1,x,cont);
    }
}

int contadorX(int mat[][m],int i, int j, int x){
    if (i<0)
        return 0;
    else
        if (j>=0)
          return (mat[i][j]==x)+contadorX(mat,i,j-1,x);
        else
            return contadorX(mat,i-1,m-1,x);
}
