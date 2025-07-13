#include <stdio.h>
int cuenta(FILE *, char);
void main(void)
{
int res;
char car;
FILE *ar;
printf("Ingrese el caracter que se va a buscar en el archivo: ");
car = getchar();
ar = fopen("arc.txt", "r");
if (ar != NULL)
{
res = cuenta(ar, car);
if (res != -1)
printf("El caracter %c se encuentra %d veces en el archivo\n", car, res);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
}
int cuenta(FILE *ar, char car)
{
int con = 0;
char p;
while (!feof(ar))
{
p = fgetc(ar);
if (p == car)
con++;
}
return con;
}
                