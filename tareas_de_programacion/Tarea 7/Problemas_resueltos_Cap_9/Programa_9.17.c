#include <stdio.h>
#include <string.h>
void cambia(FILE *, FILE *);
void main(void)
{
FILE *ar, *ap;
ar = fopen("arc.txt", "r");
ap = fopen("arc1.txt", "w");
if (ar != NULL && ap != NULL)
{
cambia(ar, ap);
fclose(ar);
fclose(ap);
}
else
printf("No se pueden abrir los archivos\n");
}
void cambia(FILE *ap1, FILE *ap2)
{
char cad[30], aux[30];
char *cad1, *cad2;
while (!feof(ap1))
{
if (fgets(cad, 30, ap1) != NULL)
{
cad1 = cad;
cad2 = strstr(cad1, "mexico");
while (cad2 != NULL)
{
strcpy(aux, cad2 + 6);
*cad2 = '\0';
strcat(cad1, "Mexico");
strcat(cad1, aux);
cad2 = strstr(cad1, "mexico");
}
fputs(cad1, ap2);
}
}
}
                        