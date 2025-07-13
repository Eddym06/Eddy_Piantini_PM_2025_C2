#include <stdio.h>
#include <string.h>
typedef struct
{
char zona[50];
char calle[50];
char colo[50];
} ubicacion;
typedef struct
{
char clave[50];
float scu;
float ste;
char car[100];
ubicacion ubi;
float precio;
char dispo;
} propiedades;
void Lectura(propiedades *, int);
void F1(propiedades *, int);
void F2(propiedades *, int);
void main(void)
{
propiedades PROPIE[100];
int TAM;
do
{
printf("Ingrese el numero de propiedades: ");
scanf("%d", &TAM);
} while (TAM > 100 || TAM < 1);
Lectura(PROPIE, TAM);
F1(PROPIE, TAM);
F2(PROPIE, TAM);
}
void Lectura(propiedades A[], int T)
{
int I;
for (I = 0; I < T; I++)
{
printf("\n\tIngrese datos de la propiedad %d\n", I + 1);
printf("Clave: ");
fflush(stdin);
fgets(A[I].clave, 50, stdin);
A[I].clave[strcspn(A[I].clave, "\n")] = 0;
printf("Superficie cubierta: ");
scanf("%f", &A[I].scu);
printf("Superficie terreno: ");
scanf("%f", &A[I].ste);
printf("Caracteristicas: ");
fflush(stdin);
fgets(A[I].car, 100, stdin);
A[I].car[strcspn(A[I].car, "\n")] = 0;
printf("\tZona: ");
fgets(A[I].ubi.zona, 50, stdin);
A[I].ubi.zona[strcspn(A[I].ubi.zona, "\n")] = 0;
printf("\tCalle: ");
fgets(A[I].ubi.calle, 50, stdin);
A[I].ubi.calle[strcspn(A[I].ubi.calle, "\n")] = 0;
printf("\tColonia: ");
fgets(A[I].ubi.colo, 50, stdin);
A[I].ubi.colo[strcspn(A[I].ubi.colo, "\n")] = 0;
printf("Precio: ");
scanf("%f", &A[I].precio);
printf("Disponibilidad (Venta-V Renta-R): ");
fflush(stdin);
scanf("%c", &A[I].dispo);
}
}
void F1(propiedades A[], int T)
{
int I;
printf("\n\t\tListado de Propiedades para Venta en Miraflores");
for (I = 0; I < T; I++)
if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0))
if ((A[I].precio >= 450000) && (A[I].precio <= 650000))
{
printf("\nClave de la propiedad: ");
puts(A[I].clave);
printf("\nSuperficie cubierta: %f", A[I].scu);
printf("\nSuperficie terreno: %f", A[I].ste);
printf("\nCaracteristicas: ");
puts(A[I].car);
printf("Calle: ");
puts(A[I].ubi.calle);
printf("Colonia: ");
puts(A[I].ubi.colo);
printf("Precio: %.2f\n", A[I].precio);
}
}
void F2(propiedades A[], int T)
{
int I;
float li, ls;
char zon[50];
printf("\n\t\tListado de Propiedades para Renta");
printf("\nIngrese zona geografica: ");
fflush(stdin);
fgets(zon, 50, stdin);
zon[strcspn(zon, "\n")] = 0;
printf("Ingrese el limite inferior del precio: ");
scanf("%f", &li);
printf("Ingrese el limite superior del precio: ");
scanf("%f", &ls);
for (I = 0; I < T; I++)
if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0))
if ((A[I].precio >= li) && (A[I].precio <= ls))
{
printf("\nClave de la propiedad: ");
puts(A[I].clave);
printf("\nSuperficie cubierta: %f", A[I].scu);
printf("\nSuperficie terreno: %f", A[I].ste);
printf("\nCaracteristicas: ");
puts(A[I].car);
printf("Calle: ");
puts(A[I].ubi.calle);
printf("Colonia: ");
puts(A[I].ubi.colo);
printf("Precio: %.2f", A[I].precio);
}
}
                                        