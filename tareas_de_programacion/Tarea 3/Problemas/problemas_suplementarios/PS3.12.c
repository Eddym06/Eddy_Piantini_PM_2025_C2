#include <stdio.h>

int esPrimo(int num);

void main(void) {
int num;
printf("Ingrese un numero entero positivo: ");
scanf("%d", &num);

if (num <= 1) {
printf("No hay numeros primos menores que %d (o es un valor invalido).\n", num);
return;
}

printf("Numeros primos menores que %d:\n", num);
for (int i = 2; i < num; i++) {
if (esPrimo(i)) {
printf("%d\n", i);
}
}
}

int esPrimo(int num) {
if (num <= 1) {
return 0;
}
for (int i = 2; i * i <= num; i++) {
if (num % i == 0) {
return 0;
}
}
return 1;
}
                