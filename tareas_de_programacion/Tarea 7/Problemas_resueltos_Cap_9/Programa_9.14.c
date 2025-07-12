#include <stdio.h>
#include <ctype.h>
void minymay(FILE *ar);
int main(void)
{
FILE *ar = fopen("arc5.txt", "r");
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
int min = 0, may = 0;
char p;
while ((p = fgetc(ar)) != EOF)
{
if (islower(p))
min++;
else if (isupper(p))
may++;
}
printf("Nmero de minsculas: %d\n", min);
printf("Nmero de maysculas: %d\n", may);
}
                