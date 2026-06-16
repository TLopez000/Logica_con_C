/*  Utilizar las estructuras que considere adecuadas para determinar si una palabra almacenada en
una cola es palíndroma. Se conoce de antemano la cantidad de letras de la palabra (N).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDADinPilas.h"

#define N 50

void main()
{
    TPila P;
    TelementoP x;
    int i=0, cumple=1;
    char pal[N];

    scanf(" %s", pal);

    iniciaP(&P);         //idea gral: guardo la palabra original y la cargo en la pila para invertirla, luego comparo palabra invertida (de la pila) con palabra original (string)

    for(i=0;pal[i]!='\0';i++)
        poneP(&P,pal[i]);

    i=0; //me paro en el caracter 0 de la string
    while (!vaciaP(P) && cumple){
        sacaP(&P,&x);
        printf("Comparo: %c con %c\n", x, pal[i]);
        if (x != pal[i])
            cumple=0;
        i++;
    }

    printf("%s \n", pal);

    if (cumple)
        printf("es palindromo");
}
