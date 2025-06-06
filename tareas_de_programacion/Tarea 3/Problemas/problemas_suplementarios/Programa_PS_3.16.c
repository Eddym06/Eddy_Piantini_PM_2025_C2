#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Generador de figura numerica\n");
    printf("Ingrese un numero positivo: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("El numero debe ser positivo!\n");
        return 1;
    }
    
    // Parte creciente de la figura
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    // Parte decreciente de la figura
    for(i = n-1; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    return 0;
}