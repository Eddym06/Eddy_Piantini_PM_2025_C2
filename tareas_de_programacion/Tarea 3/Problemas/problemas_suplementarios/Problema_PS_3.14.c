#include <stdio.h>
#include <math.h> // Para usar la función pow y factorial

// Función para calcular factorial
long factorial(int n) {
    long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    double x, senx = 0, termino, diferencia;
    int n = 0; // Contador de términos
    int signo = 1; // Alterna entre 1 y -1
    
    printf("Calculo del sen(x) usando series de Taylor\n");
    printf("Ingrese el valor de x (en radianes): ");
    scanf("%lf", &x);
    
    printf("\nCalculando sen(%.4f)...\n", x);
    
    do {
        // Calculamos cada término de la serie: (-1)^n * x^(2n+1) / (2n+1)!
        termino = signo * pow(x, 2*n + 1) / factorial(2*n + 1);
        
        senx += termino; // Sumamos el término a la aproximación
        
        // Calculamos la diferencia con el término anterior
        diferencia = fabs(termino);
        
        printf("Termino %d: %.6f (Diferencia: %.6f)\n", n+1, termino, diferencia);
        
        signo *= -1; // Alternamos el signo
        n++; // Incrementamos el contador de términos
        
    } while(diferencia > 0.001); // Continuamos hasta alcanzar la precisión
    
    printf("\nRESULTADOS:\n");
    printf("sen(%.4f) ≈ %.6f\n", x, senx);
    printf("Terminos requeridos: %d\n", n);
    printf("Valor real de sen(%.4f) = %.6f\n", x, sin(x));
    printf("Diferencia con math.h: %.6f\n", fabs(senx - sin(x)));
    
    return 0;
}