#include <stdio.h>
#include <string.h>

int main() {
  int *p, a = 4, b = 5;
   p = &b;
   *p *= 2;
   printf("b=%d *p=%d\n", b, *p); //b=10 *p=10
   printf("&b=%p p=%p &p=%p\n", &b, p, &p); //&b=direccion b p=direccion b &p=direccion del puntero p

   b = *p *3;
   printf("b=%d *p=%d\n", b, *p); //b=30 *p=30
   printf("&b=%p p=%p\n", &b, p); //&b=direccion b p=direccion b

   a = b;
   p = &a;
   (*p)++;
   printf("b=%d a=%d *p=%d\n", b, a, *p); //b=30 a=31 *p=31
   printf("&b=%p &a=%p p=%p &p=%p\n", &b, &a, p, &p); //&b=direccion b &a=Direccion a p=direccion a &p=direccion puntero p
return 0;
}
