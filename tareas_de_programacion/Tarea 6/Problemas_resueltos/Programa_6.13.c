#include <stdio.h>
#define MES 12
#define DEP 3
#define ANO 8
void Lectura(float[][DEP][ANO], int, int, int);
void Funcion1(float[][DEP][ANO], int, int, int);
void Funcion2(float[][DEP][ANO], int, int, int);
void Funcion3(float[][DEP][ANO], int, int, int);
int main(void) {
float pro[MES][DEP][ANO];
Lectura(pro, MES, DEP, ANO);
Funcion1(pro, MES, DEP, 2);
Funcion2(pro, MES, DEP, ANO);
Funcion3(pro, MES, DEP, ANO);
return 0;
}
void Lectura(float a[][DEP][ANO], int f, int c, int p) {
int k, i, j;
for (k = 0; k < p; k++)
for (i = 0; i < f; i++)
for (j = 0; j < c; j++) {
printf("Ingrese las ventas para mes %d, departamento %d, ano %d: ", i + 1, j + 1, k + 1);
if (scanf("%f", &a[i][j][k]) != 1 || a[i][j][k] < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Funcion1(float a[][DEP][ANO], int f, int c, int p) {
int i, j;
float sum;
for (i = 0; i < f; i++) {
sum = 0;
for (j = 0; j < c; j++)
sum += a[i][j][p - 1];
printf("\nVentas totales en mes %d, ano %d: %.2f", i + 1, p, sum);
}
}
void Funcion2(float a[][DEP][ANO], int f, int c, int p) {
int j, k, i;
float sum, prom;
for (j = 0; j < c; j++) {
sum = 0;
for (k = 0; k < p; k++)
for (i = 0; i < f; i++)
sum += a[i][j][k];
prom = sum / (f * p);
printf("\nPromedio de ventas del departamento %d: %.2f", j + 1, prom);
}
printf("\n");
}
void Funcion3(float a[][DEP][ANO], int f, int c, int p) {
int i, j, k;
float max_v = a[0][0][0], min_v = a[0][0][0];
int max_m = 0, min_m = 0, max_d = 0, min_d = 0, max_a = 0, min_a = 0;
for (k = 0; k < p; k++)
for (i = 0; i < f; i++)
for (j = 0; j < c; j++) {
if (a[i][j][k] > max_v) {
max_v = a[i][j][k];
max_m = i;
max_d = j;
max_a = k;
}
if (a[i][j][k] < min_v) {
min_v = a[i][j][k];
min_m = i;
min_d = j;
min_a = k;
}
}
printf("\nMayor venta: Mes %d, Departamento %d, Ano %d, Cantidad: %.2f", max_m + 1, max_d + 1, max_a + 1, max_v);
printf("\nMenor venta: Mes %d, Departamento %d, Ano %d, Cantidad: %.2f\n", min_m + 1, min_d + 1, min_a + 1, min_v);
}
