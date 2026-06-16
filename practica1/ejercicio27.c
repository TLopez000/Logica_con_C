/*Desarrollar una función que a partir de una matriz de NxM elementos enteros, devuelva en un
arreglo de structs, fila, columna y valor de las componentes de la matriz divisibles por N+M */

#include <stdio.h>

#define N 2
#define M 3

typedef struct{
    int fil;
    int col;
    int valor;}elem;

typedef elem Tvec[N*M];

void cargamat(int [][M]);
void cargavec(int [][M],Tvec);
void muestravec(Tvec,int);

void main(){
    Tvec Vec;
    int Mat[N][M];
    cargamat(Mat);
    cargavec(Mat,Vec);
}

void cargamat(int mat[][M]){
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        scanf("%d", &mat[i][j]);
}

void cargavec(int mat[][M],Tvec vec){
    int i,j,k=0;
    elem aux;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++) {
          if (mat[i][j]%(N+M)==0){
            aux.fil=i;
            aux.col=j;
            aux.valor=mat[i][j];
            vec[k]=aux;
            k++;
          }
        }
    muestravec(vec,k);
}

void muestravec(Tvec vec,int k){
    int i;
    for(i=0;i<k;i++)
      printf("FILA: %d COLUMNA: %d VALOR: %d\n",vec[i].fil,vec[i].col,vec[i].valor);
}

