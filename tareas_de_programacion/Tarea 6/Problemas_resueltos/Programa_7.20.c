#include <stdio.h>
#include <string.h>

int longitud(char *cadena) {
int cue = 0;
while (cadena[cue] != '\0') {
cue++;
}
return cue;
}

int main(void) {
int i, n, l = -1, p, t;
char cad[50], FRA[20][50];
printf("\nIngrese el numero de filas del arreglo: ");
scanf("%d", &n);
getchar();
for (i = 0; i < n; i++) {
printf("Ingrese la linea %d de texto. Maximo 50 caracteres: ", i + 1);
fgets(FRA[i], sizeof(FRA[i]), stdin);
FRA[i][strcspn(FRA[i], "\n")] = 0;
}
printf("\n");
for (i = 0; i < n; i++) {
strcpy(cad, FRA[i]);
t = longitud(cad);
if (t > l) {
l = t;
p = i;
}
}
printf("\nLa cadena con mayor longitud es: ");
puts(FRA[p]);
printf("\nLongitud: %d", l);
return 0;
}
                