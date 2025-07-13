#include <stdio.h>
#define MAX 10
void Lectura(int[][MAX], int);
void Calcula(int[][MAX], float[], int);
float Mod0(int[][MAX], int, int);
float Mod1(int[][MAX], int);
float Mod2(int[][MAX], int, int);
void Imprime(float[], int);
int main(void) {
int mat[MAX][MAX], tam;
float vec[MAX];
do {
printf("Ingrese el tamano de la matriz: ");
if (scanf("%d", &tam) != 1 || tam < 1 || tam > MAX) {
printf("El tamano debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(mat, tam);
Calcula(mat, vec, tam);
Imprime(vec, tam);
return 0;
}
void Lectura(int a[][MAX], int n) {
int i, j;
for (i = 0; i < n; i++)
for (j = 0; j < n; j++) {
printf("Ingrese el elemento %d %d: ", i + 1, j + 1);
if (scanf("%d", &a[i][j]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Calcula(int a[][MAX], float b[], int n) {
int i;
for (i = 0; i < n; i++) {
switch (i % 3) {
case 1: b[i] = Mod1(a, i); break;
case 2: b[i] = Mod2(a, i, n); break;
default: b[i] = Mod0(a, i, n); break;
}
}
}
float Mod0(int a[][MAX], int k, int m) {
int i;
float pro = 1.0, sum = 0.0;
for (i = 0; i < m; i++) {
pro *= a[i][k];
sum += a[i][k];
}
if (sum == 0) return 0;
return pro / sum;
}
float Mod1(int a[][MAX], int n) {
int i;
float sum = 0.0;
for (i = 0; i <= n; i++)
sum += a[n][i];
return sum;
}
float Mod2(int a[][MAX], int n, int m) {
int i;
float pro = 1.0;
for (i = n; i < m; i++)
pro *= a[i][n];
return pro;
}
void Imprime(float b[], int n) {
int i;
for (i = 0; i < n; i++)
printf("\nElemento %d: %.2f", i + 1, b[i]);
printf("\n");
}
                                                        