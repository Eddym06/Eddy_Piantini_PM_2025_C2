#include <stdio.h>
int duplicar(int);
int main(void)
{
int i, valor = 4;
for (i = 1; i <= 3; i++)
{
printf("Valor antes de la funcion: %d\n", ++valor);
printf("Valor despues de la funcion: %d\n", duplicar(valor));
}
return 0;
}
int duplicar(int num)
{
return num + num;
}
            