/* Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
c) media matriz (triángulo superior) */

int grado_matriz(int grafo[][N], int vertice){
    int j,cont=0;
    for(j=0;j<N;j++)
        if (grafo[vertice][j])
         cont++;

    return cont;
}

int grado_lista(DirectorioNodos LAdy, int vertice) {
    Lista nodo_act;
    int cont=0;

    nodo_act = LAdy[vertice]->sig;
    while(nodo_act!=NULL){
        cont++;
        nodo_act = nodo_act->sig;
    }

    return cont;
}

int grado_mediamatriz(int grafo[][N], int vertice) {
    int i,j, cont=0;

    //cuento aristas en su fila
    for(j=vertice+1; j<N; j++)
        if (grafo[vertice][j])
          cont++;

    //cuento aristas en su columna
    for(i=0; i<vertice;i++)
        if (grafo[i][vertice])
        cont++;

    return cont;
}
