#include <stdio.h>

void leerProduccion(int N, float produccion[][4]);
void calcularTotales(int N, float produccion[][4]);

void main(void) {
int N;
printf("Ingrese el numero de anios para la produccion de vino: ");
scanf("%d", &N);

if (N <= 0) {
printf("El numero de anios debe ser positivo.\n");
return;
}

float produccion[N][4];

leerProduccion(N, produccion);
calcularTotales(N, produccion);
}

void leerProduccion(int N, float produccion[][4]) {
printf("Ingrese las cantidades de litros de vino:\n");
for (int i = 0; i < N; i++) {
printf("--- Anio %d ---\n", i + 1);
for (int j = 0; j < 4; j++) {
printf("Tipo %d: ", j + 1);
scanf("%f", &produccion[i][j]);
}
}
}

void calcularTotales(int N, float produccion[][4]) {
float totalPorTipo[4] = {0.0, 0.0, 0.0, 0.0};
float totalAnual = 0.0;

printf("\n--- Totales de Produccion ---\n");

for (int j = 0; j < 4; j++) {
for (int i = 0; i < N; i++) {
totalPorTipo[j] += produccion[i][j];
}
printf("Total Producido Tipo %d: %.2f litros\n", j + 1, totalPorTipo[j]);
}

for (int i = 0; i < N; i++) {
float sumaAnio = 0.0;
for (int j = 0; j < 4; j++) {
sumaAnio += produccion[i][j];
}
printf("Produccion Total Anio %d: %.2f litros\n", i + 1, sumaAnio);
totalAnual += sumaAnio;
}
printf("Produccion Total General de todos los anios: %.2f litros\n", totalAnual);
}
        