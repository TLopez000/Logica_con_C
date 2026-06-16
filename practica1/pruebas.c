#include <stdio.h>

#define max 4

void imprime(int v[]);

int main() {
 int v[2]={1};
 imprime(v);
 return 0;
}

void imprime(int v[]) {
 int i;
 for(i=0;i<2;i++)
    printf("%d", v[i]);
}
