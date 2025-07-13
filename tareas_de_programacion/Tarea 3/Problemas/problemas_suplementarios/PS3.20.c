#include <stdio.h>
#include <math.h>

int verificarExpresion(int T, int P, int R);

void main(void) {
int T, P, R;
int contadorSoluciones = 0;

printf("Valores positivos de T, P, R que satisfacen la expresion 7*T^4 - 6*P^3 + 12*R^5 < 5850:\n");

for (T = 1; T <= 5; T++) {
for (P = 1; P <= 5; P++) {
for (R = 1; R <= 5; R++) {
if (verificarExpresion(T, P, R)) {
printf("T=%d, P=%d, R=%d\n", T, P, R);
contadorSoluciones++;
}
}
}
}

printf("\nTotal de soluciones encontradas: %d\n", contadorSoluciones);
}

int verificarExpresion(int T, int P, int R) {
double resultado = 7.0 * pow(T, 4) - 6.0 * pow(P, 3) + 12.0 * pow(R, 5);
return (resultado < 5850);
}
    