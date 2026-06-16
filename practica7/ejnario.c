int gradoarbol(arboln a, pos p) {
    int grado=0, gradohijo, gradomax=0;
    float prom;
    pos c;

    if (!nulo(p)) {

        c = hijomasizq(p,a);
        while(!nulo(c)){
          grado++;
          c = hnoder(c,a);
          }

        c = hijomasizq(p,a);
         while (!nulo(c)) {
          gradohijo = gradoarbol(a,c);
          if (gradohijo > gradomax)
            gradomax = gradohijo;
          c = hnoder(c,a);
        }

        return gradomax;
    else
      return gradomax;
}
