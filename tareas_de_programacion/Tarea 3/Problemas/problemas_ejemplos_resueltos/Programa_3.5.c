#include <stdio.h>
int main(void) {
float pag, spa = 0;
printf("Ingrese el primer pago: ");
if (scanf("%f", &pag) != 1 || pag < 0) {
printf("Entrada invalida\n");
return 1;
}
do {
spa += pag;
printf("Ingrese el siguiente pago (0 para terminar): ");
if (scanf("%f", &pag) != 1 || pag < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
continue;
}
} while (pag);
printf("\nEl total de pagos del mes es: %.2f\n", spa);
return 0;
}
                