/*  El ranking de una asociación de tenistas es registrada en un archivo binario. Para cada jugador
se registra apellido y nombre, nacionalidad y puntaje. Realizar un subprograma que muestre los
datos del jugador ubicado en una posición recibida como parámetro.  */

#include <stdio.h>
#include <string.h>

typedef struct{
    char nombre[20];
    char nac[4];
    int pts;} jugador;

void crea();
void buscajug(int);

void main(){
    int x;
    //crea(); //comentar para no sobreescribir el archivo ya creado.
    printf("Ingrese posicion\n");
    scanf("%d",&x);
    buscajug(x);
}

void crea() {
    FILE *arch;
    arch=fopen("ranking.dat","wb");
    if (arch==NULL)
        printf("no se pudo crear el ranking");
    else {
        int continua,pos=1;
        jugador aux;

        printf("Desea cargar un jugador?(0 para finalizar)\n");
        scanf("%d",&continua);
        while (continua!=0) {
                printf("JUGADOR EN POSICION %d\n", pos++);
                printf("Nombre y apellido: \n");
                scanf("\n%[^\n]",aux.nombre);
                printf("Nacionalidad: \n");
                scanf("%s",aux.nac);
                printf("Puntaje: \n");
                scanf("%d", &aux.pts);
                fwrite(&aux,sizeof(jugador),1,arch);
                printf("Desea cargar el siguiente?\n");
                scanf("%d",&continua);
        }
        fclose(arch);
    }
}

void buscajug(int x) {
    FILE *arch;
    jugador aux;

    arch=fopen("ranking.dat","rb");
    if (arch==NULL)
        printf("error al abrir el ranking");
    else {
        fseek(arch,(x-1)*sizeof(jugador),SEEK_SET);
        fread(&aux,sizeof(jugador),1,arch);
        printf("NOMBRE: %s, NAC: %s, PUNTAJE: %d", aux.nombre,aux.nac,aux.pts);
    }
}
