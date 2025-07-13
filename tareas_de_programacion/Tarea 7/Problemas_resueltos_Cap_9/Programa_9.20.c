#include <stdio.h>
typedef struct
{
char materia[18];
int calificacion;
} matcal;
typedef struct
{
int matricula;
char nombre[18];
matcal cal[5];
} alumno;
void F1(FILE *);
void F2(FILE *);
float F3(FILE *);
void main(void)
{
float pro;
FILE *ap;
ap = fopen("esc.dat", "r");
if (ap != NULL)
{
F1(ap);
F2(ap);
pro = F3(ap);
printf("PROMEDIO GENERAL MATERIA 4: %.2f\n", pro);
fclose(ap);
}
else
printf("El archivo no se puede abrir\n");
}
void F1(FILE *ap)
{
alumno alu;
int j;
float sum, pro;
rewind(ap);
while (fread(&alu, sizeof(alumno), 1, ap))
{
printf("Matricula: %d\t", alu.matricula);
sum = 0.0;
for (j = 0; j < 5; j++)
sum += alu.cal[j].calificacion;
pro = sum / 5;
printf("Promedio: %.2f\n", pro);
}
}
void F2(FILE *ap)
{
alumno alu;
rewind(ap);
printf("ALUMNOS CON CALIFICACION > 9 EN MATERIA 3\n");
while (fread(&alu, sizeof(alumno), 1, ap))
{
if (alu.cal[2].calificacion > 9)
printf("Matricula del alumno: %d\n", alu.matricula);
}
}
float F3(FILE *ap)
{
alumno alu;
int i = 0;
float sum = 0;
rewind(ap);
while (fread(&alu, sizeof(alumno), 1, ap))
{
i++;
sum += alu.cal[3].calificacion;
}
return i > 0 ? sum / i : 0;
}
                                        