#include <stdio.h>
int main(void)
{
int i, j, n, mat;
float cal, pro;
FILE *ar = fopen("arc9.txt", "r");
if (ar != NULL)
{
if (fscanf(ar, "%d", &n) != 1)
{
printf("Error al leer el archivo\n");
fclose(ar);
return 1;
}
for (i = 0; i < n; i++)
{
if (fscanf(ar, "%d", &mat) != 1)
{
printf("Error al leer la matrcula\n");
break;
}
printf("%d\t", mat);
pro = 0;
for (j = 0; j < 5; j++)
{
if (fscanf(ar, "%f", &cal) != 1)
{
printf("Error al leer la calificacin\n");
break;
}
pro += cal;
}
printf("%.2f\n", pro / 5);
}
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
                            