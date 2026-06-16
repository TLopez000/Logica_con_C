/*24. Desarrollar un programa que lea una matriz de enteros de NxM y:
a) busque la posición de un valor x (puede no existir)
b) muestre el promedio de cada columna de la matriz.
c) muestre para cada fila que tenga al menos un cero la cantidad de elementos que superan el
promedio de la matriz*/

#include <stdio.h>
#include <stdlib.h>
#define COL 3
#define FIL 3

void leemat(int [][COL]);
void busca(int [][COL],int);
void promcolumna(int [][COL]);
float prommatriz(int[][COL]);
int cumple(int [][COL],int);
void filacero(int [][COL], float);


void main(){
    int mat[FIL][COL];
    leemat(mat);

    int x;
    printf("escriba x: ");
    scanf("%d", &x);
    busca(mat,x);

    promcolumna(mat);

    float promtot;
    promtot=prommatriz(mat);
    filacero(mat,promtot);
}

void leemat(int mat[][COL]){
    int i,j;
    printf("Ingrese los elementos: \n");
    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++)
        scanf("%d", &mat[i][j]);
    }

    for(i=0;i<FIL;i++){
        for(j=0;j<COL;j++)
        printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void busca(int mat[][COL],int x){
    int i=0,j,esta=0;

    while (i<FIL && esta==0){
        j=0;
        while (j<COL && esta==0){
          if (mat[i][j]==x)
                esta=1;
          else
                j++;
        }
        if (esta==0)
           i++;
    }
    if (esta==1)
        printf("X se encuentra en la posicion %d %d\n", i,j);
    else
        printf("X no se encuentra en la matriz\n");
}

void promcolumna(int mat[][COL]){
    int i,j;
    float suma,prom;
    for(j=0;j<COL;j++){
        suma=0;
         for(i=0;i<FIL;i++)
         suma+=mat[i][j];
        prom=suma/FIL;
        printf("promedio columna %d: %f\n", j,prom);
    }
}

float prommatriz(int mat[][COL]){
    int i,j;
    float suma;
    for(j=0;j<COL;j++){
        suma=0;
         for(i=0;i<FIL;i++)
         suma+=mat[i][j];
    }
    return suma/(FIL*COL);
}

int cumple(int mat[][COL],int i){
    int j;
    while (j<COL && mat[i][j]!=0)
    j++;

    if (j<COL && mat[i][j]==0)
      return 1;
    else
      return 0;
}

void filacero(int mat[][COL], float promtot) {
    int i,j,cant;
    for(i=0;i<FIL;i++){
        cant=0;
        if (cumple(mat,i)){
            for(j=0;j<COL;j++)
                if (mat[i][j]>promtot)
                cant+=1;
            printf("FILA %d, Cant elementos que superan el Prom=%f : %d\n",i,promtot,cant);
        }
    }
}



