int maxprof(arbol a) {
    int izq,der;

    if (a!=NULL){
        izq = 1+maxprof (a->izq);
        der = 1+maxprof (a->der);

        if (izq>der)
            return izq;
        else
            return der;
    }
    else
        return 0;

}

void longmax(arbol a, int *max){
    int longact;
    if (a!=NULL){
        longact = strlen(a->dato);
        if(longact>*max)
            *max=longact;
        longmax(a->izq,max);
        longmax(a->der,max);
    }
}

//////////////////////////////////

int longitudmax(arbol a) {
    int izq,der,max,actual;
    if (a!=NULL){
        actual = strlen(a->dato);

        izq = longitudmax(a->izq);
        der = longitudmax(a->der);

        max = actual;

        if (izq>max)
            max=izq;
        if (der>max)
            max=der;

        return max;
    }
    else
        return 0;
}

int canthijosder(arbol a) {
    if (a!=NULL){
        if (a->der!=NULL)
            return 1+canthijosder(a->izq)+canthijosder(a->der);
        else
            return canthijosder(a->izq)+canthijosder(a->der);
    }
    else
        return 0;
}

