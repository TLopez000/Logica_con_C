//PREORDEN = BCDEFIJKGHLM
//INORDEN = CBEDIFJKGHML
//POSTORDEN = CEIJKFGHMLDB
//GRADO = 5 y PROFUNDIDAD = 4

void preorden(arbol a, posicion p){
    posicion c;
    if (!Nulo(p)){

        printf("%d", info(p));   //VISITO
        c=hijomasizq(p,a);       //voy a hijo 1
        while (!Nulo(c)) {       //recorro los n hijos con c
            preorden(a,c);       //PREORDEN A CADA SUBARBOL DE P
            c=hnoder(c,a);
        }
    }
}

void inorden(arbol a, posicion p){
    posicion c;
    if (!nulo(p)){
        c = hijomasizq(p,a);
        inorden(a,c);
        printf("%d", info(p));
        while (!nulo(c)) {
            c = hnoder(c,a);
            inorden(a,c);
        }
    }
}

void postorden (arbol a, posicion p) {
    posicion c;
    if (!nulo(p)){
        c=hijomasizq(p,a);
        while (!nulo(c)) {
            postorden(a,c);
            c=hnoder(c,a);
        }
        printf("%d", info(p));
    }
}
