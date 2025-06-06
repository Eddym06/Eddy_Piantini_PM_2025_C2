#include <stdio.h>
#include <math.h>

int main() {
    int T, P, R;
    double resultado;
    
    printf("Valores de T, P, R que satisfacen 7^4T^4 - 6^4P^3 + 12^4R^5 < 5850\n");
    printf("------------------------------------------------------------------\n");
    
    // Precalcular constantes
    double siete4 = pow(7, 4);
    double seis4 = pow(6, 4);
    double doce4 = pow(12, 4);
    
    // Buscar valores posibles (limitamos el rango para evitar bucles infinitos)
    for(T = 1; T <= 5; T++) {
        for(P = 1; P <= 10; P++) {
            for(R = 1; R <= 5; R++) {
                resultado = siete4 * pow(T, 4) - seis4 * pow(P, 3) + doce4 * pow(R, 5);
                
                if(resultado < 5850) {
                    printf("T = %d, P = %d, R = %d (Resultado = %.2f)\n", T, P, R, resultado);
                }
            }
        }
    }
    
    return 0;
}