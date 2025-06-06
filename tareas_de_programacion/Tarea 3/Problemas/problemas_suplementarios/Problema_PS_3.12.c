#include <stdio.h>

int main() {
    int num, i, j;
    int es_primo; // Bandera para saber si es primo (1) o no (0)

    printf("Vamos a encontrar todos los numeros primos menores a un numero!\n");
    printf("Ingresa un numero entero positivo: ");
    scanf("%d", &num);

    if(num <= 1) {
        printf("Los numeros primos comienzan desde el 2. Ingresa un numero mayor.\n");
        return 0;
    }

    printf("\nNumeros primos menores a %d:\n", num);

    // Revisamos cada número desde 2 hasta num-1
    for(i = 2; i < num; i++) {
        es_primo = 1; // Suponemos que es primo al inicio

        // Comprobamos si i es divisible por algún número entre 2 y i/2
        for(j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                es_primo = 0; // No es primo
                break; // Salimos del bucle interno
            }
        }

        // Si sigue siendo primo, lo mostramos
        if(es_primo == 1) {
            printf("%d ", i);
        }
    }

    printf("\n\nListo! Esos son todos los primos menores a %d\n", num);
    return 0;
}