Este programa demuestra la declaración de una estructura anidada y cómo se

accede a los campos de las variables o apuntadores de tipo estructura, tanto para
lectura como para escritura. También utiliza una función que recibe un apuntador
de tipo estructura como parámetro.
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Necesario para new o malloc/free
typedef struct /* Declaración de la estructura domicilio utilizando ➥un
typedef. */
{
char calle;
int numero;
int cp;
char localidad;
} domicilio;
struct empleado /* Declaración de la estructura anidada empleado. */
{
char nombre;
char departamento;
float sueldo;
domicilio direccion; /* dirección es un campo de tipo estructura domicilio. */
};
void Lectura(struct empleado *); /* Prototipo de función. */
void main(void) {
struct empleado e0 = {”Arturo”, ”Compras”, 15500.75, ”San Jerónimo”, 120,
3490, ”Toluca”};
struct empleado *e1, *e2, e3, e4; /* Se declaran diferentes variables y
apuntadores de la estructura empleado ➥para que el lector pueda apreciar
también las diferentes formas en que los ➥campos reciben valores. */
/* En el programa principal se leen los campos de una variable, e3, y un
➥apuntador de tipo estructura, *e1. */
// Original source uses 'new (struct empleado)'
e1 = (struct empleado *)malloc(sizeof(struct empleado));
if (e1 == NULL) { /* Handle allocation error */ return; }
printf(”\nIngrese el nombre del empleado 1: ”);
scanf(”%s”, e1->nombre); // Removed &(*e1).nombre based on common usage
fflush(stdin);
printf(”Ingrese el departamento de la empresa: ”);
gets(e1->departamento);

printf(”Ingrese el sueldo del empleado: ”);
scanf(”%f”, &e1->sueldo);
printf(”—-Ingrese la dirección del empleado—-”);
printf(”\n\tCalle: ”);
fflush(stdin);
gets(e1->direccion.calle); // Corrected from e1->dirección, calle
printf(”\tNúmero: ”);
scanf(”%d”, &e1->direccion.numero);
printf(”\tCódigo Postal: ”);
scanf(”%d”, &e1->direccion.cp);
printf(”\tLocalidad: ”);
fflush(stdin);
gets(e1->direccion.localidad);
printf(”\nIngrese el nombre del empleado 3: ”);
scanf(”%s”, e3.nombre);
fflush(stdin);
printf(”Ingrese el departamento de la empresa: ”);
gets(e3.departamento);
printf(”Ingrese el sueldo del empleado: ”);
scanf(”%f”, &e3.sueldo);
printf(”—-Ingrese la dirección del empleado—-”);
printf(”\n\tCalle: ”);
fflush(stdin);
gets(e3.direccion.calle);
printf(”\tNúmero: ”);
scanf(”%d”, &e3.direccion.numero);
printf(”\tCódigo Postal: ”);
scanf(”%d”, &e3.direccion.cp);
printf(”\tLocalidad: ”);
fflush(stdin);
gets(e3.direccion.localidad);
/* En la función Lectura se leen los campos de una variable, e4, y un apuntador
➥de tipo estructura, *e2. */
// Original source uses 'new (struct empleado)'
e2 = (struct empleado *)malloc(sizeof(struct empleado));
if (e2 == NULL) { /* Handle allocation error */ free(e1); return; }
Lectura(e2);
Lectura(&e4);
printf(”\nDatos del empleado 1\n”);
printf(”%s\t%s\t%.2f\t%s\t%d\t%d\t%s”, e1->nombre, e1->departamento, e1-

>sueldo, e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1-
>direccion.localidad);
printf(”\nDatos del empleado 3\n”);
printf(”%s\t%s\t%.2f\t%s\t%d\t%d\t%s”, e3.nombre, e3.departamento,
e3.sueldo, e3.direccion.calle, e3.direccion.numero, e3.direccion.cp,
e3.direccion.localidad);
printf(”\nDatos del empleado 4\n”);
printf(”%s\t%s\t%.2f\t%s\t%d\t%d\t%s”, e4.nombre, e4.departamento,
e4.sueldo, e4.direccion.calle, e4.direccion.numero, e4.direccion.cp,
e4.direccion.localidad);
// Free allocated memory (good practice in C)
free(e1);
free(e2);
}
void Lectura(struct empleado *a) /* Esta función permite leer los campos de un
apuntador de tipo estructura ➥alumno. */
{
printf(”\nIngrese el nombre del empleado: ”);
scanf(”%s”, a->nombre);
fflush(stdin);
printf(”Ingrese el departamento de la empresa: ”);
gets(a->departamento);
printf(”Ingrese el sueldo del empleado: ”);
scanf(”%f”, &a->sueldo);
printf(”—-Ingrese la dirección del empleado—-”);
printf(”\n\tCalle: ”);
fflush(stdin);
gets(a->direccion.calle);
printf(”\tNúmero: ”);
scanf(”%d”, &a->direccion.numero);
printf(”\tCódigo Postal: ”);
scanf(”%d”, &a->direccion.cp);
printf(”\tLocalidad: ”);
fflush(stdin);
gets(a->direccion.localidad);
}