#include <stdio.h>
#include <math.h>
int main(void)
{
int op, t;
float res;
printf("Ingrese la opcion de calculo y el valor entero: ");
if (scanf("%d %d", &op, &t) != 2)
{
printf("Entrada invalida\n");
return 1;
}
if (op == 1)
{
res = t / 5.0;
}
else if (op == 2)
{
res = pow(t, t);
}
else if (op == 3 || op == 4)
{
res = 3 * t;
}
else
{
res = 1;
}
printf("Resultado: %.2f\n", res);
return 0;
}
                        