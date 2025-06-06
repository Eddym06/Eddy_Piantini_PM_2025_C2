#include <stdio.h>

int main() {
    int anios, i, j;
    float produccion[10][5]; // Máximo 10 años y 4 tipos de vino
    float total_tipo[5] = {0};
    float total_anio[10] = {0};

    printf("Hola! Vamos a registrar la produccion de vino\n\n");
    
    printf("Cuantos años quieres registrar? (maximo 10): ");
    scanf("%d", &anios);
    
    if(anios <= 0 || anios > 10) {
        printf("Oops! El numero debe estar entre 1 y 10. Adios!\n");
        return 0;
    }
    
    printf("\nVamos a ingresar los datos...\n");
    
    // Pedir los datos para cada año
    for(i = 1; i <= anios; i++) {
        printf("\n--- Año %d ---\n", i);
        
        for(j = 1; j <= 4; j++) {
            printf("Litros de vino tipo %d: ", j);
            scanf("%f", &produccion[i][j]);
            
            // Sumar al total del tipo de vino
            total_tipo[j] += produccion[i][j];
            
            // Sumar al total del año
            total_anio[i] += produccion[i][j];
        }
    }
    
    // Mostrar los resultados
    printf("\n\n--- RESULTADOS ---\n");
    
    printf("\nTotal por tipo de vino:\n");
    for(j = 1; j <= 4; j++) {
        printf("Tipo %d: %.2f litros\n", j, total_tipo[j]);
    }
    
    printf("\nTotal por año:\n");
    for(i = 1; i <= anios; i++) {
        printf("Año %d: %.2f litros\n", i, total_anio[i]);
       printf("\nTotal por año:\n");
    for(i = 1; i <= anios; i++) {
        printf("Año %d: %.2f litros\n", i, total_anio[i]);
    }

    // Mostrar el año con mayor producción
    float max_produccion = 0;
    int mejor_anio = 0;
    
    for(i = 1; i <= anios; i++) {
        if(total_anio[i] > max_produccion) {
            max_produccion = total_anio[i];
            mejor_anio = i;
        }
    }
    
    if(mejor_anio != 0) {
        printf("\nEl año con más producción fue el año %d con %.2f litros\n", 
               mejor_anio, max_produccion);
    }

    // Calcular el promedio por año
    float promedio = 0;
    for(i = 1; i <= anios; i++) {
        promedio += total_anio[i];
    }
    promedio /= anios;
    
    printf("\nProducción promedio por año: %.2f litros\n", promedio);

    printf("\n¡Fin del programa! Gracias por usar mi sistema :)\n");
    return 0;
}