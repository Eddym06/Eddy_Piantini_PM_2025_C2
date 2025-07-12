#include <stdio.h>
typedef struct
{
int clave;
int departamento;
float salario;
float ventas[12];
} empleado;
void incrementa(FILE *ar);
int main(void)
{
FILE *ar = fopen("ad5.dat", "r+");
if (ar != NULL)
{
incrementa(ar);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void incrementa(FILE *ar)
{
empleado emp;
long pos;
int i;
while (fread(&emp, sizeof(empleado), 1, ar))
{
float sum = 0;
for (i = 0; i < 12; i++)
sum += emp.ventas[i];
if (sum > 1000000)
{
emp.salario *= 1.10;
pos = ftell(ar) - sizeof(empleado);
fseek(ar, pos, SEEK_SET);
fwrite(&emp, sizeof(empleado), 1, ar);
fseek(ar, 0, SEEK_CUR);
}
}
}
                        