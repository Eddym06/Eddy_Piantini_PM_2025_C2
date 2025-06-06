#include <stdio.h>

/* Lanzamiento de martillo.
El programa, al recibir como dato N lanzamientos de martillo, calcula el promedio
de los lanzamientos de la atleta cubana.

I, N: variables de tipo entero.
LAN, SLA: variables de tipo real. */

void main(void)
{
    int I, N;
    float LAN, SLA = 0;

    do
    {
        printf("Ingrese el número de lanzamientos:\t");
        scanf("%d", &N);
    } while (N < 1 || N > 11); // Corrected logical OR operator

    /* Se utiliza la estructura do-while para verificar que el valor de N sea
    correcto. */
    for (I = 1; I <= N; I++)
    {
        printf("\nIngrese el lanzamiento %d: ", I);
        scanf("%f", &LAN);
        SLA = SLA + LAN;
    }

    // Check to prevent division by zero in case N somehow becomes 0, though the do-while prevents N < 1
    if (N > 0) {
        SLA = SLA / N;
    } else {
        SLA = 0; // Or handle as an error if N is unexpectedly 0
    }


    printf("\nEl promedio de lanzamientos es: %.2f", SLA);
}