#include <stdio.h>
#include <stdlib.h>

int main(void) {
char c, cad[10];
int i = 0;
float sum = 0.0;

printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
c = getchar();
getchar();

while (c == 'S' || c == 's') {
printf("\nIngrese la cadena de caracteres: ");
gets(cad);
i++;
sum += atof(cad);
printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
c = getchar();
getchar();
}

printf("\nSuma: %.2f", sum);
printf("\nPromedio: %.2f", (i != 0) ? sum / i : 0);

return 0;
}
