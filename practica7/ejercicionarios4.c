int verifica(arboln a, pos p, int nivelact, int k){
    int grado=0, claveact,clavehijo, cumplemayor=0, cumplemenor=0, cumpleSub=1;
    pos c;

    if(!nulo(p) && nivelactk<=k) {
       c = hijomasizq(p,a);
       claveact=strlen(info(p));

       while(!nulo(c) && cumpleSub) {
         clavehijo = strlen(info(c));
         if (clavehijo < claveact)
            cumplemenor=1;

         if (clavehijo > claveact)
            cumplemayor=1;

         cumpleSub = verifica(a,c,nivelact+1,k);
         c = hnoder(c,a);
       }

       if (nivelact==k && grado>1)
         return cumplemenor && cumplemayor && cumpleSub;
       else
         return cumpleSub;
    }
    else
      return 1;

}
