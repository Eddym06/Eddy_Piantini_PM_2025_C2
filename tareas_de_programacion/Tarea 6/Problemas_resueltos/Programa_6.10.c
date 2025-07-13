#include <stdio.h>
#define MAX 50
void Cuadrado(int[][MAX], int);
void Imprime(int[][MAX], int);
int main(void) {
int cma[MAX][MAX], tam;
do {
printf("Ingrese el tamano impar de la matriz: ");
if (scanf("%d", &tam) != 1 || tam < 1 || tam > MAX || tam % 2 == 0) {
printf("El tamano debe ser impar y estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Cuadrado(cma, tam);
Imprime(cma, tam);
return 0;
}
void Cuadrado(int a[][MAX], int n) {
int i = 1, fil = 0, col = n / 2, num = n * n;
int k, j;
for (k = 0; k < n; k++)
for (j = 0; j < n; j++)
a[k][j] = 0;
while (i <= num) {
a[fil][col] = i;
if (i % n != 0) {
fil = (fil - 1 + n) % n;
col = (col + 1) % n;
} else
fil++;
i++;
}
}
void Imprime(int a[][MAX], int n) {
int i, j;
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
printf("\nElemento %d %d: %d", i + 1, j + 1, a[i][j]);
printf("\n");
}
                            