#include <stdio.h>
#include <ctype.h>
void minymay(FILE *);
void main(void)
{
FILE *ap;
ap = fopen("arc.txt", "r");
if (ap != NULL)
{
minymay(ap);
fclose(ap);
}
else
printf("No se puede abrir el archivo\n");
}
void minymay(FILE *ap1)
{
char cad[30];
int i, mi = 0, ma = 0;
while (!feof(ap1))
{
if (fgets(cad, 30, ap1) != NULL)
{
i = 0;
while (cad[i] != '\0')
{
if (islower(cad[i]))
mi++;
else if (isupper(cad[i]))
ma++;
i++;
}
}
}
printf("Numero de letras minusculas: %d\n", mi);
printf("Numero de letras mayusculas: %d\n", ma);
}
                        