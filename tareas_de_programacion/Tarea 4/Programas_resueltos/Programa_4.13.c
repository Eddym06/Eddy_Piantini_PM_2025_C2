#include <stdio.h>
#include <math.h>
void parimp(int, int *, int *);
int main(void)
{
int I, N, NUM, PAR = 0, IMP = 0;
printf("Ingresa el numero de datos: ");
if (scanf("%d", &N) != 1 || N <= 0)
{
printf("El numero de datos debe ser positivo\n");
return 1;
}
for (I = 1; I <= N; I++)
{
printf("Ingresa el numero %d: ", I);
if (scanf("%d", &NUM) != 1)
{
printf("Entrada invalida\n");
return 1;
}
parimp(NUM, &PAR, &IMP);
}
printf("\nNumero de pares: %d", PAR);
printf("\nNumero de impares: %d", IMP);
return 0;
}
void parimp(int NUM, int *P, int *I)
{
if (pow(-1, NUM) > 0)
*P += 1;
else
*I += 1;
}
                    