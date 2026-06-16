
Corregir los errores en la siguiente función void, la cual genera un arreglo de caracteres con los
nodos de grado 2 de un árbol binario.

void arrgrado2(arbol a, char v[N], int *dimv) {
  if (a != NULL) {
    if(a->izq != NULL && a->der != NULL) /* grado 2 */
       v[++(*dimv)] = a->dato;
    arrgrado2(a->izq, v, dimv);
    arrgrado2(a->der, v, dimv);
  }
}
