#include <stdio.h>
typedef struct
{
int matricula;
char nombre[50];
int carrera;
float promedio;
} alumno;
void escribe(FILE *ar);
int main(void)
{
FILE *ar = fopen("ad1.dat", "w");
if (ar != NULL)
{
escribe(ar);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void escribe(FILE *ar)
{
alumno alu;
int i = 0, r;
printf("Desea ingresar informacin de alumnos? (S-1 No-0): ");
if (scanf("%d", &r) != 1)
{
printf("Entrada invlida\n");
return;
}
while (r)
{
i++;
printf("Matrcula del alumno %d: ", i);
if (scanf("%d", &alu.matricula) != 1)
{
printf("Entrada invlida\n");
return;
}
while (getchar() != '\n');
printf("Nombre del alumno %d: ", i);
if (fgets(alu.nombre, sizeof(alu.nombre), stdin) == NULL)
{
printf("Error al leer el nombre\n");
return;
}
alu.nombre[strcspn(alu.nombre, "\n")] = '\0';
printf("Carrera del alumno %d: ", i);
if (scanf("%d", &alu.carrera) != 1)
{
printf("Entrada invlida\n");
return;
}
printf("Promedio del alumno %d: ", i);
if (scanf("%f", &alu.promedio) != 1)
{
printf("Entrada invlida\n");
return;
}
fwrite(&alu, sizeof(alumno), 1, ar);
printf("Desea ingresar ms alumnos? (S-1 No-0): ");
if (scanf("%d", &r) != 1)
{
printf("Entrada invlida\n");
return;
}
}
}
                                            