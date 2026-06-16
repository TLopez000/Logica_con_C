/*Corregir los errores en el siguiente programa, el cual incorpora en una lista ordenada de
números los elementos de un arreglo de N números ordenados, respetando el orden de la lista. */

#define N 2 // N es 4
...
void main(){
  int i, arr[N] = {4,8,9,60};
  TLISTA lista=NULL, pult=NULL, act, ant, nuevo;  //pult innecesario

  cargarLista(&lista);
  printf("\nLista Original\n");
  muestra(&lista);
  act = lista; //act=lista va dentro del for, para que encada iteracion se arranque la busqueda de insercion desde la cabecera
  ant = NULL; //ant innecesaria la inicializacion
  for(i=0; i<=N; i++) { //i<N

      while(act!=NULL && arr[i]<=act->n) { //arr[i]>act->n
          act = ant;  //ant = act;
          act = act.sig; //act = act->sig;
      }
      *nuevo = (TLISTA)malloc(sizeof(NODO)); //nuevo va sin *, ya es un puntero a lista
      nuevo->n = arr[i-1]; //arr[i]
      if(ant = NULL) { // (lista==NULL || lista->n>arr[i]) esto define si va en la cabecera
         nuevo->sig = lista;
         *lista = &nuevo;  //lista=nuevo
      }
      else {
        nuevo->sig = ant; // = act;
        ant->sig = &nuevo; //nuevo sin &
      }
      act = nuevo->sig; // sentencia no va, es igual a poner act=act
  }
  printf("\nLista Resultado\n");
  muestra(&lista);
}
