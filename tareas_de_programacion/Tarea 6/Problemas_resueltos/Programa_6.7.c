#include <stdio.h>
#define PRO 15
#define MES 12
void Lectura1(int[][MES], int);
void Lectura2(float[], int);
void Funcion1(int[][MES], int, int, float[], float[]);
void Funcion2(float[], int);
void Funcion3(float[], int);
int main(void) {
int fab[PRO][MES] = {0};
float cos[PRO], ven[PRO];
Lectura1(fab, PRO);
Lectura2(cos, PRO);
Funcion1(fab, PRO, MES, cos, ven);
Funcion2(ven, PRO);
Funcion3(ven, PRO);
return 0;
}
void Lectura1(int a[][MES], int n) {
int mes, pro, can;
printf("\nIngrese mes (1-%d), tipo de producto (1-%d) y cantidad vendida (-1 para terminar): ", MES, n);
if (scanf("%d %d %d", &mes, &pro, &can) != 3 || mes < -1 || mes > MES || pro < -1 || pro > n || can < -1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
return;
}
while (mes != -1 && pro != -1 && can != -1) {
if (mes >= 1 && mes <= MES && pro >= 1 && pro <= n && can >= 0)
a[pro - 1][mes - 1] += can;
else
printf("Datos invalidos\n");
printf("\nIngrese mes (1-%d), tipo de producto (1-%d) y cantidad vendida (-1 para terminar): ", MES, n);
if (scanf("%d %d %d", &mes, &pro, &can) != 3 || mes < -1 || mes > MES || pro < -1 || pro > n || can < -1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
return;
}
}
}
void Lectura2(float c[], int n) {
int i;
for (i = 0; i < n; i++) {
printf("Ingrese el costo del producto %d: ", i + 1);
if (scanf("%f", &c[i]) != 1 || c[i] < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
i--;
continue;
}
}
}
void Funcion1(int a[][MES], int n, int m, float c[], float v[]) {
int i, j;
for (i = 0; i < n; i++) {
v[i] = 0;
for (j = 0; j < m; j++)
v[i] += a[i][j] * c[i];
}
}
void Funcion2(float v[], int n) {
int i, max_i = 0;
float max_v = v[0];
for (i = 1; i < n; i++)
if (v[i] > max_v) {
max_v = v[i];
max_i = i;
}
printf("\nProducto con mayor venta: %d, Total: %.2f\n", max_i + 1, max_v);
}
void Funcion3(float v[], int n) {
int i, min_i = 0;
float min_v = v[0];
for (i = 1; i < n; i++)
if (v[i] < min_v) {
min_v = v[i];
min_i = i;
}
printf("\nProducto con menor venta: %d, Total: %.2f\n", min_i + 1, min_v);
}
                                                        