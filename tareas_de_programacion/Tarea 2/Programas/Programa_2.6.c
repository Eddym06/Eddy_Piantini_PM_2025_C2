#include <stdio.h>
int main(void)
{
float sal;
int niv;
printf("Ingrese el nivel del profesor: ");
if (scanf("%d", &niv) != 1)
{
printf("Entrada invalida\n");
return 1;
}
printf("Ingrese el salario: ");
if (scanf("%f", &sal) != 1)
{
printf("Entrada invalida\n");
return 1;
}
switch (niv)
{
case 1:
sal *= 1.0035;
break;
case 2:
sal *= 1.0041;
break;
case 3:
sal *= 1.0048;
break;
case 4:
sal *= 1.0053;
break;
default:
printf("Nivel invalido\n");
return 1;
}
printf("Nivel: %d \tSalario: %.2f\n", niv, sal);
return 0;
}
                