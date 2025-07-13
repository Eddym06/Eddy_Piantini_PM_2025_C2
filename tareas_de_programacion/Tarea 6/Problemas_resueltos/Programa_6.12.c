#include <stdio.h>
#define PRO 24
#define MES 12
#define ANO 10
void Lectura(float[][MES][ANO], int, int, int);
void Funcion1(float[][MES][ANO], int, int, int);
void Funcion2(float[][MES][ANO], int, int, int);
void Funcion3(float[][MES][ANO], int, int, int);
int main(void) {
float llu[PRO][MES][ANO];
Lectura(llu, PRO, MES, ANO);
Funcion1(llu, PRO, MES, ANO);
Funcion2(llu, PRO, MES, ANO);
Funcion3(llu, 18, MES, 5);
return 0;
}
void Lectura(float a[][MES][ANO], int pro, int mes, int ano) {
int k, i, j;
for (k = 0; k < ano; k++)
for (i = 0; i < pro; i++)
for (j = 0; j < mes; j++) {
printf("Ingrese la lluvia para provincia %d, mes %d, ano %d: ", i + 1, j + 1, k + 1);
if (scanf("%f", &a[i][j][k]) != 1 || a[i][j][k] < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Funcion1(float a[][MES][ANO], int pro, int mes, int ano) {
int k, i, j;
float sum, prom;
for (k = 0; k < ano; k++) {
sum = 0;
for (i = 0; i < pro; i++)
for (j = 0; j < mes; j++)
sum += a[i][j][k];
prom = sum / (pro * mes);
printf("\nPromedio de lluvia en el ano %d: %.2f", k + 1, prom);
}
}
void Funcion2(float a[][MES][ANO], int pro, int mes, int ano) {
int i, j, k;
float max_p = a[0][0][0], min_p = a[0][0][0];
int max_pro = 0, min_pro = 0, max_m = 0, min_m = 0, max_a = 0, min_a = 0;
for (i = 0; i < pro; i++)
for (j = 0; j < mes; j++)
for (k = 0; k < ano; k++) {
if (a[i][j][k] > max_p) {
max_p = a[i][j][k];
max_pro = i;
max_m = j;
max_a = k;
}
if (a[i][j][k] < min_p) {
min_p = a[i][j][k];
min_pro = i;
min_m = j;
min_a = k;
}
}
printf("\nMayor lluvia: Provincia %d, Mes %d, Ano %d, Cantidad: %.2f", max_pro + 1, max_m + 1, max_a + 1, max_p);
printf("\nMenor lluvia: Provincia %d, Mes %d, Ano %d, Cantidad: %.2f\n", min_pro + 1, min_m + 1, min_a + 1, min_p);
}
void Funcion3(float a[][MES][ANO], int pro, int mes, int ano) {
int k, j;
float sum, prom;
for (k = 0; k < ano; k++) {
sum = 0;
for (j = 0; j < mes; j++)
sum += a[pro - 1][j][k];
prom = sum / mes;
printf("\nPromedio de lluvia en provincia %d, ano %d: %.2f", pro, k + 1, prom);
}
printf("\n");
}
                                                