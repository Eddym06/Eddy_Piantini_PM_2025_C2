#include <stdio.h>
#include <stdlib.h>
void sumypro(FILE *ar);
int main(void)
{
FILE *ar = fopen("arc2.txt", "r");
if (ar != NULL)
{
sumypro(ar);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void sumypro(FILE *ar)
{
char cad[50];
float sum = 0.0;
int i = 0;
while (fgets(cad, sizeof(cad), ar) != NULL)
{
if (cad[0] >= '0' && cad[0] <= '9' || cad[0] == '-' || cad[0] == '+')
{
sum += atof(cad);
i++;
}
}
printf("Suma de los nmeros reales: %.2f\n", sum);
if (i > 0)
printf("Promedio de los nmeros reales: %.2f\n", sum / i);
else
printf("No se encontraron nmeros para promediar\n");
}
                    