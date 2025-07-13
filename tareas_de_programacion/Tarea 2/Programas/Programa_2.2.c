#include <stdio.h>
int main(void)
{
float pre, npr;
printf("Ingrese el precio del producto: ");
if (scanf("%f", &pre) != 1)
{
printf("Entrada invalida\n");
return 1;
}
if (pre > 1500)
{
npr = pre * 1.11;
printf("Nuevo precio: %.2f\n", npr);
}
else
printf("Precio sin cambio: %.2f\n", pre);
return 0;
}
            