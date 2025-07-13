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
switch (op)
{
case 1:
res = t / 5.0;
break;
case 2:
res = pow(t, t);
break;
case 3:
case 4:
res = 3 * t;
break;
default:
res = 1;
break;
}
printf("Resultado: %.2f\n", res);
return 0;
}
            