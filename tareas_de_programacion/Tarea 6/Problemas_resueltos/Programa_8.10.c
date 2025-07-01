Este programa maneja información sobre los vendedores de una empresa,
utilizando una estructura vendedor que incluye una unión para la forma de pago,
una estructura anidada para el domicilio, y un arreglo para las ventas anuales.
#include <stdio.h>
#include <string.h>
/* Vendedores. El programa maneja información sobre las ventas que realizan los
vendedores de ➥artículos domésticos de una importante empresa de la Ciudad de
México. */
typedef struct /* Declaración de la estructura banco. */
{
char noba; /* Nombre del banco. */
char nucu; /* Número de cuenta. */
} banco;
typedef union /* Declaración de la union fpago. */
{
banco che; /* Cheque. Campo de tipo estructura banco. */
banco nomi; /* Cómina. Campo de tipo estructura banco. */
char venta; /* Ventanilla. */
} fpago;
typedef struct /* Declaración de la estructura domicilio. */
{
char cnu; /* Calle y número. */
char col; /* Colonia. */
char cp; /* Código Postal. */
char ciu; /* Ciudad. */
} domicilio;
typedef struct /* Declaración de la estructura vendedor. */
{
int num; /* Número de vendedor. */
char nom; /* Nombre del vendedor. */
float ven; /* Ventas del año. Arreglo unidimensional de tipo real. */
domicilio domi; /* domi es de tipo estructura domicilio. */
float sal; /* Salario mensual. */

fpago pago; /* pago es de tipo unión fpago. */
int cla; /* Clave forma de pago. */
} vendedor;
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int); /* Prototipos de funciones. */
void F3(vendedor *, int);
void F4(vendedor *, int);
void main(void) {
vendedor VENDEDORES; /* Declaración del arreglo unidimensional de tipo
estructura vendedor. */
int TAM;
do {
printf(”Ingrese el número de vendedores: ”);
scanf(”%d”, &TAM);
} while (TAM > 100 || TAM < 1); /* Se verifica que el número de elementos del
arreglo sea correcto. */
Lectura (VENDEDORES, TAM);
F1 (VENDEDORES, TAM);
F2 (VENDEDORES, TAM);
F3 (VENDEDORES, TAM);
F4 (VENDEDORES, TAM);
printf(”\n\tFIN DEL PROGRAMA”);
}
void Lectura(vendedor A[], int T) /* Esta función se utiliza para leer un arreglo
unidimensional de tipo ➥estructura vendedor de T elementos. */
{
int I, J;
for (I=0; I<T; I++) {
printf(”\nIngrese datos del vendedor %d”, I+1);
printf(”\nNúmero de empleado: ”);
scanf(”%d”, &A[I].num);
fflush(stdin);
printf(”Nombre: ”);
gets(A[I].nom);
printf(”Ventas del año (12 meses): ”);
for (J=0; J<12; J++) {
printf(”\tMes %d: ”, J+1);
scanf(”%f”, &A[I].ven[J]);
}
printf(”—-Domicilio del vendedor—-”);

printf(”\n\tCalle y número: ”);
fflush(stdin);
gets(A[I].domi.cnu);
printf(”\tColonia: ”);
fflush(stdin);
gets(A[I].domi.col);
printf(”\tCódigo Postal: ”);
fflush(stdin);
gets(A[I].domi.cp);
printf(”\tCiudad: ”);
fflush(stdin);
gets(A[I].domi.ciu);
printf(”Salario: ”);
scanf(”%f”, &A[I].sal);
printf(”Clave forma de pago (1-Cheque 2-Nómina 3-Ventanilla): ”);
scanf(”%d”, &A[I].cla);
fflush(stdin); // Added fflush to clear buffer before switch
switch (A[I].cla) {
case 1:{ printf(”\tNombre del banco: ”); fflush(stdin);
gets(A[I].pago.che.noba);
printf(”\tNúmero de cuenta: ”); fflush(stdin);
gets(A[I].pago.che.nucu);
}
break;
case 2:{ printf(”\tNombre del banco: ”); fflush(stdin);
gets(A[I].pago.nomi.noba);
printf(”\tNúmero de cuenta: ”); fflush(stdin);
gets(A[I].pago.nomi.nucu);
} break;
case 3: A[I].pago.venta = ‘S’; break;
}
}
}
void F1(vendedor A[], int T) /* Esta función se utiliza para generar las ventas
totales anuales de cada uno ➥de los vendedores de la empresa. */
{
int I, J;
float SUM;
printf(”\n\t\tVentas Totales de los Vendedores”);
for (I=0; I<T; I++) {
SUM = 0.0;
for (J=0; J<12; J++)
SUM += A[I].ven[J];

printf(”\nNúmero de empleado: %d\tTotal de ventas: %.2f”, A[I].num, SUM);
}
}
void F2(vendedor A[], int T) /* Esta función se utiliza para incrementar 5% el
salario a todos aquellos ➥empleados cuyas ventas anuales superaron $1,500,000.
*/
{
int I, J;
float SUM;
printf(”\n\t\tIncremento de Salarios”);
for (I=0; I<T; I++) {
SUM = 0.0;
for (J=0; J<12; J++)
SUM += A[I].ven[J];
if (SUM > 1500000.00) {
A[I].sal = A[I].sal * 1.05;
printf(”\nNúmero de empleado: %d\tSalario: %.2f”, A[I].num, A[I].sal);
}
}
}
void F3(vendedor A[], int T) /* Esta función se utiliza para generar un listado de
todos aquellos ➥vendedores que en el año vendieron menos de $300,000. */
{
int I, J;
float SUM;
printf(”\n\t\tVendedores con Ventas < 300,000”);
for (I=0; I<T; I++) {
SUM = 0.0;
for (J=0; J<12; J++)
SUM += A[I].ven[J];
if (SUM < 300000.00)
printf(”\nNúmero de empleado: %d\nNombre: %s\nVentas: %.2f”, A[I].num,
A[I].nom, SUM);
}
}
void F4(vendedor A[], int T) /* Esta función se usa para imprimir el número de
empleado, el nombre del ➥banco y el número de cuenta de todos aquellos
empleados a quienes se les ➥deposita su sueldo en cuenta de cheques. */
{
int I;
printf(”\n\t\tVendedores con Cuenta en el Banco”);

for (I=0; I<T; I++)
if (A[I].cla == 1)
printf(”\nNúmero de vendedor: %d\n Banco: %s\nCuenta: %s”, A[I].num,
A[I].pago.che.noba, A[I].pago.che.nucu);
}