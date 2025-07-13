#include <stdio.h>
typedef struct
{
int matricula;
char nombre[50];
int carrera;
float promedio;
} alumno;
void modifica(FILE *);
int main(void)
{
FILE *ar;
ar = fopen("ad1.dat", "r+");
if (ar != NULL)
{
modifica(ar);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void modifica(FILE *ar)
{
int d;
alumno alu;
printf("Ingrese el numero de registro a modificar: ");
if (scanf("%d", &d) != 1 || d < 1)
{
printf("Entrada invalida\n");
return;
}
fseek(ar, (d - 1) * sizeof(alumno), SEEK_SET);
if (fread(&alu, sizeof(alumno), 1, ar) != 1)
{
printf("Registro no encontrado\n");
return;
}
printf("Ingrese el nuevo promedio: ");
if (scanf("%f", &alu.promedio) != 1)
{
printf("Entrada invalida\n");
return;
}
fseek(ar, (d - 1) * sizeof(alumno), SEEK_SET);
fwrite(&alu, sizeof(alumno), 1, ar);
}
                            