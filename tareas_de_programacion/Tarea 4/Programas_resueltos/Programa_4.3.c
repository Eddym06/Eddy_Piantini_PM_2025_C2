#include <stdio.h>
/* Conflicto de variables con el mismo nombre. */
void f1(void); /* Prototipo de función. */ int K = 5; /* Variable global. */
void main (void) {
int I;
for (I = 1; I <= 3; I++)
f1(); }
void f1(void)
/* La función utiliza tanto la variable local I como la variable global K. */
{
    int k_local = 2; /* Variable local. */
    k_local += k_local;
    printf("\n\nEl valor de la variable local es: %d", k_local);
    K = K + k_local; /* Uso de ambas variables. */
    printf("\nEl valor de la variable global es: %d", K);
}