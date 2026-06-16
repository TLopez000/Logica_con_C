/* Un sensor de temperatura realiza mediciones periódicas (una cada 5 seg.). Las mismas son
registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
temperatura promedio, máxima y mínima.  */

#include <stdio.h>
#include <stdlib.h>

void crea(char [],int*);
void lista(char [],int);

void main(){
    char nombre[]="arch29.dat";
    int cant;
    crea(nombre,&cant);
    lista(nombre,cant);
}

void crea(char nombre[],int *p){
    FILE *arch;
    float medicion;
    arch=fopen(nombre,"wb");
    if (arch==NULL)
        printf("no se pudo crear el archivo");
    else {
        *p=0;
        printf("Medicion nro %d: \n", *p + 1);
        scanf("%f",&medicion);
        while (medicion!=0) {
            fwrite(&medicion,sizeof(float),1,arch);
            *p+=1;
            printf("Medicion nro %d: \n", *p + 1);
            scanf("%f",&medicion);
        }
        fclose(arch);
    }
}

void lista(char nombre[],int cant){
    FILE *arch;
    arch=fopen(nombre,"rb");
    if (arch==NULL)
        printf("el archivo no existe");
    else{
        float medicion,acum=0,max=0,min=999;
        printf("CANTIDAD TOTAL DE MEDICIONES: %d\n", cant);
        while(fread(&medicion,sizeof(float),1,arch)==1){
            max=(medicion>max)? medicion:max;
            min=(medicion<min)? medicion:min;
            acum+=medicion;
        }
        fclose(arch);
        printf("Temperatura promedio: %f\n", acum/cant);
        printf("Maxima: %f\n", max);
        printf("Minima: %f", min);
    }
}

