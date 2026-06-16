/*  El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar
subprogramas que muestren:
a) el nombre del ganador.
b) los nombres de los 2 finalistas.
c) los nombres de los 4 semifinalistas.
d) los nombres de todos los competidores y la cantidad. */

void ganador(arbol a) {
    if (a!=NULL){
        printf("%s ",a->dato);  //imprime la raiz
    }
}

void finalistas(arbol a, int nivel) { // finalistas(a,1);
    if (a!=NULL && nivel<=2) {
        if (nivel == 2)
            printf("%s ",a->dato);
        else {
          finalistas(a->izq,nivel + 1);
          finalistas(a->der,nivel + 1);
        }
    }
}

void semifinalistas(arbol a, int nivel) { // semifinalistas(a,1);
    if (a!=NULL && nivel<=3) {
        if (nivel == 3)
            printf("%s ",a->dato);
        else {
          semifinalistas(a->izq,nivel + 1);
          semifinalistas(a->der,nivel + 1);
        }
    }
}

void competidores(arbol a, int *cant) {  //competidores(a,&cant);
    if (a!=NULL){
        if(a->der==NULL && a->izq==NULL){
          printf("%s ",a->dato);
          *cant+=1;
        }
        competidores(a->izq,cant);
        competidores(a->der,cant);
    }
}
