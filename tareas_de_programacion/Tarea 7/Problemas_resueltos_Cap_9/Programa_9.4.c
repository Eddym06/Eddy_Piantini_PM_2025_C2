#include <stdio.h>
int main(void)
{
char cad[50];
FILE *ar = fopen("arc.txt", "r");
if (ar != NULL)
{
while (fgets(cad, sizeof(cad), ar) != NULL)
printf("%s", cad);
fclose(ar);
}
else
printf("No se puede abrir el archivo\n");
return 0;
}
        