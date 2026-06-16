Corregir los errores de la siguiente función, que elimina el nodo de una lista circular que
contiene un valor pasado como parámetro (elem)

void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado) {
    TLISTAC ant, act = *pult->sig; //deberia inicializarse despues de verificar que pult!=NULL
    *eliminado = 0;
    if (pult = NULL) { //*pult != NULL
                       //inicia ant=*pult y act=(*pult)->sig
        do{
           ant = act;
           act = act->sig;
        }while ( *pult != act && elem < act.dato);  //act!=(*pult)->sig  && elem < act->dato  o (*act).dato (si el orden es descendente vale el < )
        if (elem == act->dato){
           if (*pult == (*pult)->sig)
              *pult = NULL;
           else {
                act->sig = ant->sig; // ant->sig = act->sig
                if (act == *pult)
                  *pult = ant;
           }
           free (act);
           *eliminado = 1;
        }
    }
}
