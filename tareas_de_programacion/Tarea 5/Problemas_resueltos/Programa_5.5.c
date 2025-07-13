#include <stdio.h>
#define TAM 50
void Lectura(int[], int);
void Frecuencia(int[], int, int[], int);
void Impresion(int[], int);
void Mayor(int[], int);
int main(void) {
int cal[TAM], fre[6] = {0};
Lectura(cal, TAM);
Frecuencia(cal, TAM, fre, 6);
printf("\nFrecuencia de Calificaciones\n");
Impresion(fre, 6);
Mayor(fre, 6);
return 0;
}
void Lectura(int vec[], int t) {
int i;
for (i = 0; i < t; i++) {
printf("Ingrese la calificacion (0-5) del alumno %d: ", i + 1);
if (scanf("%d", &vec[i]) != 1 || vec[i] < 0 || vec[i] > 5) {
printf("Entrada invalida, ingrese un valor entre 0 y 5\n");
while (getchar() != '\n');
i--;
continue;
}
}
}
void Impresion(int vec[], int t) {
int i;
for (i = 0; i < t; i++)
printf("\nCalificacion %d: %d", i, vec[i]);
printf("\n");
}
void Frecuencia(int a[], int p, int b[], int t) {
int i;
for (i = 0; i < p; i++)
if (a[i] >= 0 && a[i] < 6)
b[a[i]]++;
}
void Mayor(int x[], int t) {
int i, mfre = 0, mval = x[0];
for (i = 1; i < t; i++)
if (x[i] > mval) {
mval = x[i];
mfre = i;
}
printf("\nMayor frecuencia de calificaciones: %d \tValor: %d\n", mfre, mval);
}
                                