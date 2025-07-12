#include <stdio.h>
typedef struct
{
int matricula;
char nombre[50];
int carrera;
float promedio;
} alumno;
void lee(FILE *ar);
int main(void)
{
FILE *ar = fopen("ad1.dat", "r");
if (ar != NULL)
{
lee(ar);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void lee(FILE *ar)
{
alumno alu;
while (fread(&alu, sizeof(alumno), 1, ar))
{
printf("Matrcula: %d\tCarrera: %d\tPromedio: %.2f\tNombre: %s\n",
alu.matricula, alu.carrera, alu.promedio, alu.nombre);
}
}
                        