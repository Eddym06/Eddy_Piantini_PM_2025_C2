#include <stdio.h>
void modificar(int *);
int main(void)
{
int i, valor = 4;
for (i = 1; i <= 3; i++)
{
printf("Valor antes de la funcion: %d\n", ++valor);
modificar(&valor);
printf("Valor despues de la funcion: %d\n", valor);
}
return 0;
}
void modificar(int *num)
{
*num += *num;
}
            