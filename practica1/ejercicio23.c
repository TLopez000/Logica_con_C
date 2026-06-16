/* 23. Corregir el siguiente código para que asigne el contenido de la cadena cad1 a cad3, solamente
si cad1 y cad2 son distintas.
char cad1[20], cad2[20], cad3[20];
gets(cad1);
gets(cad2);
if(cad1 != cad2)
cad3 = cad1; */

if (strcmp(cad1,cad2)!=0) //strcmp devuelve 0 si cad1=cad2, se puede evitar poner !=0 pues 0 en C es falso. Si son iguales el if no se ejecuta.
    strcpy(cad3,cad1);
