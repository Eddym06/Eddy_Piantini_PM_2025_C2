#include <stdio.h>
void mezcla(FILE *ar, FILE *ar1, FILE *ar2);
int main(void)
{
FILE *ar = fopen("arc9.dat", "r");
FILE *ar1 = fopen("arc10.dat", "r");
FILE *ar2 = fopen("arc11.dat", "w");
if (ar != NULL && ar1 != NULL && ar2 != NULL)
{
mezcla(ar, ar1, ar2);
fclose(ar);
fclose(ar1);
fclose(ar2);
}
else
printf("No se pueden abrir los archivos\n");
return 0;
}
void mezcla(FILE *ar, FILE *ar1, FILE *ar2)
{
int mat, mat1, i, b = 1, b1 = 1;
float ca[3], ca1[3];
while ((b || !feof(ar)) && (b1 || !feof(ar1)))
{
if (b)
{
if (fscanf(ar, "%d", &mat) != 1)
{
b = 0;
continue;
}
for (i = 0; i < 3; i++)
if (fscanf(ar, "%f", &ca[i]) != 1)
break;
b = 0;
}
if (b1)
{
if (fscanf(ar1, "%d", &mat1) != 1)
{
b1 = 0;
continue;
}
for (i = 0; i < 3; i++)
if (fscanf(ar1, "%f", &ca1[i]) != 1)
break;
b1 = 0;
}
if (!b && !b1)
break;
if (b && (!b1 || mat < mat1))
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
while (!feof(ar))
{
if (fscanf(ar, "%d", &mat) != 1)
break;
fprintf(ar2, "%d\t", mat);
for (i = 0; i < 3; i++)
{
if (fscanf(ar, "%f", &ca[i]) != 1)
break;
fprintf(ar2, "%.2f\t", ca[i]);
}
fputs("\n", ar2);
}
while (!feof(ar1))
{
if (fscanf(ar1, "%d", &mat1) != 1)
break;
fprintf(ar2, "%d\t", mat1);
for (i = 0; i < 3; i++)
{
if (fscanf(ar1, "%f", &ca1[i]) != 1)
break;
fprintf(ar2, "%.2f\t", ca1[i]);
}
fputs("\n", ar2);
}
}
                                                        