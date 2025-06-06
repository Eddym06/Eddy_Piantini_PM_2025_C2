#include <stdio.h>

int main() {
    int filas = 10; // Número fijo de filas para este patrón
    int i, j, num;
    
    printf("Piramide numerica especial\n\n");
    
    for(i = 1; i <= filas; i++) {
        // Parte creciente
        num = i % 10;
        for(j = 1; j <= i; j++) {
            printf("%d", num);
            num = (num + 1) % 10;
        }
        
        // Parte decreciente
        num = (num - 2 + 10) % 10;
        for(j = 1; j < i; j++) {
            printf("%d", num);
            num = (num - 1 + 10) % 10;
        }
        
        printf("\n");
    }
    
    return 0;
}