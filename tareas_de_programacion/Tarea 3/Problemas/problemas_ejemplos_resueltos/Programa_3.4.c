#include <stdio.h>
#include <math.h>
int main(void) {
int num;
long cua, suc = 0;
printf("Ingrese un numero entero (0 para terminar): ");
if (scanf("%d", &num) != 1) {
printf("Entrada invalida\n");
return 1;
}
while (num) {
cua = pow(num, 2);
printf("%d al cuadrado es %ld\n", num, cua);
suc += cua;
printf("Ingrese un numero entero (0 para terminar): ");
if (scanf("%d", &num) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
continue;
}
}
printf("\nLa suma de los cuadrados es: %ld\n", suc);
return 0;
}
                