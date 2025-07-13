#include <stdio.h>

int calcularMCD(int a, int b);

void main(void) {
int N1, N2, resultadoMCD;

printf("Ingrese el primer numero natural (N1): ");
scanf("%d", &N1);
printf("Ingrese el segundo numero natural (N2): ");
scanf("%d", &N2);

if (N1 <= 0 || N2 <= 0) {
printf("Ambos numeros deben ser naturales (positivos).\n");
return;
}

resultadoMCD = calcularMCD(N1, N2);
printf("El Maximo Comun Divisor (MCD) de %d y %d es: %d\n", N1, N2, resultadoMCD);
}

int calcularMCD(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
        