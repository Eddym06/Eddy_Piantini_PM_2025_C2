#include <stdio.h>
void main(void)
{
char cad[50];
int res;
FILE *ar;
ar = fopen("arc.txt", "w");
if (ar != NULL)
{
printf("Desea ingresar una cadena de caracteres? Si-1 No-0: ");
scanf("%d", &res);
while (res)
{
while (getchar() != '\n');
printf("Ingrese la cadena: ");
fgets(cad, 50, stdin);
fputs(cad, ar);
printf("Desea ingresar otra cadena de caracteres? Si-1 No-0: ");
scanf("%d", &res);
if (res)
fputs("\n", ar);
}
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
}
            