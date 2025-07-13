#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct alumno
{
int matricula;
char nombre[50];
char carrera[50];
float promedio;
char direccion[50];
};
void Lectura(struct alumno *a)
{
printf("\nIngrese la matricula del alumno: ");
scanf("%d", &a->matricula);
fflush(stdin);
printf("Ingrese el nombre del alumno: ");
fgets(a->nombre, 50, stdin);
a->nombre[strcspn(a->nombre, "\n")] = 0;
printf("Ingrese la carrera del alumno: ");
fgets(a->carrera, 50, stdin);
a->carrera[strcspn(a->carrera, "\n")] = 0;
printf("Ingrese el promedio del alumno: ");
scanf("%f", &a->promedio);
fflush(stdin);
printf("Ingrese la direccion del alumno: ");
fgets(a->direccion, 50, stdin);
a->direccion[strcspn(a->direccion, "\n")] = 0;
}
void main(void)
{
struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
struct alumno *a3, *a4, *a5, a6;
a3 = &a0;
a4 = (struct alumno *)malloc(sizeof(struct alumno));
if (a4 == NULL)
return;
strcpy(a4->nombre, "Pedro");
strcpy(a4->carrera, "Informatica");
a4->matricula = 200;
a4->promedio = 7.8;
strcpy(a4->direccion, "Mexico");
a5 = (struct alumno *)malloc(sizeof(struct alumno));
if (a5 == NULL)
{
free(a4);
return;
}
Lectura(a5);
Lectura(&a6);
printf("\nDatos del alumno 3\n");
printf("%d\t%s\t%s\t%.2f\t%s", a3->matricula, a3->nombre, a3->carrera, a3->promedio, a3->direccion);
printf("\nDatos del alumno 4\n");
printf("%d\t%s\t%s\t%.2f\t%s", a4->matricula, a4->nombre, a4->carrera, a4->promedio, a4->direccion);
printf("\nDatos del alumno 5\n");
printf("%d\t%s\t%s\t%.2f\t%s", a5->matricula, a5->nombre, a5->carrera, a5->promedio, a5->direccion);
printf("\nDatos del alumno 6\n");
printf("%d\t%s\t%s\t%.2f\t%s", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);
free(a4);
free(a5);
}
                