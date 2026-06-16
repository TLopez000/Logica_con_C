#include <stdio.h>
#include <stdlib.h>
typedef char TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e){
     *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}


///////////////////////// EJERCICIOS ///////////////////////////////////////

//19
int cantArbolesBosque(arbol a){ //debo pasar la raiz del binario transformado
    int i=0;
    while (a!=NULL){
        i++;
        a=a->der;
    }
    return i;
}

int profundidad(arbol a){
    int izq, der;
    if (a==NULL)
        return 0;
    else{
        izq = 1+profundidad(a->izq);
        der = profundidad(a->der);

        if (izq>der)
            return izq;
        else
            return der;
    }
}

void profundidadCadaArbol(arbol a){
    int i=0,prof;
    printf("ARBOL  PROFUNDIDAD\n");
    while (a!=NULL) {
        i++;
        if (a->izq==NULL) //arbol de una hoja
            prof=1;
        else
            prof=profundidad(a->izq)+1;
        printf("%c          %d\n", a->dato, prof);
        a=a->der;
    }
}

/* 21) Dado un árbol binario que proviene de la transformación de un bosque,
a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada). */

//INCISO A
int cantArbolesK(arbol a,int k){
    int alt,cant=0;
    while (a!=NULL) {
        if (a->izq==NULL)
            alt=0;
        else
            alt=profundidad(a->izq); //no sumo 1 porque la altura es 0 en la raiz
        if (alt>=k)
            cant++;

        a=a->der;
    }
    return cant;
}

//INCISO B
char clavemayor(arbol a){
    char izq,der,max;
    if (a!=NULL){
        izq = clavemayor(a->izq);
        der = clavemayor(a->der);

        max=a->dato;

        if(izq>max)
            max=izq;
        if(der>max)
           max=der;

        return max;
    }
    else
        return 0; //a es un minimo en ascii
}

void generavec(arbol a, int* dimv,char vec[]){
    char max;
    while (a!=NULL){

        //si es un arbol de una hoja
        if (a->izq==NULL)
            vec[++(*dimv)]=a->dato;
        //si no es de una hoja, calculo su maximo
        else {
            max = clavemayor(a->izq);
            //al meterme por izq para no invadir los otros arboles, debo comparar con la raiz
            if (max > a->dato)
               vec[++(*dimv)] = max;
            else
               vec[++(*dimv)] = a->dato;
        }
        a=a->der;
    }

    int i;
    printf("CLAVES MAXIMAS: ");
    for(i=0;i<=*dimv;i++)
        printf("%c ", vec[i]);
    printf("\n");
}

//INCISO C
int grado_nodo(arbol a){
    int i=0;
    while(a!=NULL){
        i++;
        a = a->der;
    }
    return i;
}

int cumple_arbol(arbol a, int k){
    int grado;
    if (a!=NULL){

        grado = grado_nodo(a->izq);

        if (grado>=k)
            return 1;
        else
            return cumple_arbol(a->izq,k) || cumple_arbol(a->der,k);
    }
    else
        return 0;
}

void recorre_bosque(arbol a, int k) {
    int grado_raiz,cumple;

    printf("ARBOL  CUMPLE\n");
    while (a!=NULL){
        cumple=0;
        if (a->izq!=NULL){
            grado_raiz = grado_nodo(a->izq);
            cumple = cumple_arbol(a->izq,k);
        }
        else
            grado_raiz = 0;

        printf("  %c", a->dato);
        if (grado_raiz>=k || cumple)
            printf("     SI\n");
        else
            printf("     NO\n");

        a=a->der;
    }
}


void main(){
 arbol a;
 char vec[100];
 int dimv=-1;

 //arbol del ejercicio 18
 addnodo(&a, 'A');
 addnodo(&a->der, 'B');
 addnodo(&a->der->der, 'L');
 addnodo(&a->der->izq, 'C');
 addnodo(&a->der->izq->der, 'D');
 addnodo(&a->der->izq->der->izq, 'E');
 addnodo(&a->der->izq->der->izq->der, 'F');
 addnodo(&a->der->izq->der->izq->der->der, 'G');
 addnodo(&a->der->izq->der->izq->der->der->der, 'H');
 addnodo(&a->der->izq->der->izq->der->izq, 'I');
 addnodo(&a->der->izq->der->izq->der->izq->der, 'J');
 addnodo(&a->der->izq->der->izq->der->izq->der->der, 'K');

 addnodo(&a->der->der->izq, 'M');
 addnodo(&a->der->der->izq->der, 'N');
 addnodo(&a->der->der->izq->der->izq, 'O');

 printf("cantidad de arboles que conformaban el bosque: %d\n", cantArbolesBosque(a));
 printf("profundidad maxima del bosque: %d\n", profundidad(a));
 profundidadCadaArbol(a);

 printf("cantidad de arboles con altura mayor o igual a K: %d\n", cantArbolesK(a,1));

 generavec(a,&dimv,vec);

 recorre_bosque(a,2);

}
