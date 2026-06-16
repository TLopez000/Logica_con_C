// Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:

// a) retornar la cantidad de nodos que posee.
int cantnodos(arboln a, posicion p) {

    if (!nulo(p))
        return 1+cantnodos(a,hijomasizq(p,a))+cantnodos(a,hnoder(p,a));
    else
        return 0;
}

//////////////////////////////////////////////////

int cantnodos2(arboln a, pos p) {
    pos c;
    int cant=0;
    if (!nulo(p)) {
        cant++;
        c =  hijomasizq(p,a);
        while (!nulo(c)){
            cant+=cantnodos2(a,c);
            c = hnoder(a,c);
        }
        return cant;
    }
    else
        return 0;
}



//b) hallar el porcentaje de claves pares
int cantpares(arboln a, posicion p) {

    if (!nulo(p))
        if (info(p) % 2 == 0 )
          return 1+cantpares(a,hijomasizq(p,a))+cantpares(a,hnoder(p,a));
        else
          return cantpares(a,hijomasizq(p,a))+cantpares(a,hnoder(p,a));
    else
        return 0;
}
/////////////////////////////////////
int cantpares2(arboln a, posicion p) {
    pos c;
    int cant=0;
    if (!nulo(p)) {
        c = hijomasizq(p,a);
        while (!nulo(c)) {
            cant += cantpares2(a,c);
            c = hnoder(c,a);
        }

        return cant + (info(p) % 2 == 0);
    }
    else

        return 0;
}

void porcentajepares(arboln a) {
    float totalpares,totalnodos;
    totalpares = cantpares(a,raiz(a));
    totalnodos = cantnodos(a,raiz(a));
    printf("porcentaje: %f", totalpares*100/totalnodos);
}

/////////////////////////////////

//c) retornar su grado
int grado_nario(arboln a, posicion p) {
    posicion c;
    int grado=0,gradomax=0,gradohijo;
    if (!nulo(p)) {
        c = hijomasizq(p,a);
        while(!nulo(c)){
            grado++;
            gradohijo = grado_nario(a,c);
            if (gradohijo>gradomax)
                gradomax=gradohijo;
            c = hnoder(c,a);
        }
    }
    return (grado > gradomax)? grado:gradomax;
}

//d) hallar la cantidad de nodos de grado impar que hay en niveles impares.

int cant_gradoimpar(arboln a, posicion p, int nivel){
    posicion c;
    int grado=0,cant=0;
    if (!nulo(p)) {
        c = hijomasizq(p,a);
        while(!nulo(c)){
            grado++;
            cant += cant_gradoimpar(a,c,nivel+1);
            c = hnoder(c,a);
        }
    }
        return cant+(nivel % 2 == 1 && grado % 2 ==1);
}

//e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
//a la cantidad de hijos. (función int y función void)

int cumple(arboln a, posicion p){
    int grado=0,cumplehijo=1;
    posicion c;
    if (!nulo(p)){

        c = hijomasizq(p,a);
        while(!nulo(c) && cumplehijo){
            grado++;
            cumplehijo = cumple(a,c);
            c = hnoder(c,a);
        }

        if (grado>0 && grado!=info(p))
            return 0;
        else
            return cumplehijo;
    }
   else
    return 1;

}

//se invoca con cum=1; cumple(a,raiz(a),&cum);
void cumple(arboln a, posicion p, int *cum) {
    posicion c;
    int grado=0;
    if (!nulo(p) && *cum) {
        c = hijomasizq(p,a);
        while(!nulo(c)){
            grado++;
            cumple(a,c,cum);
            c = hnoder(c,a);
        }
        if (grado > 0 && grado != info(p))
            *cum=0;
    }
}

//f) obtener el promedio de las claves del nivel K (dato)

void promedio_k(arboln a, posicion p,int nivel, int k,int *cant, int *suma){
    posicion c;
    if (!nulo(p)) {

        c = hijomasizq(p,a);
        while (!nulo(c)){
            promedio_k(a,c,nivel+1,cant,suma);
            c = hnoder(c,a);
        }
        if (nivel == k) {
            *suma+=info(p);
            *cant+=1;
        }
    }
}

// printf("promedio: %f", suma/cant);

int sumanivelk(arboln a, posicion p, int nivel, int k){
    if (!nulo(p) && nivel<=k)
        if (nivel == k)
          return info(p)+sumanivelk(a,hnoder(p,a),nivel,k);
        else
          return sumanivelk(a,hijomasizq(p,a),nivel+1,k)+sumanivelk(a,hnoder(p,a),nivel,k);
    else
        return 0;
}

//////

int sumanivelk(arboln a, posicion p, int nivel, int k){
    posicion c;
    int suma=0;
    if (!nulo(p) && nivel<=k){
        c = hijomasizq(p,a);
        while(!nulo(c)){
            suma+=sumanivelk(a,c,nivel+1,k);
            c = hnoder(c,a);
        }
        if (nivel==k)
            return suma+info(p);
    }
    return suma;
}


int cantnivelk(arboln a, posicion p, int nivel, int k){
    if (!nulo(p) && nivel<=k)
        if (nivel == k)
          return 1+cantnivelk(a,hnoder(p,a),nivel);
        else
          return cantnivelk(a,hijomasizq(p,a),nivel+1,k)+cantnivelk(a,hnoder(p,a),nivel,k);
    else
        return 0;
}

// verificar si existe algun nodo de grado k en el nivel X

int verifica(arboln a,posicion p,int nivel, int k, int X) {
    int grado=0,cumplio=0;
    posicion c;
    if (!nulo(p) && nivel<=x){
        c = hijomasizq(p,a);
        while (!nulo(c) && !cumplio){
            grado++;
            cumplio = verifica(a,c,nivel+1,k,x);
            c = hnoder(c,a);
        }

        if (nivel==x && grado==k)
            return 1;
    }
    return cumplio;
}
