#include <stdio.h>

void dibujarFigura(int N);

void main(void) {
int N;

printf("Ingrese un numero entero positivo: ");
scanf("%d", &N);

if (N <= 0) {
printf("El numero debe ser positivo.\n");
return;
}

dibujarFigura(N);
}

void dibujarFigura(int N) {
for (int i = 1; i <= N; i++) {
for (int j = 1; j <= i; j++) {
printf("%d ", j);
}
printf("\n");
}

for (int i = N - 1; i >= 1; i--) {
for (int j = 1; j <= i; j++) {
printf("%d ", j);
}
printf("\n");
}
}
        