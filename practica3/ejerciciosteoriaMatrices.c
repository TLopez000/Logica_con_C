int sumaM(int A[][10], int n, int j, int m) {  //recorrido por filas desde la ultima posicion
    if (n==0 && j==0)
        return A[n][j];
    else
        if (j==0)
         return A[n][m]+sumaM(A,n-1,m,m);
        else
         return A[n][m]+sumaM(A,n,j-1,m);
}

int sumaM(int A[][10],int i, int j,int n) {   //sumaM(A,n-1,m-1,n); recorrido por columnas desde la ultima posicion
    if (i==0 && j==0)
        return A[i][j];
    else
        if (i==0)
          return A[i][j]+sumaM(A,n,j-1,n);
        else
          return A[i][j]+sumaM(A,i-1,j,n);
}


//CONTAR CANTIDAD DE VOCALES POR COLUMNA

//#define esvocal(C) C=='A' || C=='E' || C=='I' || C=='O' || C=='U'

//invocacion : cont=0; CuentaVoc(A,n-1,n-1,n-1,cont);
//DESDE ULTIMA COLUMNA;

void CuentaVoc(int A[][10], int i, int j, int n, int cont) {
    if (j>=0) {
        if (i>=0) {
           if (esvocal(A[i][j]))
            cont+=1;
           CuentaVoc((A,i-1,j,n,cont));
        }
        else {
            printf("columna\n %d vocales\n %d", j,cont);
            CuentaVoc(A,n,j-1,n,0);
        }
    }
}


//invocacion : cont=0; CuentaVoc(A,0,0,n-1,cont);
//DESDE PRIMERA COLUMNA, ULT FILA

void CuentaVoc(int A[][10], int i, int j, int n, int cont) {
    if (j<=n) {
        if (i>=0) {
           if (esvocal(A[i][j]))
            cont+=1;
           CuentaVoc((A,i-1,j,n,cont));
        }
        else {
            printf("columna\n %d vocales\n %d", j,cont);
            CuentaVoc(A,n,j+1,n,0);
        }
    }
}

//CONTAR CANTIDAD DE FILAS CON AL MENOS 1 VOCAL EN MATRIZ DE NxN

//invocacion: cont=0; CuentaFil(A,0,0,n-1);

int CuentaFil(char A[][10],int i,int j,int n) {
    if (i>n)
        return 0;
    else {
        if (j<=n) {
            if (esVocal(A[i][j]))
                return 1+CuentaFil(A,i+1,0,n);
            else
                return CuentaFil(A,i,j+1,n);
        }
        else
            return CuentaFil(A,i+1,0,n);
    }
}

//FUNCION QUE DETERMINA SI TODAS LAS FILAS TIENEN ALGUNA VOCAL

//invocacion: Cumple(A,0,0,n-1);

int Cumple(char A[][10],int i,int j,int n) {
    if (i>n)
        return 1;
    else
        if (j<=n)
          if (esVocal(A[i][j]))
           return Cumple(A,i+1,0,n);
          else
            return Cumple(A,i,j+1,n);
        else
            return 0;
}

//función recursiva int para obtener la cantidad de columnas que tienen todos sus elementos pares.

//invocacion: CuentaPar(A,0,0,n);

int CuentaPar(int A[][10], int i,int j,int n) {
    if (j>n)
        return 0;
    else
        if (i<=n)
         if (A[i][j]%2==0)
          return CuentaPar(A,i+1,j,n);
         else
            return CuentaPar(A,0,j+1,n);
        else
            return 1+CuentaPar(A,0,j+1,n);
}

//FUNCION QUE GENERE UN VECTOR CON AL SUMA DE LOS ELEMENTOS DE CADA FILA de una matriz nxn

/*invocacion:
int V[M];
generaV(A,n-1,n-1,n-1,0,v);
*/

void generaV(A[][n],int i,int j,int n, int suma, int v[]) {
    if (i>=0) {
        if (j>=0)
          generaV(A,i,j-1,n,suma+A[i][j],v);
        else {
            v[i]=suma;
            generaV(A,i-1,n,n,0,v);
        }
    }
}

//FUNCION QUE GENERA VECTOR CON LA SUMA DE LOS ELEMENTOS DE AQUELLAS COLUMNAS CON AL MENOS UN 0, MATRIZ DE NXM.

/*invocacion:
int V[m];
int k=-1; //se inicializa en -1 para que luego se incremente correctamente
generaV(A,n-1,m-1,n-1,0,0,v,&k);*/

void generaV(A[][n],int i, int j,int n, int suma,int cumple, int v[],int *k) {
    if (j>=0) {
        if (i>=0) {
           if (A[i][j]==0 && !cumple)
            cumple=1;
           generaV(A,i-1,j,n,suma+A[i][j],cumple,v,k);
        }
        else {
            if (cumple){
                *k+=1;
                v[*k]=suma;
                }
            generaV(A,n,j-1,n,0,0,v,k);
        }
    }
}

//FUNCION QUE OBTIENE LA CANTIDAD DE COLUMNAS CON TODOS SUS ELEMENTOS PARES

//invocacion CuentaPar(A,n-1,n-1,n-1);

int CuentaPar(A[][10],int i, int j, int n) {
    if (j<0)
        return 0;
    else
       if (i>=0)
         if (A[i][j]%2==0)
           return CuentaPar(A,i-1,j,n);
         else
           return CuentaPar(A,n,j-1,n);
       else
         return 1+CuentaPar(A,n,j-1,n);
}
