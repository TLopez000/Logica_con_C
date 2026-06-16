/* Desarrollar un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él una cantidad desconocida de enteros (se encuentran en un archivo de texto). Posteriormente
a la carga, mostrar aquellos que sean positivos. Luego, para finalizar, liberar la memoria
solicitada en tiempo de ejecución.  */

#include <stdlib.h>
#include <stdio.h>

typedef int* ptr;

void leevec(ptr [],int*);
void muestrapos(ptr [],int);
void libera(ptr [],int);

void main(){
    ptr vec[30]; //declaro un vector estatico de punteros a enteros
    int n;

    leevec(vec,&n);
    muestrapos(vec,n);
    libera(vec,n);
}

void leevec(ptr vec[],int *n){
    int i=0,aux;
    FILE *arch;
    arch=fopen("arch5.txt", "r");
    if (arch==NULL){
      printf("Error el archivo no existe");
      *n=0;
    }
    else {                                          //controlo i<30 para evitar overflows y que fscanf lea correctamente el unico argumento(deja de dar verdadero cuando llega el feof)
       while(i<30 && fscanf(arch,"%d", &aux)==1){  // uso aux porque el puntero en vec[i] aun no tiene memoria reservada
           vec[i]=(int *)malloc(sizeof(int)); //vec[i] es un puntero a entero dinamico
           *vec[i]=aux;
           i++;
        }
    *n=i;
    fclose(arch);
    }
}

void muestrapos(ptr vec[],int n){
    int i;
    for(i=0;i<n;i++)
        if (*vec[i]>0)
        printf("%d ", *vec[i]);
}

void libera(ptr vec[],int n){
    int i;
    for(i=0;i<n;i++)
        free(vec[i]);
}
