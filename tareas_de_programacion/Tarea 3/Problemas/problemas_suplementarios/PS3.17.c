#include <stdio.h>

void dibujarPiramidePalindromo(int N);

void main(void) {
int N;

printf("Ingrese un numero entero positivo: ");
scanf("%d", &N);

if (N <= 0) {
printf("El numero debe ser positivo.\n");
return;
}

dibujarPiramidePalindromo(N);
}

void dibujarPiramidePalindromo(int N) {
for (int i = 1; i <= N; i++) {
for (int j = 1; j <= i; j++) {
printf("%d ", j);
}
for (int j = i - 1; j >= 1; j--) {
printf("%d ", j);
}
printf("\n");
}
}
                