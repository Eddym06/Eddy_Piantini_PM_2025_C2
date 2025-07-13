#include <stdio.h>
#define TAM 10
void Lectura(int[][TAM], int);
void Imprime(int[][TAM], int);
int main(void) {
int mat[TAM][TAM];
int fil;
do {
printf("Ingrese el tamano de la matriz (1-%d): ", TAM);
if (scanf("%d", &fil) != 1 || fil < 1 || fil > TAM) {
printf("El tamano debe estar entre 1 y %d\n", TAM);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(mat, fil);
Imprime(mat, fil);
return 0;
}
void Lectura(int a[][TAM], int f) {
int i, j;
for (i = 0; i < f; i++)
for (j = 0; j < f; j++) {
printf("Ingrese el elemento %d %d: ", i + 1, j + 1);
if (scanf("%d", &a[i][j]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Imprime(int a[][TAM], int f) {
int i;
for (i = 0; i < f; i++)
printf("\nElemento diagonal %d: %d", i + 1, a[i][i]);
printf("\n");
}
                            