#include <stdio.h>
int cuenta(FILE *ar, char car);
int main(void)
{
char car;
int res;
printf("Ingrese el caracter a buscar: ");
car = getchar();
FILE *ar = fopen("arc.txt", "r");
if (ar != NULL)
{
res = cuenta(ar, car);
printf("El caracter %c se encuentra %d veces en el archivo\n", car, res);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
int cuenta(FILE *ar, char car)
{
int con = 0;
char p;
while ((p = fgetc(ar)) != EOF)
{
if (p == car)
con++;
}
return con;
}
                