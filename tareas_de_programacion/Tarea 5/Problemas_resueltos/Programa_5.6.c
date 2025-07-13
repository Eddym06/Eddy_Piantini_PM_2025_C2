#include <stdio.h>
#include <math.h>
#define MAX 100
void Lectura(float[], int);
double Suma(float[], int);
int main(void) {
float vec[MAX];
double res;
Lectura(vec, MAX);
res = Suma(vec, MAX);
printf("\nSuma del arreglo: %.2lf\n", res);
return 0;
}
void Lectura(float a[], int t) {
int i;
for (i = 0; i < t; i++) {
printf("Ingrese el elemento %d: ", i + 1);
if (scanf("%f", &a[i]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
i--;
continue;
}
}
}
double Suma(float a[], int t) {
int i;
double sum = 0.0;
for (i = 0; i < t; i++)
sum += pow(a[i], 2);
return sum;
}
                    