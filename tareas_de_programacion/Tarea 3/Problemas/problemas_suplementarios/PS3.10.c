#include <stdio.h>
#include <math.h>

void calcularVentas(float preciosLoc[], int *totalBoletosLoc, float *recaudacionTotal);

void main(void) {
float precios[6];
int totalBoletos[6] = {0, 0, 0, 0, 0, 0};
float recaudacion = 0.0;

printf("Ingrese los precios de las 6 localidades:\n");
for (int i = 0; i < 6; i++) {
printf("Precio Localidad %d: ", i + 1);
scanf("%f", &precios[i]);
}

calcularVentas(precios, totalBoletos, &recaudacion);

printf("\n--- Resumen de Ventas ---\n");
for (int i = 0; i < 6; i++) {
printf("Localidad %d: %d boletos vendidos\n", i + 1, totalBoletos[i]);
}
printf("Recaudacion Total: %.2f\n", recaudacion);
}

void calcularVentas(float preciosLoc[], int *totalBoletosLoc, float *recaudacionTotal) {
int tipoLocalidad, cantidad;
float montoVenta;

printf("\nIngrese tipo de localidad y cantidad (0 0 para terminar):\n");
while (scanf("%d %d", &tipoLocalidad, &cantidad) == 2 && (tipoLocalidad != 0 || cantidad != 0)) {
if (tipoLocalidad >= 1 && tipoLocalidad <= 6) {
montoVenta = preciosLoc[tipoLocalidad - 1] * cantidad;
*recaudacionTotal += montoVenta;
totalBoletosLoc[tipoLocalidad - 1] += cantidad;
printf("Venta procesada. Monto: %.2f\n", montoVenta);
} else {
printf("Tipo de localidad invalido. Intente de nuevo.\n");
}
printf("Ingrese tipo de localidad y cantidad (0 0 para terminar):\n");
}
}
            