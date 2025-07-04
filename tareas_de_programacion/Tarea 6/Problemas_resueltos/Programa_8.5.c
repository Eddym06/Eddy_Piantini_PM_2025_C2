Este programa demuestra cómo se declara una unión y cómo se accede a los
campos de las variables de tipo unión para la asignación de valores, lectura y
escritura. También muestra que solo un componente de la unión puede tener un
valor significativo a la vez.
#include <stdio.h>
#include <string.h>
/* Uniones. El programa muestra la manera como se declara una unión, así como la
forma de ➥acceso a los campos de las variables de tipo unión tanto para
asignación ➥de valores como para lectura y escritura. */
union datos /* Declaración de una unión. */
{
char celular;
char correo;
};
typedef struct /* Declaración de una estructura utilizando typedef. */
{
int matricula;
char nombre;
char carrera;
float promedio;
union datos personales; /* Observa que uno de los campos de la estructura
alumno es una unión. */
} alumno;
void Lectura(alumno *a); // Corrected: parameter should be a pointer to alumno
void main(void) {
alumno a1 = {120, ”María”, ”Contabilidad”, 8.9, ”5-158-40-50”}; // Initializing the
first member of the union
alumno a2, a3; /* Observa que sólo el primer componente de una unión puede
recibir valores por ➥medio de este tipo de asignaciones. */
/* Para que puedas observar las diferentes formas en que los campos de las
➥variables de tipo estructura alumno reciben valores, ingresamos los valores ➥de
los campos de tres formas diferentes. Los campos de a1 reciben valores
➥directamente, los campos de a2 se leen en el programa principal, y los campos
➥de a3 reciben valores a través de una función. */
printf(”Alumno 2\n”);
printf(”Ingrese la matrícula: ”);

scanf(”%d”, &a2.matricula);
fflush(stdin);
printf(”Ingrese el nombre: ”);
gets(a2.nombre);
fflush(stdin);
printf(”Ingrese la carrera: ”);
gets(a2.carrera);
printf(”Ingrese el promedio: ”);
scanf(”%f”, &a2.promedio);
fflush(stdin);
printf(”Ingrese el correo electrónico: ”);
gets(a2.personales.correo); /* Observa que en la variable a2 de tipo estructura
alumno el segundo campo de la ➥unión recibe un valor. */
printf(”Alumno 3\n”);
Lectura(&a3); /* Se llama a una función para leer los campos de la variable a3.
*/
/* Impresión de resultados. */
printf(”\nDatos del alumno 1\n”);
printf(”%d\n”, a1.matricula);
puts(a1.nombre);
puts(a1.carrera);
printf(”%.2f\n”, a1.promedio);
puts(a1.personales.celular); /* Observa que escribe el valor del teléfono celular
asignado. */
// puts(a1.personales.correo); } /* Observa que si tratamos de imprimir el
campo correo, escribe basura. */ // This line was commented out in the source
code.
printf(”\nDatos del alumno 2\n”);
printf(”%d\n”, a2.matricula);
puts(a2.nombre);
puts(a2.carrera);
printf(”%.2f\n”, a2.promedio);
printf(”Ingrese el teléfono celular del alumno 2: ”);
fflush(stdin);
gets(a2.personales.celular);
puts(a2.personales.celular); /* Escribe el teléfono celular ingresado. */
puts(a2.personales.correo); /* Ahora escribe basura. */
printf(”\nDatos del alumno 3\n”);
printf(”%d\n”, a3.matricula);

puts(a3.nombre);
puts(a3.carrera);
printf(”%.2f\n”, a3.promedio);
puts(a3.personales.celular);
puts(a3.personales.correo); /* Escribe basura. */
}
void Lectura(alumno *a) /* La función Lectura se utiliza para leer los campos de
una variable de tipo ➥estructura alumno. */
{
printf(”\nIngrese la matrícula: ”);
scanf(”%d”, &(*a).matricula);
fflush(stdin);
printf(”Ingrese el nombre: ”);
gets(a->nombre);
fflush(stdin);
printf(”Ingrese la carrera: ”);
gets((*a).carrera);
printf(”Ingrese el promedio: ”);
scanf(”%f”, &a->promedio);
printf(”Ingrese el teléfono celular: ”);
fflush(stdin);
gets(a->personales.celular);
}