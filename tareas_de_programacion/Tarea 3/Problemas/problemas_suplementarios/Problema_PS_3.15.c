#include <stdio.h>

int main() {
    int N1, N2, temp;
    
    printf("CALCULADORA DE MAXIMO COMUN DIVISOR (MCD)\n");
    printf("----------------------------------------\n");
    
    // Pedir los dos números
    printf("Ingrese el primer numero (N1): ");
    scanf("%d", &N1);
    printf("Ingrese el segundo numero (N2): ");
    scanf("%d", &N2);
    
    // Validar que sean números positivos
    if (N1 <= 0 || N2 <= 0) {
        printf("\nError: Ambos numeros deben ser naturales (positivos)!\n");
        return 1;
    }
    
    // Algoritmo de Euclides para calcular MCD
    printf("\nCalculando MCD(%d, %d)...\n", N1, N2);
    
    while (N2 != 0) {
        temp = N2;
        N2 = N1 % N2;
        N1 = temp;
        
        // Mostrar paso intermedio (opcional)
        printf("Paso: N1 = %d, N2 = %d\n", N1, N2);
    }
    
    printf("\nRESULTADO:\n");
    printf("El MCD es: %d\n", N1);
    
    return 0;
}