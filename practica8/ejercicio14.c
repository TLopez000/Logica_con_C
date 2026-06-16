/*  Una empresa ferroviaria planifica el tendido de vías para unir cinco localidades determinadas.
Para ello cuenta con la siguiente tabla con las distancias entre las mismas. Se solicita diseñar de
la manera más eficiente dicho tendido. */

#include <stdio.h>
#define N 5

int todosconexos(int CC[]){
    int aux,i=0;
    aux = CC[0];
    while (i<N && CC[i]==aux)
        i++;
    if(i<N)
        return 0;
    else
        return 1;
}

void Kruskal(int Grafo[][N], int Kr[][N]){
    int CC[N] = {0,1,2,3,4};
    int i,j,imin,jmin,min;

    while (!todosconexos(CC)) {
        min = 9999;
        for(i=0; i<N; i++)
            for(j=i+1; j<N; j++)
               if(CC[i]!=CC[j] && Grafo[i][j]>0 && Grafo[i][j] < min) {
                 min = Grafo[i][j];
                 imin=i;
                 jmin=j;
             }

        Kr[imin][jmin]= Grafo[imin][jmin];

        for(i=0;i<N;i++)
            if(CC[i]==CC[jmin])
              CC[i] = CC[imin];
    }
}

void Prim(int Grafo[][N], int Pr[][N]) {
    int U[N] = {0};
    int conexos=1,i,j,imin,jmin,min;

    U[0]=1;
    while (conexos<N){
        min = 9999;
        for(i=0; i<N; i++)
            if (U[i])
            for(j=i+1; j<N;j++)
               if (!U[j] && Grafo[i][j]>0 && Grafo[i][j] < min) {
                  min = Grafo[i][j];
                  imin = i;
                  jmin = j;
                }
        U[jmin] = 1;
        Pr[imin][jmin] = Grafo[imin][jmin];
        conexos++;
    }

}

void muestraAAM(int T[][N]){
    int i,j,suma=0;
    for(i=0;i<N;i++)
        for(j=i+1; j<N; j++)
           if(T[i][j] > 0){
              printf("(%d,%d)\n", i+1,j+1);
              suma+=T[i][j];
           }
    printf("Costo total minimo obtenido: %d", suma);
}

void main(){
       int Grafo[N][N] = {
       /*   L1 L2 L3 L4 L5  */
           { 0, 5, 50, 80, 90}, // 1
           { 0, 0, 70, 60, 50}, // 2
           { 0, 0, 0, 8, 20},   // 3
           { 0, 0, 0, 0, 10},   // 4
           { 0, 0, 0, 0, 0},    // 5
        };

        int Kr[N][N] = {0};

       // Kruskal(Grafo,Kr);
        Prim(Grafo,Kr);
        muestraAAM(Kr);
}
