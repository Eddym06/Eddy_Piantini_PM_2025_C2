#include <stdio.h>
#define MAX 100
void Lectura(int[], int);
int Busca(int[], int, int);
int main(void) {
int vec[MAX], tam, ele, res;
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
printf("\nIngrese el elemento a buscar: ");
if (scanf("%d", &ele) != 1) {
printf("Entrada invalida\n");
return 1;
}
res = Busca(vec, tam, ele);
if (res)
printf("\nEl elemento se encuentra en la posicion: %d\n", res);
else
printf("\nEl elemento no se encuentra en el arreglo\n");
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
int Busca(int a[], int t, int e) {
int i;
for (i = 0; i < t; i++)
if (a[i] == e)
return i + 1;
return 0;
}
                                