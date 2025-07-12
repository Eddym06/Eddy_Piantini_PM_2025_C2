#include <stdio.h>
#include <string.h>
void cambia(FILE *ar1, FILE *ar2);
int main(void)
{
FILE *ar = fopen("arc.txt", "r");
FILE *ap = fopen("arc1.txt", "w");
if (ar != NULL && ap != NULL)
{
cambia(ar, ap);
fclose(ar);
fclose(ap);
}
else
printf("No se pueden abrir los archivos\n");
return 0;
}
void cambia(FILE *ar1, FILE *ar2)
{
char cad[50], aux[50];
while (fgets(cad, sizeof(cad), ar1) != NULL)
{
char *cad1 = cad;
char *cad2 = strstr(cad1, "mxico");
strcpy(aux, "");
while (cad2 != NULL)
{
strncat(aux, cad1, cad2 - cad1);
strcat(aux, "Mxico");
cad1 = cad2 + strlen("mxico");
cad2 = strstr(cad1, "mxico");
}
strcat(aux, cad1);
fputs(aux, ar2);
}
}
                    