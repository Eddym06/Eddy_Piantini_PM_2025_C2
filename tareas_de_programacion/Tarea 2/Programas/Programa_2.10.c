#include <stdio.h>
#include <math.h>
int main(void)
{
int num;
printf("Ingrese el numero: ");
if (scanf("%d", &num) != 1)
{
printf("Entrada invalida\n");
return 1;
}
if (num == 0)
printf("Nulo\n");
else if (pow(-1, num) > 0)
printf("Par\n");
else
printf("Impar\n");
return 0;
}
        