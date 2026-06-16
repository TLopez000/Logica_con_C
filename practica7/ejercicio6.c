void nivelcadA(arbol a, int nivelact, int *max, int *nivelMax) {
    int longact;
    if (a!=NULL) {
        if (a->dato[0]=='A'){
            longact = strlen(a->dato);

            if (longact > *max){
                *max = longact;
                *nivelMax = nivelact;
            }
        }
        nivelcadA(a->izq, nivelact + 1, max, nivelMax);
        nivelcadA(a->der, nivelact + 1, max, nivelMax);
    }
}

//invocacion - nivelcadA(a,1,&max,&nivelMax);  max = 0 y nivelMax = 0;
