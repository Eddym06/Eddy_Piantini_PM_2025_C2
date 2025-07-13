#include <stdio.h>
#define FUN 5
#define MES 12
void LecturaM(float[][MES], int, int);
void LecturaV(float[], int);
void F1(float[][MES], int, int, float[], float[]);
void F2(float[][MES], int, int);
void F3(float[], int);
int main(void) {
float pre[FUN][MES], ini[FUN], fin[FUN];
LecturaM(pre, FUN, MES);
LecturaV(ini, FUN);
F1(pre, FUN, MES, ini, fin);
F2(pre, FUN, MES);
F3(fin, FUN);
return 0;
}
void LecturaM(float a[][MES], int f, int c) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++) {
printf("Ingrese el precio del fondo %d, mes %d: ", i + 1, j + 1);
if (scanf("%f", &a[i][j]) != 1 || a[i][j] < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void LecturaV(float v[], int n) {
int i;
for (i = 0; i < n; i++) {
printf("Ingrese el precio inicial del fondo %d (31/12/2003): ", i + 1);
if (scanf("%f", &v[i]) != 1 || v[i] < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
i--;
continue;
}
}
}
void F1(float a[][MES], int f, int c, float ini[], float fin[]) {
int i;
for (i = 0; i < f; i++)
fin[i] = a[i][c - 1];
}
void F2(float a[][MES], int f, int c) {
int i, j;
float max_p = a[0][0], min_p = a[0][0];
int max_f = 0, min_f = 0, max_m = 0, min_m = 0;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++) {
if (a[i][j] > max_p) {
max_p = a[i][j];
max_f = i;
max_m = j;
}
if (a[i][j] < min_p) {
min_p = a[i][j];
min_f = i;
min_m = j;
}
}
printf("\nFondo con precio maximo: %d, Mes: %d, Precio: %.2f", max_f + 1, max_m + 1, max_p);
printf("\nFondo con precio minimo: %d, Mes: %d, Precio: %.2f\n", min_f + 1, min_m + 1, min_p);
}
void F3(float fin[], int n) {
int i, max_i = 0, min_i = 0;
float max_v = fin[0], min_v = fin[0];
for (i = 1; i < n; i++) {
if (fin[i] > max_v) {
max_v = fin[i];
max_i = i;
}
if (fin[i] < min_v) {
min_v = fin[i];
min_i = i;
}
}
printf("\nFondo con mayor precio final: %d, Precio: %.2f", max_i + 1, max_v);
printf("\nFondo con menor precio final: %d, Precio: %.2f\n", min_i + 1, min_v);
}
                                                                