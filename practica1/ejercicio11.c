 /*Desarrollar una macro que devuelva cada uno de los siguientes resultados:
a) Máximo de 2 números b) Caracter es alfabético
Implementar un programa que utilice las macros desarrolladas.*/

#include <stdio.h>
#include <string.h>

#define max(a,b) (a>b)? a:b
#define alfa(c) (c>='a' && c<='z' || c>='A' && c<='Z')

int main(){
    int a=5, b=10;
    printf("el maximo es %d\n", max(a,b));

    char c;
    c=getchar();
    printf("%d\n",alfa(c)); //devuelve 1 si es verdadero
    if(alfa(c))
        printf("alfabetico");
    else printf("no alfabetico");
return 0;
}
