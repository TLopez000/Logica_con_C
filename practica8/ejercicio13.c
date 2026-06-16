#include <stdio.h>
#define N 7

int costominimo(int AAM[][N]){
    int i,j,suma=0;
    for(i=0; i<N; i++)
            for(j=i+1; j<N; j++)
                suma+= AAM[i][j];
    return suma;
}

int todosconexos(int CC[]){
    int aux, i=0;
    aux = CC[0];
    while(i<N && CC[i]==aux)
        i++;
    if (i<N)
        return 0;
    else
        return 1;
}

//Kruskal busca la arista de menor costo de todo el grafo que una dos componentes distintas.
void Kruskal(int Grafo[][N], int Kr[][N]) {
    int CC[N] = {0,1,2,3,4,5,6};
    int i,j,min, jmin,imin;

    while (!todosconexos(CC)) {
        min = 9999;
        //recorro solo media matriz pues es un grafo no dirigido
        for(i=0; i<N; i++)
            for(j=i+1; j<N; j++)
              if (CC[i]!=CC[j] && Grafo[i][j]>0 && Grafo[i][j] < min) {
                  min = Grafo[i][j];
                  imin = i;
                  jmin = j;
              }
        //al ser un grafo no dirigido, la matriz es simetrica
        Kr[imin][jmin] = Grafo[imin][jmin];
        Kr[jmin][imin] = Grafo[imin][jmin];
        for (i=0; i<N; i++)
            if (CC[i]==CC[jmin])
              CC[i]=CC[imin];
    }
}


//Prim busca la minima arista entre los vertices que ya estan en U
void Prim (int Grafo[][N], int Pr[][N]){
    int i,j,imin,jmin,min,U[N]={0}, conexos=1;

    U[0]=1;

    while (conexos<N) {
            min=9999;
            for(i=0; i<N; i++)
              if (U[i]==1)
                 for(j=0; j<N; j++)
                    if (!U[j] && Grafo[i][j] < min && Grafo[i][j] > 0 ){
                        min = Grafo[i][j];
                        imin = i;
                        jmin = j;
                    }
            conexos++;
            U[jmin]=1;
            Pr[imin][jmin] = Grafo[imin][jmin];
            Pr[jmin][imin] = Grafo[imin][jmin];
    }
}

void main(){
       int Grafo[N][N] = {
       /*    1  2  3  4  5  6  7 */
           { 0, 3, 1, 0, 0, 0, 0 }, // 1
           { 3, 0, 2, 4, 0, 0, 0 }, // 2
           { 1, 2, 0, 1, 3, 0, 0 }, // 3
           { 0, 4, 1, 0, 2, 0, 0 }, // 4
           { 0, 0, 3, 2, 0, 1, 4 }, // 5
           { 0, 0, 0, 0, 1, 0, 0 }, // 6
           { 0, 0, 0, 0, 4, 0, 0 }  // 7
        };

        int Kr[N][N] = {0};
        int Pr[N][N] = {0};

        Kruskal(Grafo,Kr);
        printf("Costo minimo de Kruskal: %d\n", costominimo(Kr));

        Prim(Grafo,Pr);
        printf("Costo minimo de Prim: %d\n", costominimo(Pr));

}
