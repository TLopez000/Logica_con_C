void maximin(arboln a, pos p, int nivelact, int nivelk, int *min, int *max) {
   pos c;
   int grado=0;

   if(!nulo(p) && nivelact <= nivelk)
         if (nivelact==nivelk){
            c = hijomasizq(p,a);
            while (!nulo(c)){
               grado++;
               c = hnoder(c,a);
            }
            if (grado > *max)
               *max = grado;

            if (grado < *min)
               *min = grado;

         }
         else {
           c = hijomasizq(p,a);
           while(!nulo(c)){
             maximin(a,c,nivelact+1,nivelk,min,max);
             c = hnoder(c,a);
           }

         }
}
