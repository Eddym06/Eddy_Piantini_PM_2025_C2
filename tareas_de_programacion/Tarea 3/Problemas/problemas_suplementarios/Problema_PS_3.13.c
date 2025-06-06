#include <stdio.h>

// Función mejorada para verificar primos
int esPrimo(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N1, N2;
    
    printf("BUSCADOR DE PRIMOS GEMELOS\n");
    printf("--------------------------\n");
    
    // Validación de entrada para N1
    do {
        printf("Ingrese el primer numero (N1 > 1): ");
        scanf("%d", &N1);
        if (N1 <= 1) printf("Error: N1 debe ser mayor que 1\n");
    } while (N1 <= 1);
    
    // Validación de entrada para N2
    do {
        printf("Ingrese el segundo numero (N2 > N1): ");
        scanf("%d", &N2);
        if (N2 <= N1) printf("Error: N2 debe ser mayor que N1\n");
    } while (N2 <= N1);
    
    printf("\nAnalizando rango %d-%d...\n\n", N1, N2);
    
    int parejas = 0;
    
    // Buscamos primos gemelos
    for (int i = N1; i <= N2 - 2; i++) {
        if (esPrimo(i) && esPrimo(i + 2)) {
            printf("Pareja %d: %d y %d\n", ++parejas, i, i + 2);
            i++; // Saltamos el siguiente para evitar solapamiento
        }
    }
    
    // Resultados finales
    printf("\nRESULTADOS:\n");
    printf("Rango analizado: %d a %d\n", N1, N2);
    printf("Total parejas encontradas: %d\n", parejas);
    
    if (parejas == 0) {
        printf("No se encontraron primos gemelos en este rango\n");
    }
    
    return 0;
}