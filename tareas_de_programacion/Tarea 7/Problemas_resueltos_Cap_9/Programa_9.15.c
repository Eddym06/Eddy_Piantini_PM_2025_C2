#include <stdio.h>
#include <ctype.h>
void minymay(FILE *ar);
int main(void)
{
FILE *ar = fopen("arc.txt", "r");
if (ar != NULL)
{
minymay(ar);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
void minymay(FILE *ar)
{
char cad[50];
int i, mi = 0, ma = 0;
while (fgets(cad, sizeof(cad), ar) != NULL)
{
for (i = 0; cad[i] != '\0'; i++)
{
if (islower(cad[i]))
mi++;
else if (isupper(cad[i]))
ma++;
}
}
printf("Nmero de letras minsculas: %d\n", mi);
printf("Nmero de letras maysculas: %d\n", ma);
}
                    