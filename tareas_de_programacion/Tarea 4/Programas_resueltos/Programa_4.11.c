#include <stdio.h>
int mad(int);
int main(void)
{
int NUM, RES;
printf("\nIngresa el numero: ");
if (scanf("%d", &NUM) != 1 || NUM <= 0)
{
printf("El numero debe ser positivo\n");
return 1;
}
RES = mad(NUM);
printf("\nEl mayor divisor de %d es: %d", NUM, RES);
return 0;
}
int mad(int N1)
{
int I;
for (I = N1 / 2; I >= 1; I--)
if (N1 % I == 0)
return I;
return 1;
}
            