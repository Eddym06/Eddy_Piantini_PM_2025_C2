#include <stdio.h>
#include <stdlib.h>
void sumypro(FILE *);
void main(void)
{
FILE *ap;
ap = fopen("arc2.txt", "r");
if (ap != NULL)
{
sumypro(ap);
fclose(ap);
}
else
printf("No se puede abrir el archivo\n");
}
void sumypro(FILE *ap1)
{
char cad[30];
float sum = 0.0;
int i = 0;
while (!feof(ap1))
{
if (fgets(cad, 30, ap1) != NULL)
{
sum += atof(cad);
i++;
}
}
if (i > 0)
printf("Suma: %.2f\nPromedio: %.2f\n", sum, sum / i);
else
printf("No se encontraron numeros validos\n");
}
                    