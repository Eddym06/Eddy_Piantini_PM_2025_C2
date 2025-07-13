#include <stdio.h>
typedef struct
{
int matricula;
char nombre[18];
int carrera;
float promedio;
} alumno;
void lee(FILE *);
void main(void)
{
FILE *ar;
ar = fopen("ad1.dat", "r");
if (ar != NULL)
{
lee(ar);
fclose(ar);
}
else
printf("El archivo no se puede abrir\n");
}
void lee(FILE *ap)
{
alumno alu;
while (fread(&alu, sizeof(alumno), 1, ap))
{
printf("Matricula: %d\tCarrera: %d\tPromedio: %.2f\t%s\n", alu.matricula, alu.carrera, alu.promedio, alu.nombre);
}
}
                    