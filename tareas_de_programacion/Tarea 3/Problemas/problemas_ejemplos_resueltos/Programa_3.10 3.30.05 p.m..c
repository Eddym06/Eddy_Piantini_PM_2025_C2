#include <stdio.h>
#include <math.h>

/* Pares e impares.
El programa, al recibir como datos N números enteros, obtiene la suma de los
números pares y calcula el promedio de los impares.

I, N, NUM, SPA, SIM, CIM: variables de tipo entero. */

void main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

    printf("Ingrese el número de datos que se van a procesar:\t");
    scanf("%d", &N);

    if (N > 0)
    {
        for (I = 1; I <= N; I++)
        {
            printf("\nIngrese el número %d: ", I);
            scanf("%d", &NUM);

            // The original condition 'if (NUM)' followed by 'if (pow(-1, NUM) > 0)'
            // is not the standard way to check for even/odd.
            // pow(-1, NUM) will be 1 for even NUM and -1 for odd NUM.
            // So, pow(-1, NUM) > 0 means NUM is even.
            // A more direct way to check for even/odd is using the modulo operator (%).
            // A number is even if NUM % 2 == 0. It's odd if NUM % 2 != 0.

            // The original code `if (NUM)` means if NUM is non-zero. If NUM is 0,
            // it skips the even/odd check, which might not be desired if 0 is considered even.

            if (NUM % 2 == 0) // Check if NUM is even
            {
                SPA = SPA + NUM;
            }
            else // NUM is odd
            {
                SIM = SIM + NUM;
                CIM++;
            }
        }

        printf("\nLa suma de los números pares es: %d", SPA);

        // Before calculating the average of odd numbers, check if CIM (count of odd numbers) is not zero
        if (CIM > 0)
        {
            printf("\nEl promedio de números impares es: %5.2f", (float)SIM / CIM);
        }
        else
        {
            printf("\nNo se ingresaron números impares para calcular el promedio.");
        }
    }
    else
    {
        printf("\nEl valor de N es incorrecto");
    }
}