#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Generador de piramide numerica\n");
    printf("Ingrese un numero positivo: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Error: El numero debe ser positivo!\n");
        return 1;
    }
    
    // Generar la pirámide
    for(i = 1; i <= n; i++) {
        // Parte creciente (1 2 3...)
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        // Parte decreciente (...3 2 1)
        for(j = i-1; j >= 1; j--) {
            printf("%d ", j);
        }
        
        printf("\n"); // Nueva línea para la siguiente fila
    }
    
    return 0;
}