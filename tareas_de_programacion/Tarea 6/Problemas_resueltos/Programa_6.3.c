#include <stdio.h>
#define F 8
#define C 2
#define P 5
void Lectura(int[][C][P], int, int, int);
void Funcion1(int[][C][P], int, int, int);
void Funcion2(int[][C][P], int, int, int);
void Funcion3(int[][C][P], int, int, int);
int main(void) {
int uni[F][C][P];
Lectura(uni, F, C, P);
Funcion1(uni, F, C, P);
Funcion2(uni, F, C, P);
Funcion3(uni, 6, C, P);
return 0;
}
void Lectura(int a[][C][P], int fi, int co, int pr) {
int k, i, j;
for (k = 0; k < pr; k++)
for (i = 0; i < fi; i++)
for (j = 0; j < co; j++) {
printf("Ano: %d\tCarrera: %d\tSemestre: %d ", k + 1, i + 1, j + 1);
if (scanf("%d", &a[i][j][k]) != 1 || a[i][j][k] < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
j--;
continue;
}
}
}
void Funcion1(int a[][C][P], int fi, int co, int pr) {
int k, i, j, may = 0, ao = -1, sum;
for (k = 0; k < pr; k++) {
sum = 0;
for (i = 0; i < fi; i++)
for (j = 0; j < co; j++)
sum += a[i][j][k];
if (sum > may) {
may = sum;
ao = k;
}
}
if (ao == -1)
printf("\nNo se ingresaron datos validos\n");
else
printf("\nAno con mayor ingreso de alumnos: %d Alumnos: %d\n", ao + 1, may);
}
void Funcion2(int a[][C][P], int fi, int co, int pr) {
int i, j, may = 0, car = -1, sum;
for (i = 0; i < fi; i++) {
sum = 0;
for (j = 0; j < co; j++)
sum += a[i][j][pr - 1];
if (sum > may) {
may = sum;
car = i;
}
}
if (car == -1)
printf("\nNo se ingresaron datos validos\n");
else
printf("\nCarrera con mayor numero de alumnos: %d Alumnos: %d\n", car + 1, may);
}
void Funcion3(int a[][C][P], int fi, int co, int pr) {
int k, j, may = 0, ao = -1, sum;
for (k = 0; k < pr; k++) {
sum = 0;
for (j = 0; j < co; j++)
sum += a[fi - 1][j][k];
if (sum > may) {
may = sum;
ao = k;
}
}
if (ao == -1)
printf("\nNo se ingresaron datos validos\n");
else
printf("\nAno con mayor ingreso de alumnos en carrera %d: %d Alumnos: %d\n", fi, ao + 1, may);
}
                                                    