//Funcion int que compruebe si existe algun nodo no hoja de clave positiva y grado par, que tenga clave igual o mayor al promedio de sus hijos

int cumplearbol(arboln a, pos p) {
    int cumple=0, grado=0;
    float suma=0;
    pos c;
    if (!nulo(p)) {
        c = hijomasizq(p,a);
        while(!nulo(c) && !cumple) {
            grado++;
            suma+=info(c);
            cumple = cumplearbol (a,c);
            c = hnoder(c,a);
        }
        if (grado==0 || info(p)<=0)
            return cumple;
        else
            return cumple || (grado % 2 == 0 && info(p)>= suma/grado);
    }
    else
        return 0;
}
