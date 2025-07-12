#include <stdio.h>
int main(void)
{
char cad[50];
int res;
FILE *ar = fopen("arc.txt", "w");
if (ar != NULL)
{
printf("Desea ingresar una cadena de caracteres? S-1 No-0: ");
if (scanf("%d", &res) != 1)
{
printf("Entrada invlida\n");
fclose(ar);
return 1;
}
while (res)
{
while (getchar() != '\n');
printf("Ingrese la cadena: ");
if (fgets(cad, sizeof(cad), stdin) == NULL)
{
printf("Error al leer la cadena\n");
break;
}
cad[strcspn(cad, "\n")] = '\0';
fputs(cad, ar);
printf("Desea ingresar otra cadena de caracteres? S-1 No-0: ");
if (scanf("%d", &res) != 1)
{
printf("Entrada invlida\n");
break;
}
if (res)
fputs("\n", ar);
}
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
                        