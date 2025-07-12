#include <stdio.h>
int main(void)
{
int i, j, n, mat;
float cal;
printf("Ingrese el nmero de alumnos: ");
if (scanf("%d", &n) != 1 || n < 1 || n > 35)
{
printf("Entrada invlida\n");
return 1;
}
FILE *ar = fopen("arc8.txt", "w");
if (ar != NULL)
{
fprintf(ar, "%d ", n);
for (i = 0; i < n; i++)
{
printf("Ingrese la matrcula del alumno %d: ", i + 1);
if (scanf("%d", &mat) != 1)
{
printf("Entrada invlida\n");
fclose(ar);
return 1;
}
fprintf(ar, "\n%d ", mat);
for (j = 0; j < 5; j++)
{
printf("Calificacin %d: ", j + 1);
if (scanf("%f", &cal) != 1)
{
printf("Entrada invlida\n");
fclose(ar);
return 1;
}
fprintf(ar, "%.2f ", cal);
}
}
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
                            