#include <stdio.h>
#include <ctype.h>

int main(void) {
char p, cad[50];
int n;
printf("\nIngrese la cadena de caracteres (maximo 50): ");
fgets(cad, sizeof(cad), stdin);
cad[strcspn(cad, "\n")] = 0;
printf("\nIngrese la posicion en la cadena que desea verificar: ");
scanf("%d", &n);
if (n >= 1 && n <= 50) {
p = cad[n-1];
if (islower(p)) {
printf("\n%c es una letra minuscula", p);
} else {
printf("\n%c no es una letra minuscula", p);
}
} else {
printf("\nEl valor ingresado de n es incorrecto");
}
return 0;
}
                    