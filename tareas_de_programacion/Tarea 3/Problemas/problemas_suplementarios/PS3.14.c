#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double calcularFactorial(int n);
double calcularSeno(double x, int *numTerminos);

void main(void) {
double x_grados;
int terminos = 0;

printf("Ingrese un valor para X (en grados): ");
scanf("%lf", &x_grados);

double x_radianes = x_grados * M_PI / 180.0;

double seno_calculado = calcularSeno(x_radianes, &terminos);

printf("\nEl sen(%.2f grados) es: %.4f\n", x_grados, seno_calculado);
printf("Numero de terminos requeridos para la precision: %d\n", terminos);
}

double calcularFactorial(int n) {
double factorial = 1.0;
for (int i = 1; i <= n; i++) {
factorial *= i;
}
return factorial;
}

double calcularSeno(double x, int *numTerminos) {
double seno = 0.0;
double termino_actual;
int k = 0;
*numTerminos = 0;

do {
int potencia = 2 * k + 1;
if (k % 2 == 0) {
termino_actual = pow(x, potencia) / calcularFactorial(potencia);
} else {
termino_actual = -pow(x, potencia) / calcularFactorial(potencia);
}

seno += termino_actual;
(*numTerminos)++;
k++;

} while (fabs(termino_actual) > 0.001 && *numTerminos < 100);

return seno;
}
