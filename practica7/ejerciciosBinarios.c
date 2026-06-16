// Dado un binario proveniente de un bosque. Cuantos arboles del bosque tenian exactamente un nodo de grado k

int grado_nodo(arbol a) {
    int g=0;
    while (a!=NULL){
        g++;
        a=a->der;
    }
    return g;
}

int cant_nodosGk(arbol a, int k) {
    int grado;

    if (a!=NULL){
        grado = grado_nodo(a->izq);
        return (grado==k) + cant_nodosGk(a->izq,k) + cant_nodosGk(a->der,k);
    }
    else
        return 0;
}

int cant_arboles(arbol a, int k) {

    if (a!=NULL)
        if ((grado_nodo(a->izq)==k) + cant_nodosGk(a->izq,k)==1)
         return 1+cant_arboles(a->der,k);
        else
            return cant_arboles(a->der,k);
    else
        return 0;
}
//invocacion cant=cant_arboles(a,k);
