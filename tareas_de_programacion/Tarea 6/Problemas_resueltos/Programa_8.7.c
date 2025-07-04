Este programa, similar al 8.4, organiza la información de los alumnos utilizando un
arreglo unidimensional de estructuras, donde cada estructura alumno contiene un
campo cal que es a su vez un arreglo unidimensional de estructuras matpro,

detallando materia y promedio.
#include <stdio.h>
#include <string.h>
/* Escuela. El programa genera información importante de los alumnos de una
escuela. */
typedef struct /* Declaración de la estructura matpro. */
{
char mat; /* Materia. */
int pro; /* Promedio. */
} matpro;
typedef struct /* Declaración de la estructura alumno. */
{
int matri; /* Matrícula. */
char nom; /* Nombre del alumno. */
matpro cal; /* Observa que cal es un arreglo unidimensional de tipo
➥estructura matpro —la estructura definida en primer término. */
} alumno;
void Lectura(alumno * , int);
void F1(alumno *, int);
void F2(alumno *, int); /* Prototipos de funciones. */
void F3(alumno *, int);
void main(void) {
alumno ALU; /* ALU es un arreglo unidimensional de tipo alumno. */
int TAM;
do {
printf(”Ingrese el tamaño del arreglo: ”);
scanf(”%d”, &TAM);
} while (TAM > 50 || TAM < 1); /* Se verifica que el tamaño del arreglo sea
➥correcto. */
Lectura(ALU, TAM);
F1(ALU, TAM);
F2(ALU, TAM);
F3(ALU, TAM);
}
void Lectura(alumno A[], int T) /* Esta función se utiliza para leer la información de
un arreglo unidimensional ➥de tipo estructura alumno de T elementos. */
{
int I, J;

for(I=0; I<T; I++) {
printf(”\nIngrese los datos del alumno %d”, I+1);
printf(”\nIngrese la matrícula del alumno: ”);
scanf(”%d”, &A[I].matri);
fflush(stdin);
printf(”Ingrese el nombre del alumno:”);
gets(A[I].nom);
for (J=0; J<5; J++) {
printf(”\tMateria %d: ”, J+1);
fflush(stdin);
gets(A[I].cal[J].mat);
printf(”\tPromedio %d: ”, J+1);
scanf(”%d”, &A[I].cal[J].pro);
}
}
}
void F1(alumno A[], int T) /* Esta función se utiliza para obtener la matrícula y el
promedio general de ➥cada alumno. */
{
int I, J;
float SUM;
for (I=0; I<T; I++) {
printf(”\nMatrícula del alumno : %d”, A[I].matri);
SUM = 0.0;
for (J=0; J<5; J++)
SUM = SUM + A[I].cal[J].pro;
SUM = SUM / 5;
printf(”\tPromedio: %.2f”, SUM);
}
}
void F2(alumno A[], int T) /* Esta función se utiliza para obtener las matrículas de
los alumnos cuya ➥calificación en la tercera materia es mayor a 9. */
{
int I;
printf(”\nAlumnos con calificación mayor a 9 en la tercera materia”);
for (I=0; I<T; I++)
if (A[I].cal.pro > 9)
printf(”\nMatrícula del alumno : %d”, A[I].matri);
}
void F3(alumno A[], int T) /* Esta función se utiliza para obtener el promedio
general de la cuarta materia. */

{
int I;
float SUM = 0.0; // Corrected: PRO was used without initialization
for (I=0; I<T; I++)
SUM = SUM + A[I].cal.pro;
float PRO = SUM / T; // PRO needs to be declared as float
printf(”\n\nPromedio de la cuarta materia: %.2f”, PRO);
}