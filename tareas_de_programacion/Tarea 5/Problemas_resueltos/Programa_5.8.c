#include <stdio.h>
#include <math.h>
#define TAM 100
void Imprime(int[], int);
void Primo(int, int*);
int main(void) {
int p[TAM] = {0}, fla, j = 2, pri = 3;
p[0] = 1;
p[1] = 2;
while (j < TAM) {
fla = 1;
Primo(pri, &fla);
if (fla) {
p[j] = pri;
j++;
}
pri += 2;
}
Imprime(p, TAM);
return 0;
}
void Primo(int a, int *b) {
int di = 3;
while (*b && di <= sqrt(a)) {
if (a % di == 0)
*b = 0;
di += 2;
}
}
void Imprime(int primos[], int t) {
int i;
for (i = 0; i < t; i++)
if (primos[i])
printf("\nPrimos[%d]: %d", i, primos[i]);
printf("\n");
}
                        