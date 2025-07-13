#include <stdio.h>
#define MAX 100
void Lectura(int[], int);
void Ordena(int[], int);
void Imprime(int[], int);
int main(void) {
int tam, vec[MAX];
do {
printf("Ingrese el tamano del arreglo: ");
if (scanf("%d", &tam) != 1 || tam < 1 || tam > MAX) {
printf("El tamano debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(vec, tam);
Ordena(vec, tam);
Imprime(vec, tam);
return 0;
}
void Lectura(int a[], int t) {
int i;
for (i = 0; i < t; i++) {
printf("Ingrese el elemento %d: ", i + 1);
if (scanf("%d", &a[i]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
i--;
continue;
}
}
}
void Imprime(int a[], int t) {
int i;
for (i = 0; i < t; i++)
printf("\nA[%d]: %d", i, a[i]);
printf("\n");
}
void Ordena(int a[], int t) {
int i, l, aux;
for (i = 1; i < t; i++) {
aux = a[i];
l = i - 1;
while (l >= 0 && aux < a[l]) {
a[l + 1] = a[l];
l--;
}
a[l + 1] = aux;
}
}
                                        