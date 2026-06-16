/* 25. Leer el nombre y la edad de N personas, calcular e imprimir:
a) el listado de nombres de las personas de más de X años (X es dato).
b) el porcentaje de las personas mayores de edad (sobre el total).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[15];
    int edad;}persona;

void lee(persona **,int);
void lista(persona [],int,int);
float porcentaje(persona [],int);

void main(){
    int n;
    persona *vec;
    printf("ingrese N: ");
    scanf("%d", &n);
    lee(&vec,n);

    int x;
    printf("ingrese X para obtener el listado de personas mayores: \n");
    scanf("%d",&x);
    lista(vec,n,x);

    printf("El porcentaje de adultos es: %2.2f", porcentaje(vec,n)*100);

    free(vec);
}

void lee(persona **ptr,int n){
    int i;
    *ptr=(persona *) malloc(sizeof(persona)*n);
    for(i=0;i<n;i++){
       printf("NOMBRE: ");
       scanf(" %s", (*ptr+i)->nombre);
       printf("EDAD: ");
       scanf("%d", &(*ptr+i)->edad);
    }
}

void lista(persona vec[],int n,int x){
    int i;
    for(i=0;i<n;i++)
        if (vec[i].edad>x)
        printf("%s\n", (vec+i)->nombre);
}

float porcentaje(persona vec[],int n){
    int i;
    float cant=0;
    for(i=0;i<n;i++)
        if ((vec+i)->edad>17)
        cant+=1;
    return cant/n;
}
