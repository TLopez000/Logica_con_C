//verificar que exista al menos 1 nodo con grado G y clave negativa e impar

int existe(arboln a, posicion p, int G) {
    int grado=0, cumplio=0;
    posicion c;
    if (!nulo(p)){

        c = hijomasizq(p,a);
        while (!nulo(c) && !cumplio){
            grado++;
            cumplio = existe(a,c,G);
            c = hnoder(c,a);
        }

        if (grado==G && info(p)<0 && info(p) % 2 != 0 )
            return 1;
        else
            return cumplio;
    }
    return cumplio;
}


//EXACTAMENTE 1 nodo

int existe(arboln a, posicion p, int G) {
    int grado=0, cant=0;
    posicion c;
    if (!nulo(p)){

        c = hijomasizq(p,a);
        while (!nulo(c)){
            grado++;
            cant += existe(a,c,G);
            c = hnoder(c,a);
        }

       return (grado==G && info(p)<0 && info(p) % 2 != 0 ) + cant;

    }
    return cant;
}

//determinar si en cada nivel hay al menos una vocal

int esvocal(c) {
    c = toupper(c);
    return c=='A' || c=='E' || c=='I'|| c=='O'|| c=='U';
}


int altura(arbol a, posicion p){       //para profundidad es igual, solo inicio altmax en 0
    int altmax=-1,althijo;
    posicion c;

    if (!nulo(p)) {
        c = hijomasizq(p,a);
        while (!nulo(c)) {
            althijo = altura(a,c);
            if (althijo>altmax)
                altmax = althijo;
            c = hnoder(c,a);
        }

    return altmax+1;
    }
    else
        return altmax;
}


int cumpleNivel(arbol a, posicion p, int nivelact, int k) {
    int cumple=0;
    if (!nulo(p) && nivelact<=k){
        if (nivelact == k) {
            if (esvocal(info(p)))
                return 1;
            else
                return cumpleNivel(a,hnoder(p,a),nivelact,k);
        }
        else {
            c = hijomasizq(p,a);
            while (!nulo(c) && !cumple) {
                cumple = cumpleNivel(a,c,nivelact+1,k);
                c = hnoder(c,a);
            }
            return cumple;
        }
    }
    else
        return cumple;
}

int cumplenTodos(arbol a) {
    int i,altura,cumplio=1;
    altura = altura(a,p);
    for(i=0;i<=altura;i++){
        if(!cumpleNivel(a,raiz(a),1,i))
            cumplio=0;
    }
    return cumplio;
}

//////////////////////////////////////////

// Busca clave maxima de un arbol

int maximo(arboln a, posicion p) {
    int max, maxHijo;
    posicion c;

    if (!nulo(p)) {
        max = info(p);
        c = hijomasizq(p,a);

        while(!nulo(c)){
            maxHijo = maximo(a,c);
            if (maxHijo>max)
                max = maxHijo;
            c = hnoder(c,a);
        }

    return max;
   }
   else
    return 0;
}


//Busca altura de un arbol

int altura(arboln a, posicion p) {
    int alturaAct = -1, altHijo;
    posicion c;
    if (!nulo(p)) {

        c = hijomasizq(p,a);

        while(!nulo(c)){
            altHijo = altura(a,c);
            if (altHijo>alturaAct)
                alturaAct = altHijo;
            c = hnoder(c,a);
        }

    return alturaAct+1;
   }
   else
    return 0;
}


