/* Simular un gestor de archivos simplificado mediante listas de carpetas que contengan sublistas
de carpetas y archivos. Implementar el listado del contenido de una carpeta ingresada como
dato. No es necesario listar el contenido de las subcarpetas de dicha carpeta. */

typedef struct noditoa {
    char archivo[10];
    struct noditoa *sig;}noditoa;
typedef noditoa *sublistaarch;

typedef struct noditoc {
    char carpeta[10];
    struct noditoc *sig;}noditoc;
typedef noditoc *sublistacarp;

typedef struct nodo {
    char carpeta[10];
    struct nodo *sig;
    sublistaarch suba;
    sublistacarp subc;} nodo;
typedef nodo *Tlista;

void listado (Tlista L, char carpeta[10]){
    sublistaarch actsuba;
    sublistacarp actsubc;
    if (L!=NULL){
            //busco carpeta principal
        while (L!=NULL && strcmp(carpeta,L->carpeta)!=0)
            L=L->sig;
        if (L!=NULL) {
            //listado de archivos
            actsuba=L->suba;
            while (actsuba!=NULL){
                printf("%s\n", actsuba->archivo);
                actsuba=actsuba->sig;
            }
            //listado de subcarpetas
            actsubc=L->subc;
            while (actsubc!=NULL){
                printf("%s\n", actsubc->carpeta);
                actsubc=actsubc->sig;
            }
        }
    }
}
