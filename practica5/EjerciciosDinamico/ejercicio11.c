 /*Simular una fila de empleados para usar un horno microondas en el comedor de una empresa.
Para cada empleado se tiene: su número de legajo, el momento de arribo (en segundos a partir
de las 12:00) y la cantidad de segundos que piensa usar el horno. El programa debe mostrar
para cada empleado el tiempo en que empieza y termina el uso del horno. Al finalizar mostrar
tiempo promedio de espera y legajo con mayor tiempo de espera. */

#include <stdio.h>
#include <stdlib.h>
#include "TDADinColas.h"

void cargacola(TCola *, int *);
void muestra(TCola *, int);

void main()
{
    TCola C;
    int cant=0;
    cargacola(&C,&cant);
    muestra(&C,cant);
}

void cargacola(TCola *C,int *cant){
    TElementoC x;
    FILE *arch;
    iniciaC(C);
    arch=fopen("texto11.txt","r");
    while (fscanf(arch,"%d %d %d", &(x.legajo), &(x.arribo), &(x.uso))==3){
        (*cant)+=1;
        poneC(C,x);
    }
    fclose(arch);
}

void muestra(TCola *C, int cant) {
    TElementoC x;
    int LegMax=0;
    float inicio,fin,fin_ant=0, TespMax=0,Tespera,TespSum=0;

    while (!vaciaC(*C)){
        sacaC(C,&x);
        if (x.arribo>fin_ant)       //el inicio de un empleado es cuando llega si llega despues de que termino el anterior, o si llega mientras lo usan su inicio es cuando termina el anterior
           inicio=x.arribo;
        else
           inicio=fin_ant;

        fin = inicio + x.uso;      //el fin sera desde que arranco hasta su tiempo de uso
        Tespera= inicio-x.arribo;  //lo que tuvo que esperar hasta empezar a usarlo
        TespSum+=Tespera;
        fin_ant=fin;       //guardo el fin del empleado para comparar con el siguiente

        if (Tespera>TespMax){
            LegMax=x.legajo;
            TespMax=Tespera;
        }
        printf("Empleado: %d Llegada: %d Inicio: %5.2f Tespera: %5.2f\n",x.legajo,x.arribo,inicio,Tespera);

    }

    printf("Empleado con mas tiempo de espera: %d Tiempo de espera promedio: %f", LegMax,(float)TespSum/cant);
}
