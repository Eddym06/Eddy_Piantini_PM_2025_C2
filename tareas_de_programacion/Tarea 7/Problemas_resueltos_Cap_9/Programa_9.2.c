#include <stdio.h>
void main(void)
{
char p1;
FILE *ar;
ar = fopen("arc.txt", "r");
if (ar != NULL)
{
while (!feof(ar))
{
p1 = fgetc(ar);
if (!feof(ar))
putchar(p1);
}
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
}
            