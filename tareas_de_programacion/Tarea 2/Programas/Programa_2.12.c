#include <stdio.h>
#include <math.h>
int main(void)
{
int t, p, n;
printf("Ingrese los valores de T, P y N: ");
if (scanf("%d %d %d", &t, &p, &n) != 3)
{
printf("Entrada invalida\n");
return 1;
}
if (p != 0)
{
if (pow(t / p, n) == pow(t, n) / pow(p, n))
printf("Se cumple la igualdad\n");
else
printf("No se cumple la igualdad\n");
}
else
printf("P no puede ser cero\n");
return 0;
}
            