int buscax(arbol a, int x) {
    if (a!=NULL)
        if (a->dato==x)
        return 1;
        else
            return buscax(a->izq,x) || buscax(a->der,x);
    else
        return 0;
}

int buscaabb(arbol a,int x){
    if (a!=NULL)
        if (x<a->dato)
         return buscaabb(a->izq, x);
        else
            if (x>a->dato)
             return buscaabb(a->der, x);
            else
                return 1;
    else
        return 0;
}
