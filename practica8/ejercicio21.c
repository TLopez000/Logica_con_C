/* Dada la matriz de alcance correspondiente a un digrafo, realizar una función recursiva para
hallar el vértice alcanzado por la mayor cantidad de vértices. En el caso de que existan más de
uno, devolver el primero encontrado.  */

#include <stdio.h>
#define N 6

void masalcanzable(int R[][N], int i, int j, int *max, int cont, int *maxV) {
    if (j>=0)
       if (i>=0) {
            if (R[i][j])
               cont++;
            masalcanzable(R,i-1,j,max,cont,maxV);
       }
       else {
          if (cont > *max) {
            *max = cont;
            *maxV = j;
          }
          masalcanzable(R,N,j-1,max,0,maxV);
    }
}

//version int

int cuentacolumna(int R[][N], int i, int j){
    if (i>=0)
        if (R[i][j])
           return 1+cuentacolumna(R,i-1,j);
        else
            return 0;
    else
        return 0;
}

int masalcanzableInt(int R[][N],int j, int max, int maxV) {
    int cont;
    if (j>=0) {

        cont = cuentacolumna(R,N-1,j);

        if (cont > max) {
            max = cont;
            maxV = j;
        }

       return masalcanzableInt(R, j-1, max, maxV);
    }
    else
        return maxV;
}


void main(){
   int max=0, maxV;

   int R[N][N] = {
    /*A B C D E F*/
    {0,0,1,0,1,1}, // A
    {1,0,1,1,1,1}, // B
    {0,0,0,0,1,1}, // C
    {0,0,0,0,1,0}, // D
    {0,0,0,0,1,1}, // E
    {0,0,0,0,1,0}  // F
    };

    masalcanzable(R,N-1,N-1,&max,0,&maxV);
    printf("El vertice mas alcanzable es: %d", masalcanzableInt(R,N-1,0,0));

}
