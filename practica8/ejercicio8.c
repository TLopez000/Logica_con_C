/* 8. Desarrollar funciones recursivas para:
a)  generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.

b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.

c) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
(triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).

d) generar un vector de registros con grado y vértice para aquellos vértices, de un grafo
almacenado en una matriz de adyacencia, cuyo grado sea mayor a 3.  */


//invocacion generavecA(grafo,0,0,N,0,Vec);
void generavecA(int grafo[][N], int i,j,N,int grado, int Vec[]){
    if (i<N)
        if (j<N) {
            if (grafo[i][j])
              grado++;
            generavecA(grafo,i,j+1,N,grado,Vec);
        }
        else {
            Vec[i] = grado;
            generavecA(grafo,i+1,0,N,0,Vec);
        }
}

int mayorentrada(int digrafo[][N]) {
    int i,j,grado_entr,max,maxgrado=0;
    for(j=0; j<N; j++) {
       grado_entr = 0;
       for(i=0; i<N; i++){
          if (digrafo[i][j])
            grado_entr++;
       }
       if (grado_entr>maxgrado) {
         max = j;
         maxgrado = grado_entr;
       }
    }

    return max;
}

int cumplen(int grafo[][N], int i,j,N , int Costo) {
    int i=0,j,cumple=1;

    while (i<N && cumple) {
        cumple = 0;
        j=i+1;
          while(j<N && grafo[i][j] < costo)
           j++;
          if (grafo[i][j] >= Costo)
            cumple = 1;

        j=0;
         while (j < i && grafo[j][i] < costo)
            j++;
         if (grafo[i][j] >= Costo)
            cumple = 1;

        i++;
    }

    return cumple;
}

void generavecD(int grafo[][N],int *dimV, Tvec Vec[]) {
  int i,j,grado;
  for(i=0; i<N; i++){
    grado=0;
    for(j=0; j<N; j++)
      if (grafo[i][j])
        grado++;

    if (grado>3){
        Vec[*dimV].vertice  = i;
        Vec[*dimV].grado = grado;
        (*dimV)++;
    }
  }
}

