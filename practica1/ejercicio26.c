/*26. Declarar un tipo struct para almacenar nombre, matrícula y promedio de un alumno.
Desarrollar una función que realice lectura de una variable del tipo creado. */

#include <stdio.h>

typedef struct{
    char nombre[20];
    int mtr;
    float prom;}RegAlu;

void leereg(RegAlu *);

void main(){
    RegAlu alumno;
    leereg(&alumno);
    printf("nombre: %s\n", alumno.nombre);
    printf("matricula: %d\n", alumno.mtr);
    printf("promedio: %2.3f\n", alumno.prom);
}

void leereg(RegAlu *a){
    printf("ingrese nombre: ");
    scanf("%s", a->nombre);
    printf("ingrese matricula: ");
    scanf("%d", &(a->mtr));
    printf("ingrese promedio: ");
    scanf("%f", &(a->prom));
}
