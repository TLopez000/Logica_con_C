/* Desarrollar una función que reciba tres números enteros y devuelva si son consecutivos entre sí
o si no lo son. */

#include <stdio.h>

int consecutivos(int,int,int);

int main() {
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    if (consecutivos(a,b,c))
        printf("son consecutivos");
    else
        printf("no son consecutivos");

return 0;
}

int consecutivos(int a, int b, int c) {
    if ((a==b-1 && a==c-2) || (a==c-1 && a==b-2) || (b==a-1 && b==c-2) || (b==c-1 && b==a-2)|| (c==a-1 && c==b-2) || (c==b-1 && c==a-2))
        return 1;
    else
        return 0;
}
