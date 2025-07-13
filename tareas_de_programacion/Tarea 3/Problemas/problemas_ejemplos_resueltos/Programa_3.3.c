#include <stdio.h>
int main(void) {
float pag, spa = 0;
printf("Ingrese el primer pago: ");
if (scanf("%f", &pag) != 1 || pag < 0) {
printf("Entrada invalida\n");
return 1;
}

while (pag) {
spa += pag;
printf("Ingrese el siguiente pago: ");
if (scanf("%f", &pag) != 1 || pag < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
continue;
}
}
printf("\nEl total de pagos del mes es: %.2f\n", spa);
return 0;
}
