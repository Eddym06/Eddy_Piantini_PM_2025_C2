# include <stdio.h>
/* Mayor divisor.
El programa, al recibir como dato un número entero positivo, calcula ➥ su mayor divisor. */
int mad(int); /* Prototipo de función. */
void main(void)
{
int NUM, RES;
printf(“\nIngresa el número: “); scanf(“%d”, &NUM);
RES = mad(NUM);
printf(“\nEl mayor divisor de %d es: %d”, NUM, RES); }
int mad(int N1)
/* Esta función calcula el mayor divisor del número N1. */ {