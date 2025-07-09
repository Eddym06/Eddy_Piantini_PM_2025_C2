#include <stdio.h>
/* Cuenta caracteres. El programa, al recibir como dato un archivo de texto y un caracter, cuenta ➥el número de veces que se encuentra el caracter en el archivo. */
int cuenta(FILE *, char);    /* Prototipo de función. Se pasan dos archivos como parámetros. */
void main(void) {
char car;
int res;
FILE *ar;
printf(”\nIngrese el caracter que va a buscar en el archivo: ”);
car = getchar();
if ((ar = fopen(”arc.txt”, ”r”)) != NULL)
res = cuenta(ar, car);
else
res = -1;
if (res == -1)
printf(”\nEl archivo no se pudo abrir”);
else
printf(”\nEl caracter %c se encuentra en el archivo %d veces”, car, res);
}
int cuenta(FILE *ar, char car) /* Esta función cuenta el número de veces que se encuentra el caracter en el ➥archivo. */
{
int res, con = 0;
char p;
rewind(ar);   /* Se posiciona el apuntador en el inicio del archivo para ➥lectura. */
{
while (!feof(ar))    /* Se trabaja con el archivo mientras no se llegue ➥al fin de éste. */
{
p = getc(ar);
if (p == car)   /* Se realiza la comparación de los caracteres. */
con++;
}
fclose(ar);
res = con;
} else
res = -1;
return (res);
}