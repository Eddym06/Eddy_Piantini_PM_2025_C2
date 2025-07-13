#include <stdio.h>
int main(void)
{
int tra, eda, dia;
float cos;
printf("Ingrese tipo de tratamiento, edad y dias: ");
if (scanf("%d %d %d", &tra, &eda, &dia) != 3)
{
printf("Entrada invalida\n");
return 1;
}
switch (tra)
{
case 1:
cos = dia * 2800;
break;
case 2:
cos = dia * 1950;
break;
case 3:
cos = dia * 2500;
break;
case 4:
cos = dia * 1150;
break;
default:
cos = -1;
break;
}
if (cos != -1)
{
if (eda >= 60)
cos *= 0.75;
else if (eda <= 25)
cos *= 0.85;
printf("Clave tratamiento: %d Dias: %d Costo total: %.2f\n", tra, dia, cos);
}
else
printf("La clave del tratamiento es incorrecta\n");
return 0;
}
                