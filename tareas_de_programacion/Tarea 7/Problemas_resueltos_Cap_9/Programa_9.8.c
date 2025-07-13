#include <stdio.h>
typedef struct
{
int matricula;
char nombre[18];
int carrera;
float promedio;
} alumno;
void escribe(FILE *);
void main(void)
{
FILE *ar;
ar = fopen("ad1.dat", "w");
if (ar != NULL)
{
escribe(ar);
fclose(ar);
}
else
printf("El archivo no se puede abrir\n");
}
void escribe(FILE *ap)
{
alumno alu;
int i = 0, r;
printf("Desea ingresar informacion sobre alumnos? (Si-1 No-0): ");
scanf("%d", &r);
while (r)
{
i++;
printf("Matricula del alumno %d: ", i);
scanf("%d", &alu.matricula);
while (getchar() != '\n');
printf("Nombre del alumno %d: ", i);
fgets(alu.nombre, 18, stdin);
printf("Carrera del alumno %d: ", i);
scanf("%d", &alu.carrera);
printf("Promedio del alumno %d: ", i);
scanf("%f", &alu.promedio);
fwrite(&alu, sizeof(alumno), 1, ap);
printf("Desea ingresar mas informacion sobre alumnos? (Si-1 No-0): ");
scanf("%d", &r);
}
}
                    