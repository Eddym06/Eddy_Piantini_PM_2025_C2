#include <stdio.h>
#include <math.h>

/* Serie de ULAM.
El programa, al recibir como dato un entero positivo, obtiene y escribe
la serie de ULAM.

NUM: variable de tipo entero. */

void main(void)
{
    int NUM;

    printf("Ingresa el número para calcular la serie: ");
    scanf("%d", &NUM);

    if (NUM > 0)
    {
        printf("\nSerie de ULAM\n");
        printf("%d \t", NUM);
        while (NUM != 1)
        {
            // The condition `if (pow(-1, NUM) > 0)` checks if NUM is even.
            // pow(-1, NUM) is 1 if NUM is even, and -1 if NUM is odd.
            // A more direct way to check for even/odd is using the modulo operator (%).
            if (NUM % 2 == 0) // If NUM is even
                NUM = NUM / 2;
            else // If NUM is odd
                NUM = NUM * 3 + 1;
            printf("%d \t", NUM);
        }
    }
    else
    {
        printf("\n NUM debe ser un entero positivo");
    }
}