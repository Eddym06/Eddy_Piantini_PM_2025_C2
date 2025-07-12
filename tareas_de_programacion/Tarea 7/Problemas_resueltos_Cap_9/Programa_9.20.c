#include <stdio.h>
typedef struct
{
char materia[50];
int calificacion;
} matcal;
typedef struct
{
int matricula;
char nombre[50];
matcal cal[5];
} alumno;
void F1(FILE *ar);
void F2(FILE *ar);
float F3(FILE *ar);
int main(void)
{
float pro;
FILE *ar = fopen("esc.dat", "r");
if (ar != NULL)
{
F1(ar);
F2(ar);
pro = F3(ar);
printf("\nPROMEDIO GENERAL MATERIA 4: %.2f\n", pro);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void F1(FILE *ar)
{
alumno alu;
int j;
float sum, pro;
printf("MATRCULA y PROMEDIOS\n");
rewind(ar);
while (fread(&alu, sizeof(alumno), 1, ar))
{
printf("Matrcula: %d", alu.matricula);
sum = 0.0;
for (j = 0; j < 5; j++)
sum += alu.cal[j].calificacion;
pro = sum / 5;
printf("\tPromedio: %.2f\n", pro);
}
}
void F2(FILE *ar)
{
alumno alu;
printf("\nALUMNOS CON CALIFICACIN > 9 EN MATERIA 3\n");
rewind(ar);
while (fread(&alu, sizeof(alumno), 1, ar))
{
if (alu.cal[2].calificacion > 9)
printf("Matrcula del alumno: %d\n", alu.matricula);
}
}
float F3(FILE *ar)
{
alumno alu;
int i = 0;
float sum = 0;
rewind(ar);
while (fread(&alu, sizeof(alumno), 1, ar))
{
i++;
sum += alu.cal[3].calificacion;
}
return i > 0 ? sum / i : 0;
}
                                        