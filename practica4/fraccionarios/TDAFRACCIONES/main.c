#include <stdio.h>
#include <stdlib.h>
#include "tdafracciones.h"

int main()
{
    fraccion f1,f2,f3,f4;
    crear(&f1);
    crear(&f2);
    crear(&f4);
    printf("f1: %d/%d\n",numerador(f1),denominador(f1));
    printf("f2: %d/%d\n", numerador(f2),denominador(f2));
    f3=sumar(f1,f2);
    printf("f1+f2=f3: %d/%d\n",numerador(f3),denominador(f3));
    f3=simplificar(f3);
    printf("f3 simplificado: %d/%d\n",numerador(f3),denominador(f3));
    f3=multiplicar(f1,f2);
    printf("f1*f2=f3: %d/%d\n",numerador(f3),denominador(f3));
    f3=dividir(f1,f2);
    printf("f1/f2=f3: %d/%d\n",numerador(f3),denominador(f3));
    f3=restar(f1,f2);
    printf("f1-f2=f3: %d/%d\n",numerador(f3),denominador(f3));
    if (iguales(f1,f4))
        printf("f1 y f4 son iguales");
    return 0;
}
