#include <stdio.h>
typedef struct
{
int clave;
int departamento;
float salario;
float ventas[12];
} empleado;
void incrementa(FILE *);
int main(void)
{
FILE *ar;
ar = fopen("ad5.dat", "r+");
if (ar != NULL)
{
incrementa(ar);
fclose(ar);
}
else
printf("El archivo no se puede abrir\n");
return 0;
}
void incrementa(FILE *ap)
{
empleado emple;
int j;
float sum;
while (fread(&emple, sizeof(empleado), 1, ap))
{
sum = 0;
for (j = 0; j < 12; j++)
sum += emple.ventas[j];
if (sum > 1000000)
{
emple.salario *= 1.10;
fseek(ap, -(long)sizeof(empleado), SEEK_CUR);
fwrite(&emple, sizeof(empleado), 1, ap);
}
}
}
                        