#include <stdio.h>

/* Suma pagos.
El programa obtiene la suma de los pagos realizados el último mes.

PAG y SPA: variables de tipo real.*/

void main(void)
{
    float PAG, SPA = 0;

    printf("Ingrese el primer pago:\t");
    scanf("%f", &PAG);

    /* Observa que al utilizar la estructura do-while al menos se necesita un pago.*/

    do
    {
        SPA = SPA + PAG;
        printf("Ingrese el siguiente pago -0 para terminar-:\t ");
        scanf("%f", &PAG);
    } while (PAG); // This 'while' condition will cause an infinite loop if PAG is never 0 after the first input. 
                   // The intention seems to be to sum payments until a 0 is entered, but the initial 'scanf'
                   // is outside the loop. If the first input is 0, the 'do-while' block will still execute once.
                   // A common pattern for reading input until a sentinel value (like 0) is this:

    // --- Alternative implementation for clarity if the goal is to sum all payments until 0 is entered,
    // --- including the first one:
    /*
    float PAG, SPA = 0;
    do {
        printf("Ingrese un pago (0 para terminar):\t");
        scanf("%f", &PAG);
        if (PAG != 0) {
            SPA = SPA + PAG;
        }
    } while (PAG != 0);
    */

    printf("\nEl total de pagos del mes es: %.2f", SPA);
}