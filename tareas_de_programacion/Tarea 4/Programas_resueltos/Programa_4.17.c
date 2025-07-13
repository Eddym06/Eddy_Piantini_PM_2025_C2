#include <stdio.h>
void Mayor(float, float, float);
int main(void)
{
int I;
float GOL, PAC, CAR, AGOL = 0, APAC = 0, ACAR = 0;
for (I = 1; I <= 12; I++)
{
printf("\n\nIngresa las lluvias del mes %d", I);
printf("\nRegiones Golfo, Pacifico y Caribe: ");
if (scanf("%f %f %f", &GOL, &PAC, &CAR) != 3 || GOL < 0 || PAC < 0 || CAR < 0)
{
printf("Entrada invalida\n");
return 1;
}
AGOL += GOL;
APAC += PAC;
ACAR += CAR;
}
printf("\n\nPromedio de lluvias Region Golfo: %.2f", AGOL / 12);
printf("\nPromedio de lluvias Region Pacifico: %.2f", APAC / 12);
printf("\nPromedio de lluvias Region Caribe: %.2f", ACAR / 12);
Mayor(AGOL / 12, APAC / 12, ACAR / 12);
return 0;
}
void Mayor(float R1, float R2, float R3)
{
if (R1 > R2)
if (R1 > R3)
printf("\n\nRegion con mayor promedio: Golfo. Promedio: %.2f", R1);
else
printf("\n\nRegion con mayor promedio: Caribe. Promedio: %.2f", R3);
else if (R2 > R3)
printf("\n\nRegion con mayor promedio: Pacifico. Promedio: %.2f", R2);
else
printf("\n\nRegion con mayor promedio: Caribe. Promedio: %.2f", R3);
}
                