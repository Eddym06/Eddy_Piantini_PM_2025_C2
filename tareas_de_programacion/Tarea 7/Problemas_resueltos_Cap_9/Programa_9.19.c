#include <stdio.h>
typedef struct
{
int matricula;
char nombre[18];
int carrera;
float promedio;
} alumno;
void ordena(FILE *, FILE *);
void main(void)
{
FILE *ar1, *ar2;
ar1 = fopen("ad5.dat", "r");
ar2 = fopen("ad6.dat", "w");
if (ar1 != NULL && ar2 != NULL)
{
ordena(ar1, ar2);
fclose(ar1);
fclose(ar2);
}
else
printf("El o los archivos no se pudieron abrir\n");
}
void ordena(FILE *ap1, FILE *ap2)
{
alumno alu;
int t, n, i;
t = sizeof(alumno);
fseek(ap1, 0, SEEK_END);
n = ftell(ap1) / t;
rewind(ap1);
for (i = n - 1; i >= 0; i--)
{
fseek(ap1, i * t, SEEK_SET);
fread(&alu, t, 1, ap1);
fwrite(&alu, t, 1, ap2);
}
}
                    