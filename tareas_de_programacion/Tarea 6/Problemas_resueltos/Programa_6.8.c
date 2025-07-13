#include <stdio.h>
#define MAX 50
void Lectura(int[][MAX], int, int);
void Traspuesta(int[][MAX], int[][MAX], int, int);
void Imprime(int[][MAX], int, int);
int main(void) {
int mat[MAX][MAX], tra[MAX][MAX], fil, col;
do {
printf("Ingrese el numero de filas de la matriz: ");
if (scanf("%d", &fil) != 1 || fil < 1 || fil > MAX) {
printf("El numero de filas debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
do {
printf("Ingrese el numero de columnas de la matriz: ");
if (scanf("%d", &col) != 1 || col < 1 || col > MAX) {
printf("El numero de columnas debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(mat, fil, col);
Traspuesta(mat, tra, fil, col);
printf("\nMatriz Transpuesta\n");
Imprime(tra, col, fil);
return 0;
}
void Lectura(int a[][MAX], int f, int c) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++) {
printf("Ingrese el elemento %d %d: ", i + 1, j + 1);
if (scanf("%d", &a[i][j]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Traspuesta(int m1[][MAX], int m2[][MAX], int f, int c) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++)
m2[j][i] = m1[i][j];
}
void Imprime(int a[][MAX], int f, int c) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++)
printf("\nElemento %d %d: %d", i + 1, j + 1, a[i][j]);
printf("\n");
}
                                        