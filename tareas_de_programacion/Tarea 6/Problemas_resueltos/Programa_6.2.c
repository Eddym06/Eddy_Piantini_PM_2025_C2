#include <stdio.h>
#define MAX 50
void Lectura(int[][MAX], int, int);
void Suma(int[][MAX], int[][MAX], int[][MAX], int, int);
void Imprime(int[][MAX], int, int);
int main(void) {
int ma[MAX][MAX], mb[MAX][MAX], mc[MAX][MAX], fil, col;
do {
printf("Ingrese el numero de filas de los arreglos: ");
if (scanf("%d", &fil) != 1 || fil < 1 || fil > MAX) {
printf("El numero de filas debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
do {
printf("Ingrese el numero de columnas de los arreglos: ");
if (scanf("%d", &col) != 1 || col < 1 || col > MAX) {
printf("El numero de columnas debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
printf("\nLectura del Arreglo MA\n");
Lectura(ma, fil, col);
printf("\nLectura del Arreglo MB\n");
Lectura(mb, fil, col);
Suma(ma, mb, mc, fil, col);
printf("\nSuma de los Arreglos\n");
Imprime(mc, fil, col);
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
void Suma(int a[][MAX], int b[][MAX], int c[][MAX], int f, int c1) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c1; j++)
c[i][j] = a[i][j] + b[i][j];
}
void Imprime(int a[][MAX], int f, int c) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < c; j++)
printf("\nElemento %d %d: %d", i + 1, j + 1, a[i][j]);
printf("\n");
}
                                        