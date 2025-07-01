Este programa gestiona la información de pacientes en un hospital,
almacenándolos en un arreglo unidimensional de estructuras paciente, que a su
vez contienen una estructura anidada para el domicilio.
#include <stdio.h>
#include <string.h>
/* Hospital. El programa genera información importante de los pacientes de un
hospital. */
typedef struct /* Declaración de la estructura domicilio. */
{
char calle;
int numero;
char colo; // Colonia
char cp; // Código Postal
char ciu; // Ciudad
} domicilio;
typedef struct /* Declaración de la estructura paciente. */
{
char nom; /* Nombre. */
int edad; /* Edad. */
char sexo; /* Sexo. */
int con; /* Condición. */
domicilio dom; /* dom es de tipo estructura domicilio. */
char tel; /* Teléfono. */
} paciente;
void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int); /* Prototipos de funciones. */
void F3(paciente *, int);
void main(void) {

paciente HOSPITAL; /* Arreglo unidimensional de tipo estructura ➥paciente. */
int TAM;
do {
printf(”Ingrese el número de pacientes: ”);
scanf(”%d”, &TAM);
} while (TAM > 100 || TAM < 1); /* Se verifica que el tamaño del arreglo sea
➥correcto. */
Lectura(HOSPITAL, TAM);
F1(HOSPITAL, TAM);
F2(HOSPITAL, TAM);
F3(HOSPITAL, TAM);
}
void Lectura(paciente A[], int T) /* Esta función se utiliza para leer un arreglo
unidimensional de tipo ➥estructura paciente de T elementos. */
{
int I;
for (I=0; I<T; I++) {
printf(”\nIngrese datos del paciente %d”, I+1);
printf(”\nNombre: ”);
fflush(stdin);
gets(A[I].nom);
printf(”Edad: ”);
scanf(”%d”, &A[I].edad);
printf(”Sexo (F-M): ”);
fflush(stdin);
scanf(”%c”, &A[I].sexo);
printf(”Condición (1-5): ”);
scanf(”%d”, &A[I].con);
fflush(stdin);
printf(”—-Domicilio del paciente—-”);
printf(”\n\tCalle: ”);
gets(A[I].dom.calle);
printf(”\tNúmero: ”);
scanf(”%d”, &A[I].dom.numero);
printf(”\tColonia: ”);
fflush(stdin);
gets(A[I].dom.colo);
printf(”\tCódigo Postal: ”);
gets(A[I].dom.cp);
fflush(stdin);
printf(”\tCiudad: ”);
gets(A[I].dom.ciu);
printf(”Teléfono: ”);

gets(A[I].tel);
}
}
void F1(paciente A[], int T) /* Esta función obtiene el porcentaje de hombres y
mujeres registrados en el ➥hospital. */
{
int I, FEM = 0, MAS = 0;
for (I=0; I<T; I++)
if (A[I].sexo == ‘F’)
FEM++;
else
MAS++;
printf(”\nPorcentaje de Hombres: %5.2f”, (float)MAS / T * 100);
printf(”\nPorcentaje de Mujeres: %5.2f”, (float)FEM / T * 100);
}
void F2(paciente A[], int T) /* Esta función obtiene el número de pacientes de cada
una de las categorías ➥de condición. */
{
int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
for (I=0; I<T; I++)
switch (A[I].con) {
case 1: C1++; break;
case 2: C2++; break;
case 3: C3++; break;
case 4: C4++; break;
case 5: C5++; break;
}
printf(”\nNúmero de pacientes en condición 1: %d”, C1);
printf(”\nNúmero de pacientes en condición 2: %d”, C2);
printf(”\nNúmero de pacientes en condición 3: %d”, C3);
printf(”\nNúmero de pacientes en condición 4: %d”, C4);
printf(”\nNúmero de pacientes en condición 5: %d”, C5);
}
void F3(paciente A[], int T) /* Esta función obtiene el nombre y teléfono de todos
los pacientes que tuvieron ➥una condición de ingreso de máxima gravedad (5). */
{
int I;
printf(”\nPacientes con condición 5”);
for (I=0; I<T; I++)
if (A[I].con == 5)
printf(”\nNombre: %s\tTeléfono: %s”, A[I].nom, A[I].tel);

}