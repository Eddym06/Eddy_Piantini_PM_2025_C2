#include <stdio.h>
#define MAX 10
void Lectura(int[], int);
void Imprime(int[], int);
void Producto(int[], int[], int[], int);
int main(void) {
int ve1[MAX], ve2[MAX], ve3[MAX];
Lectura(ve1, MAX);
Lectura(ve2, MAX);
Producto(ve1, ve2, ve3, MAX);
printf("\nProducto de los Vectores\n");
Imprime(ve3, MAX);
return 0;
}
void Lectura(int vec[], int t) {
int i;
for (i = 0; i < t; i++) {
printf("Ingrese el elemento %d: ", i + 1);
if (scanf("%d", &vec[i]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
i--;
continue;
}
}
}
void Imprime(int vec[], int t) {
int i;
for (i = 0; i < t; i++)
printf("\nVEC[%d]: %d", i + 1, vec[i]);
printf("\n");
}
void Producto(int x[], int y[], int z[], int t) {
int i;
for (i = 0; i < t; i++)
z[i] = x[i] * y[i];
}
                        