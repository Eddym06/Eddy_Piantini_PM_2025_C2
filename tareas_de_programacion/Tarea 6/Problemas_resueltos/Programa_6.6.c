#include <stdio.h>
#define MAX 50
void Lectura(float[][MAX], int, int);
void Intercambia(float[][MAX], int, int);
void Imprime(float[][MAX], int, int);
int main(void) {
int fil, col;
float mat[MAX][MAX];
do {
printf("Ingrese el numero de filas del arreglo: ");
if (scanf("%d", &fil) != 1 || fil < 1 || fil > MAX) {
printf("El numero de filas debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
do {
printf("Ingrese el numero de columnas del arreglo: ");
if (scanf("%d", &col) != 1 || col < 1 || col > MAX) {
printf("El numero de columnas debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(mat, fil, col);
Intercambia(mat, fil, col);
Imprime(mat, fil, col);
return 0;
}
void Lectura(float a[][MAX], int f, int c) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++) {
printf("Ingrese el elemento %d %d: ", i + 1, j + 1);
if (scanf("%f", &a[i][j]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Intercambia(float a[][MAX], int f, int c) {
int i, j;
float aux;
for (i = 0; i < c / 2; i++)
for (j = 0; j < f; j++) {
aux = a[j][i];
a[j][i] = a[j][c - i - 1];
a[j][c - i - 1] = aux;
}
}
void Imprime(float a[][MAX], int f, int c) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++)
printf("\nElemento %d %d: %.2f", i + 1, j + 1, a[i][j]);
printf("\n");
}
                                            