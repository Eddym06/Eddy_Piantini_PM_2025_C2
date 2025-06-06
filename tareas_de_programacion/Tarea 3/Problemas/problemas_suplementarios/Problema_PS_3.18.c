#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Generador de figura en V invertida\n");
    printf("Ingrese un numero positivo: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Error: El numero debe ser positivo!\n");
        return 1;
    }
    
    // Generar la figura
    for(i = n; i >= 1; i--) {
        // Parte izquierda (ascendente)
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        // Espacios en el centro
        for(j = 1; j <= 2*(n-i); j++) {
            printf("  "); // Dos espacios por cada posición
        }
        
        // Parte derecha (descendente)
        for(j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        
        printf("\n"); // Nueva línea para la siguiente fila
    }
    
    return 0;
}