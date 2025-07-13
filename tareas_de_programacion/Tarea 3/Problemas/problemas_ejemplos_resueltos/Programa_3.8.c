#include <stdio.h>
int main(void) {
int i, num;
long fac = 1;
printf("Ingrese el numero: ");
if (scanf("%d", &num) != 1 || num < 0) {
printf("Error en el dato ingresado\n");
return 1;
}
for (i = 1; i <= num; i++)
fac *= i;
printf("\nEl factorial de %d es: %ld\n", num, fac);
return 0;
}
        