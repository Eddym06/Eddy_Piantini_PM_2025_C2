#include <stdio.h>
#include <string.h>
typedef struct
{
char calle[50];
int numero;
char colo[50];
char cp[10];
char ciu[50];
} domicilio;
typedef struct
{
char nom[50];
int edad;
char sexo;
int con;
domicilio dom;
char tel[20];
} paciente;
void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);
void main(void)
{
paciente HOSPITAL[100];
int TAM;
do
{
printf("Ingrese el numero de pacientes: ");
scanf("%d", &TAM);
} while (TAM > 100 || TAM < 1);
Lectura(HOSPITAL, TAM);
F1(HOSPITAL, TAM);
F2(HOSPITAL, TAM);
F3(HOSPITAL, TAM);
}
void Lectura(paciente A[], int T)
{
int I;
for (I = 0; I < T; I++)
{
printf("\nIngrese datos del paciente %d\n", I + 1);
printf("Nombre: ");
fflush(stdin);
fgets(A[I].nom, 50, stdin);
A[I].nom[strcspn(A[I].nom, "\n")] = 0;
printf("Edad: ");
scanf("%d", &A[I].edad);
printf("Sexo (F-M): ");
fflush(stdin);
scanf("%c", &A[I].sexo);
printf("Condicion (1-5): ");
scanf("%d", &A[I].con);
fflush(stdin);
printf("----Domicilio del paciente----\n");
printf("\tCalle: ");
fgets(A[I].dom.calle, 50, stdin);
A[I].dom.calle[strcspn(A[I].dom.calle, "\n")] = 0;
printf("\tNumero: ");
scanf("%d", &A[I].dom.numero);
printf("\tColonia: ");
fflush(stdin);
fgets(A[I].dom.colo, 50, stdin);
A[I].dom.colo[strcspn(A[I].dom.colo, "\n")] = 0;
printf("\tCodigo Postal: ");
fgets(A[I].dom.cp, 10, stdin);
A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = 0;
printf("\tCiudad: ");
fgets(A[I].dom.ciu, 50, stdin);
A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = 0;
printf("Telefono: ");
fgets(A[I].tel, 20, stdin);
A[I].tel[strcspn(A[I].tel, "\n")] = 0;
}
}
void F1(paciente A[], int T)
{
int I, FEM = 0, MAS = 0;
for (I = 0; I < T; I++)
if (A[I].sexo == 'F')
FEM++;
else
MAS++;
printf("\nPorcentaje de Hombres: %5.2f", (float)MAS / T * 100);
printf("\nPorcentaje de Mujeres: %5.2f", (float)FEM / T * 100);
}
void F2(paciente A[], int T)
{
int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
for (I = 0; I < T; I++)
switch (A[I].con)
{
case 1:
C1++;
break;
case 2:
C2++;
break;
case 3:
C3++;
break;
case 4:
C4++;
break;
case 5:
C5++;
break;
}
printf("\nNumero de pacientes en condicion 1: %d", C1);
printf("\nNumero de pacientes en condicion 2: %d", C2);
printf("\nNumero de pacientes en condicion 3: %d", C3);
printf("\nNumero de pacientes en condicion 4: %d", C4);
printf("\nNumero de pacientes en condicion 5: %d", C5);
}
void F3(paciente A[], int T)
{
int I;
printf("\nPacientes con condicion 5");
for (I = 0; I < T; I++)
if (A[I].con == 5)
printf("\nNombre: %s\tTelefono: %s", A[I].nom, A[I].tel);
}
                                        