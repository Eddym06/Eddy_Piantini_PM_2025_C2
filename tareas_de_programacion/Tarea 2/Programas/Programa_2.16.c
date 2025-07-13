#include <stdio.h>
int main(void)
{
int cla, cat, ant, res;
printf("Ingrese la clave, categoria y antiguedad del trabajador: ");
if (scanf("%d %d %d", &cla, &cat, &ant) != 3)
{
printf("Entrada invalida\n");
return 1;
}
switch (cat)
{
case 3:
case 4:
if (ant >= 5)
res = 1;
else
res = 0;
break;
case 2:
if (ant >= 7)
res = 1;
else
res = 0;
break;
default:
res = 0;
break;
}
if (res)
printf("El trabajador con clave %d reune las condiciones para el puesto\n", cla);
else
printf("El trabajador con clave %d no reune las condiciones para el puesto\n", cla);
return 0;
}
            