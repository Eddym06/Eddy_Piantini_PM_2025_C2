#include <stdio.h>
#include <string.h>
#include <ctype.h>

void minymay(char *cadena) {
int i = 0, mi = 0, ma = 0;
while (cadena[i] != '\0') {
if (islower(cadena[i])) {
mi++;
} else if (isupper(cadena[i])) {
ma++;
}
i++;
}
printf("\nNumero de letras minusculas: %d", mi);
printf("\nNumero de letras mayusculas: %d", ma);
}

int main(void) {
int i, n;
char FRA[20][50];

printf("\nIngrese el numero de filas del arreglo: ");
scanf("%d", &n);
getchar();

for (i = 0; i < n; i++) {
printf("Ingrese la linea %d de texto: ", i + 1);
gets(FRA[i]);
}

printf("\n");
for (i = 0; i < n; i++) {
minymay(FRA[i]);
}

return 0;
}
