/*  Un sistema de inscripción a una maratón toma los datos de una cola de competidores (apellido
y nombre) y genera las identificaciones apilándolas según la inicial de los apellidos; debido a la
gran cantidad de inscriptos se pide implementar una pila por cada inicial. Mostrar los datos de
la pila de los apellidos que comienzan con una letra solicitada al operador. */

/* IDEA GRAL: vector de pilas con indice = codigo ascii de cada inicial (una pila para cada inicial)
             25 iniciales (pilas) posibles. Conversion del codigo ascii a indice valido: letra - 'A' */

//TelementoC=TelementoP struct con un campo string. De esta forma puedo trabajar con strings asignando el struct, etc



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TDADinColas.h"
#include "TDADinPilas.h"

#define MAXPIL 26

// Cargar cola desde archivo
void leecola(TCola *C){
    TElementoC nombre, apellido;
    FILE *arch;

    iniciaC(C);

    arch = fopen("texto15.txt", "r");
    if (arch == NULL)
        printf("Error al abrir archivo\n");
    else {
        while (fscanf(arch, "%49s %49s", nombre.pal, apellido.pal) == 2)
          poneC(C, apellido);

        fclose(arch);
    }
}

// Inicializar vector de pilas
void iniciapilas(TPila vec[]){
    int i;
    for(i = 0; i < MAXPIL; i++)
        iniciaP(&vec[i]);
}

// Pasar de cola a pilas por inicial
void leepilas(TPila vec[], TCola *C){
    TElementoC apellidoc;
    TelementoP apellidop;
    int indice;

    iniciapilas(vec);

    while (!vaciaC(*C)){
        sacaC(C, &apellidoc);

        strcpy(apellidop.pal, apellidoc.pal);

        indice = toupper(apellidop.pal[0]) - 'A';

        if (indice >= 0 && indice < MAX)
            poneP(&vec[indice], apellidop);
    }
}

// Mostrar pila según inicial
void muestrapila(TPila vec[]){
    char letra;
    int indice;
    TelementoP apellidop;

    printf("Ingrese inicial: ");
    scanf(" %c", &letra);

    letra = toupper(letra);
    indice = letra - 'A';

    if (indice < 0 || indice >= MAX)
        printf("Inicial invalida\n");

    printf("Pila de inicial %c:\n", letra);

    while (!vaciaP(vec[indice])){
        sacaP(&vec[indice], &apellidop);
        printf("%s\n", apellidop.pal);
    }
}

// Programa principal
int main(){
    TCola C;
    TPila vec[MAX];

    leecola(&C);
    leepilas(vec, &C);
    muestrapila(vec);

    return 0;
}
