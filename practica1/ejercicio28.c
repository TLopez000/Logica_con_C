/* 12. Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0.
28. Rehacer el ejercicio 12 suponiendo que los números se encuentran en un archivo de texto,
todos en la misma línea. ¿Como modificaría la lectura, si hubiera un valor por línea? */

//no cambia en nada si estan en diferentes lineas, el fscanf ignorara saltos de linea y espacios

#include <stdio.h>
#include <stdlib.h>

void suma();

void main(){
    suma();
}

void suma(){
    FILE *arch;
    arch=fopen("arch5.txt","r");
    if (arch==NULL)
        printf("El archivo no existe");
    else {
        int n,acum=0;
        while (fscanf(arch,"%d",&n)==1 && n!=0)
          acum+=n;
        printf("la suma da: %d", acum);
    }

}
