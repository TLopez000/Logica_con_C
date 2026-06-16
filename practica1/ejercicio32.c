/* En un archivo binario se registran temperaturas diarias máxima y mínima para algunas ciudades
del país en un mes determinado. Cada registro tiene los siguientes campos: ciudad (cadena de
20, archivo ordenado por este campo), día del mes (1..30), temperatura máxima (float),
temperatura mínima (float). Listar para cada ciudad sus temperaturas máximas y mínimas en el
mes; y al final del listado la ciudad que tuvo la menor temperatura en el mes, indicando el día.  */

#include <stdio.h>
#include <string.h>

typedef struct{
    char ciudad[21]; //clave primaria
    short int dia;
    float tmax;
    float tmin;}reg;

int main(){
    reg aux;
    char ciudadmin[21],ciudadact[21];
    short int diamin,diamintot;
    float min,mintot=999,max;

    FILE *arch;
    arch=fopen("ciudades.dat","rb");
    if (arch==NULL)
        printf("no se pudo abrir el archivo");
    else {
        printf("CIUDAD    TEMP MAX    TEMP MIN\n");
        fread(&aux,sizeof(reg),1,arch);
        while (!feof(arch)) {
            strcpy(ciudadact,aux.ciudad);
            min=999;
            max=-999;
            while (strcmp(ciudadact,aux.ciudad)==0) {
                    if(aux.tmin<min){
                        min=aux.tmin;
                        diamin=aux.dia;
                    }
                    max=(aux.tmax>max)? aux.tmax:max;
                    fread(&aux,sizeof(reg),1,arch);
            }                                              //sale del while cuando cambia de ciudad
            printf("%s   %f    %f\n", ciudadact,max,min);
            if (min<mintot){
                mintot=min;
                diamintot=diamin;
                strcpy(ciudadmin,ciudadact);
            }
        }
        printf("CIUDAD MIN: %s - DIA: %d - TEMP: %f", ciudadmin, diamintot, mintot);
        fclose(arch);
    }
}
