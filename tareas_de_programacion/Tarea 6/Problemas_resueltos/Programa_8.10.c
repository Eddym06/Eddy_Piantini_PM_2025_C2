#include <stdio.h>
#include <string.h>
typedef struct
{
char noba[50];
char nucu[50];
} banco;
typedef union
{
banco che;
banco nomi;
char venta;
} fpago;
typedef struct
{
char cnu[50];
char col[50];
char cp[10];
char ciu[50];
} domicilio;
typedef struct
{
int num;
char nom[50];
float ven[12];
domicilio domi;
float sal;
fpago pago;
int cla;
} vendedor;
void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int);
void F3(vendedor *, int);
void F4(vendedor *, int);
void main(void)
{
vendedor VENDEDORES[100];
int TAM;
do
{
printf("Ingrese el numero de vendedores: ");
scanf("%d", &TAM);
} while (TAM > 100 || TAM < 1);
Lectura(VENDEDORES, TAM);
F1(VENDEDORES, TAM);
F2(VENDEDORES, TAM);
F3(VENDEDORES, TAM);
F4(VENDEDORES, TAM);
printf("\n\tFIN DEL PROGRAMA");
}
void Lectura(vendedor A[], int T)
{
int I, J;
for (I = 0; I < T; I++)
{
printf("\nIngrese datos del vendedor %d\n", I + 1);
printf("Numero de empleado: ");
scanf("%d", &A[I].num);
fflush(stdin);
printf("Nombre: ");
fgets(A[I].nom, 50, stdin);
A[I].nom[strcspn(A[I].nom, "\n")] = 0;
printf("Ventas del ano (12 meses): ");
for (J = 0; J < 12; J++)
{
printf("\tMes %d: ", J + 1);
scanf("%f", &A[I].ven[J]);
}
printf("----Domicilio del vendedor----\n");
printf("\tCalle y numero: ");
fflush(stdin);
fgets(A[I].domi.cnu, 50, stdin);
A[I].domi.cnu[strcspn(A[I].domi.cnu, "\n")] = 0;
printf("\tColonia: ");
fgets(A[I].domi.col, 50, stdin);
A[I].domi.col[strcspn(A[I].domi.col, "\n")] = 0;
printf("\tCodigo Postal: ");
fgets(A[I].domi.cp, 10, stdin);
A[I].domi.cp[strcspn(A[I].domi.cp, "\n")] = 0;
printf("\tCiudad: ");
fgets(A[I].domi.ciu, 50, stdin);
A[I].domi.ciu[strcspn(A[I].domi.ciu, "\n")] = 0;
printf("Salario: ");
scanf("%f", &A[I].sal);
printf("Clave forma de pago (1-Cheque 2-Nomina 3-Ventanilla): ");
scanf("%d", &A[I].cla);
fflush(stdin);
switch (A[I].cla)
{
case 1:
printf("\tNombre del banco: ");
fgets(A[I].pago.che.noba, 50, stdin);
A[I].pago.che.noba[strcspn(A[I].pago.che.noba, "\n")] = 0;
printf("\tNumero de cuenta: ");
fgets(A[I].pago.che.nucu, 50, stdin);
A[I].pago.che.nucu[strcspn(A[I].pago.che.nucu, "\n")] = 0;
break;
case 2:
printf("\tNombre del banco: ");
fgets(A[I].pago.nomi.noba, 50, stdin);
A[I].pago.nomi.noba[strcspn(A[I].pago.nomi.noba, "\n")] = 0;
printf("\tNumero de cuenta: ");
fgets(A[I].pago.nomi.nucu, 50, stdin);
A[I].pago.nomi.nucu[strcspn(A[I].pago.nomi.nucu, "\n")] = 0;
break;
case 3:
A[I].pago.venta = 'S';
break;
}
}
}
void F1(vendedor A[], int T)
{
int I, J;
float SUM;
printf("\n\t\tVentas Totales de los Vendedores");
for (I = 0; I < T; I++)
{
SUM = 0.0;
for (J = 0; J < 12; J++)
SUM += A[I].ven[J];
printf("\nNumero de empleado: %d\tTotal de ventas: %.2f", A[I].num, SUM);
}
}
void F2(vendedor A[], int T)
{
int I, J;
float SUM;
printf("\n\t\tIncremento de Salarios");
for (I = 0; I < T; I++)
{
SUM = 0.0;
for (J = 0; J < 12; J++)
SUM += A[I].ven[J];
if (SUM > 1500000.00)
{
A[I].sal = A[I].sal * 1.05;
printf("\nNumero de empleado: %d\tSalario: %.2f", A[I].num, A[I].sal);
}
}
}
void F3(vendedor A[], int T)
{
int I, J;
float SUM;
printf("\n\t\tVendedores con Ventas < 300,000");
for (I = 0; I < T; I++)
{
SUM = 0.0;
for (J = 0; J < 12; J++)
SUM += A[I].ven[J];
if (SUM < 300000.00)
printf("\nNumero de empleado: %d\nNombre: %s\nVentas: %.2f", A[I].num, A[I].nom, SUM);
}
}
void F4(vendedor A[], int T)
{
int I;
printf("\n\t\tVendedores con Cuenta en el Banco");
for (I = 0; I < T; I++)
if (A[I].cla == 1)
printf("\nNumero de vendedor: %d\n Banco: %s\nCuenta: %s", A[I].num, A[I].pago.che.noba, A[I].pago.che.nucu);
}
                                                                        