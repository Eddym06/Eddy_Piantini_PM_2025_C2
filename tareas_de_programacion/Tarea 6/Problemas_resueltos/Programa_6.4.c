#include <stdio.h>
#define MAX 100
void Lectura(int[][MAX], int);
int Simetrico(int[][MAX], int);
int main(void) {
int mat[MAX][MAX], n;
do {
printf("Ingrese el tamano del arreglo: ");
if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
printf("El tamano debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(mat, n);
if (Simetrico(mat, n))
printf("\nEl arreglo bidimensional es simetrico\n");
else
printf("\nEl arreglo bidimensional no es simetrico\n");
return 0;
}
void Lectura(int a[][MAX], int t) {
int i, j;
for (i = 0; i < t; i++)
for (j = 0; j < t; j++) {
printf("Fila: %d\tColumna: %d ", i + 1, j + 1);
if (scanf("%d", &a[i][j]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
int Simetrico(int a[][MAX], int t) {
int i = 0, j, f = 1;
while (i < t && f) {
j = 0;
while (j < i && f) {
if (a[i][j] != a[j][i])
f = 0;
j++;
}
i++;
}
return f;
}
                                    