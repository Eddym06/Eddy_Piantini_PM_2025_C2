#include <stdio.h>
int main(void)
{
char p1;
FILE *ar = fopen("arc.txt", "r");
if (ar != NULL)
{
while ((p1 = fgetc(ar)) != EOF)
putchar(p1);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
        