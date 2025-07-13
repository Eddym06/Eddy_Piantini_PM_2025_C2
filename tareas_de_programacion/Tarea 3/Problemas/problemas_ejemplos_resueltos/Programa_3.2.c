#include <stdio.h>
int main(void) {
int i, n, num, sum = 0;
printf("Ingrese el numero de datos: ");
if (scanf("%d", &n) != 1 || n <= 0) {
printf("Numero de datos invalido\n");
return 1;
}
for (i = 1; i <= n; i++) {
printf("Ingrese el dato numero %d: ", i);
if (scanf("%d", &num) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
i--;
continue;
}
if (num > 0)
sum += num;
}
printf("\nLa suma de los numeros positivos es: %d\n", sum);
return 0;
}
                