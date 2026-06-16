#include "tdafracciones.h"
#include <stdio.h>

int mcd(int a, int b){
    int resto;
    if (a<0)
        a=-a;
    if (b<0)
        b=-b;
    if (a==b)
        return a;
    else {
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
    }
}

void crear(fraccion *f) {
  int n,d;
  printf("numerador: \n");
  scanf("%d", &n);
  printf("denominador: \n");
  scanf("%d", &d);
  (*f).numerador=n;
  (*f).denominador=d;
}

int numerador(fraccion f){
    return f.numerador;
}

int denominador(fraccion f){
    return f.denominador;
}

fraccion sumar(fraccion f1, fraccion f2){
    fraccion aux;
    aux.denominador=f1.denominador*f2.denominador;
    aux.numerador=((aux.denominador/f1.denominador)*f1.numerador)+((aux.denominador/f2.denominador)*f2.numerador);
    return aux;
}

fraccion restar(fraccion f1, fraccion f2){
    fraccion aux;
    aux.denominador=f1.denominador*f2.denominador;
    aux.numerador=((aux.denominador/f1.denominador)*f1.numerador)-((aux.denominador/f2.denominador)*f2.numerador);
    return aux;
}

fraccion multiplicar(fraccion f1, fraccion f2){
    fraccion aux;
    aux.denominador=f1.denominador*f2.denominador;
    aux.numerador=f1.numerador*f2.numerador;
    return aux;
}

fraccion dividir(fraccion f1, fraccion f2){
    fraccion aux;
    aux.denominador=f2.denominador*f1.numerador;
    aux.numerador=f2.numerador*f1.denominador;
    return aux;
}

fraccion simplificar(fraccion f){
    fraccion aux;
    int divisor=mcd(f.numerador,f.denominador);
    aux.numerador=f.numerador/divisor;
    aux.denominador=f.denominador/divisor;
    return aux;
}

int iguales(fraccion f1, fraccion f2){
    fraccion aux1,aux2;
    aux1=simplificar(f1);
    aux2=simplificar(f2);
    if ((aux1.numerador==aux2.numerador)&&(aux1.denominador==aux2.denominador))
      return 1;
    else
        return 0;
}
