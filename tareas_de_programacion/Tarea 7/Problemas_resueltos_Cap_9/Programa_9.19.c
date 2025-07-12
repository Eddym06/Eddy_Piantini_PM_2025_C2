#include <stdio.h>
typedef struct
{
int matricula;
char nombre[50];
int carrera;
float promedio;
} alumno;
void ordena(FILE *ar1, FILE *ar2);
int main(void)
{
FILE *ar1 = fopen("ad5.dat", "r");
FILE *ar2 = fopen("ad6.dat", "w");
if (ar1 != NULL && ar2 != NULL)
{
ordena(ar1, ar2);
fclose(ar1);
fclose(ar2);
}
else
printf("No se pueden abrir los archivos\n");
return 0;
}
void ordena(FILE *ar1, FILE *ar2)
{
alumno *alumnos;
int n = 0, i;
fseek(ar1, 0, SEEK_END);
n = ftell(ar1) / sizeof(alumno);
alumnos = (alumno *)malloc(n * sizeof(alumno));
if (!alumnos)
{
printf("Error de memoria\n");
return;
}
rewind(ar1);
for (i = 0; i < n; i++)
fread(&alumnos[i], sizeof(alumno), 1, ar1);
for (i = 0; i < n - 1; i++)
for (int j = i + 1; j < n; j++)
if (alumnos[i].matricula > alumnos[j].matricula)
{
alumno temp = alumnos[i];
alumnos[i] = alumnos[j];
alumnos[j] = temp;
}
for (i = 0; i < n; i++)
fwrite(&alumnos[i], sizeof(alumno), 1, ar2);
free(alumnos);
}
                        