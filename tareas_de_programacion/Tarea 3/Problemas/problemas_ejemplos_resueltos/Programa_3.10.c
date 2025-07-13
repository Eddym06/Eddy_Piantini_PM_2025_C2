#include <stdio.h>
int main(void) {
int i, n, num, spa = 0, sim = 0, cim = 0;
printf("Ingrese el numero de datos que se van a procesar: ");
if (scanf("%d", &n) != 1 || n <= 0) {
printf("El valor de N es incorrecto\n");
return 1;
}
for (i = 1; i <= n; i++) {
printf("Ingrese el numero %d: ", i);
if (scanf("%d", &num) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
i--;
continue;
}
if (num % 2 == 0)
spa += num;
else {
sim += num;
cim++;
}
}
printf("\nLa suma de los numeros pares es: %d\n", spa);
if (cim > 0)
printf("El promedio de numeros impares es: %.2f\n", (float)sim / cim);
else
printf("No se ingresaron numeros impares\n");
return 0;
}
                    