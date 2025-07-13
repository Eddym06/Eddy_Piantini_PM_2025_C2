#include <stdio.h>
void mezcla(FILE *, FILE *, FILE *);
void main(void)
{
FILE *ar, *ar1, *ar2;
ar = fopen("arc9.dat", "r");
ar1 = fopen("arc10.dat", "r");
ar2 = fopen("arc11.dat", "w");
if (ar != NULL && ar1 != NULL && ar2 != NULL)
{
mezcla(ar, ar1, ar2);
fclose(ar);
fclose(ar1);
fclose(ar2);
}
else
printf("No se pueden abrir los archivos\n");
}
void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
int i, mat, mat1, b = 1, b1 = 1;
float ca[3], ca1[3];
while ((b || !feof(ar)) && (b1 || !feof(ar1)))
{
if (b)
{
if (!feof(ar))
{
fscanf(ar, "%d", &mat);
for (i = 0; i < 3; i++)
fscanf(ar, "%f", &ca[i]);
b = 0;
}
else
mat = 9999999;
}
if (b1)
{
if (!feof(ar1))
{
fscanf(ar1, "%d", &mat1);
for (i = 0; i < 3; i++)
fscanf(ar1, "%f", &ca1[i]);
b1 = 0;
}
else
mat1 = 9999999;
}
if (mat < mat1)
{
fprintf(ar2, "%d\t", mat);
for (i = 0; i < 3; i++)
fprintf(ar2, "%.2f\t", ca[i]);
fputs("\n", ar2);
b = 1;
}
else
{
fprintf(ar2, "%d\t", mat1);
for (i = 0; i < 3; i++)
fprintf(ar2, "%.2f\t", ca1[i]);
fputs("\n", ar2);
b1 = 1;
}
}
}
                                        