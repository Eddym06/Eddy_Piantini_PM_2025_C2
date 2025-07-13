#include <stdio.h>
#define MAX 100
void Lectura(int[], int);
void Imprime(int[], int);
void Elimina(int[], int*);
int main(void) {
int tam, arre[MAX];
do {
printf("Ingrese el tamano del arreglo: ");
if (scanf("%d", &tam) != 1 || tam < 1 || tam > MAX) {
printf("El tamano debe estar entre 1 y %d\n", MAX);
while (getchar() != '\n');
continue;
}
break;
} while (1);
Lectura(arre, tam);
Elimina(arre, &tam);
Imprime(arre, tam);
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
void Elimina(int a[], int *t) {
int i, j, k;
for (i = 0; i < *t; i++) {
for (j = i + 1; j < *t; j++) {
if (a[i] == a[j]) {
for (k = j; k < *t - 1; k++)
a[k] = a[k + 1];
(*t)--;
j--;
}
}
}
}
                                            