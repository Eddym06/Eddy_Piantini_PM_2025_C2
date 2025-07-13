#include <stdio.h>
#define MAX 50
#define EXA 4
void Lectura(float[][EXA], int);
void Funcion1(float[][EXA], int);
void Funcion2(float[][EXA], int);
int main(void) {
int n;
float mat[MAX][EXA];
do {
printf("Ingrese el numero de alumnos (1-%d): ", MAX);
if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
printf("El numero debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(mat, n);
Funcion1(mat, n);
Funcion2(mat, n);
return 0;
}
void Lectura(float a[][EXA], int n) {
int i, j;
for (i = 0; i < n; i++)
for (j = 0; j < EXA; j++) {
printf("Ingrese la calificacion %d del alumno %d: ", j + 1, i + 1);
if (scanf("%f", &a[i][j]) != 1 || a[i][j] < 0 || a[i][j] > 10) {
printf("Entrada invalida, ingrese un valor entre 0 y 10\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Funcion1(float a[][EXA], int n) {
int i, j;
float sum, prom;
for (i = 0; i < n; i++) {
sum = 0;
for (j = 0; j < EXA; j++)
sum += a[i][j];
prom = sum / EXA;
printf("\nPromedio del alumno %d: %.2f", i + 1, prom);
}
}
void Funcion2(float a[][EXA], int n) {
int i, j;
float sum, prom;
for (j = 0; j < EXA; j++) {
sum = 0;
for (i = 0; i < n; i++)
sum += a[i][j];
prom = sum / n;
printf("\nPromedio de la materia %d: %.2f", j + 1, prom);
}
printf("\n");
}
                                        