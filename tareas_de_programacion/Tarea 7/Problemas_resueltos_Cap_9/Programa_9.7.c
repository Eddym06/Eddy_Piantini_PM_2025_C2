#include <stdio.h>
void promedio(FILE *ar);
int main(void)
{
FILE *ar = fopen("arc9.txt", "r");
if (ar != NULL)
{
promedio(ar);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void promedio(FILE *ar)
{
int i, j, n, mat;
float pro, cal;
if (fscanf(ar, "%d", &n) != 1)
{
printf("Error al leer el archivo\n");
return;
}
for (i = 0; i < n; i++)
{
if (fscanf(ar, "%d", &mat) != 1)
{
printf("Error al leer la matrcula\n");
return;
}
printf("%d\t", mat);
pro = 0;
for (j = 0; j < 5; j++)
{
if (fscanf(ar, "%f", &cal) != 1)
{
printf("Error al leer la calificacin\n");
return;
}
pro += cal;
}
printf("%.2f\n", pro / 5);
}
}
                                