#include <stdio.h>
int main(void) {
int i, j, num, sum, c = 0;
printf("Ingrese el numero limite: ");
if (scanf("%d", &num) != 1 || num < 1) {
printf("Entrada invalida\n");
return 1;
}
for (i = 1; i <= num; i++) {
sum = 0;
for (j = 1; j <= i / 2; j++)
if (i % j == 0)
sum += j;
if (sum == i) {
printf("\n%d es un numero perfecto", i);
c++;
}
}
printf("\nEntre 1 y %d hay %d numeros perfectos\n", num, c);
return 0;
}
                