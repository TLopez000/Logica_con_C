/* Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo (ANU7: alfanumérico de 7 caracteres), velocidad
registrada (entero positivo), velocidad máxima permitida (entero positivo), fecha y hora de la
medición (ANU16, formato aaaa/mm/dd hh:nn). Cada dato está separado por un espacio. El
programa debe generar un archivo binario con los registros donde la velocidad registrada
supere en más de un 20% a la velocidad máxima. Cada registro del archivo binario contiene los
mismos datos que el archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones
procesadas y la cantidad de registros generados en el archivo binario. */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char pat[8];
    int velreg;
    int velmax;
    char fecha[17];
    } vehiculo;

void lee(char []);

void main(){
    char vigia[]="vigia.txt";
    lee(vigia);
}

void lee(char nombre[]) {
    FILE *archT;
    FILE *archBin;
    vehiculo aux;
    int cant=0;

    archT=fopen(nombre,"rt");
    if (archT==NULL)
        printf("el archivo vigia no existe");
    else {
        archBin=fopen("multados.dat","wb");
        if (archBin==NULL)
            printf("no se puede crear el archivo de multados");
        else {
              printf("PATENTE   FECHA\n");
              while (fscanf(archT,"%s %d %d %[^\n]", aux.pat, &aux.velreg, &aux.velmax, aux.fecha)==4)
                   if (aux.velreg>aux.velmax*1.2) {
                      fwrite(&aux,sizeof(vehiculo),1,archBin);
                      cant++;
                      printf("%s %s\n",aux.pat,aux.fecha);
                   }
             fclose(archT);
             fclose(archBin);
             printf("Cantidad de multados: %d",cant);
        }
    }
}



