#include <stdio.h>

void main()
{
    // Precios de las localidades. Índice 0 no usado para que coincida con tipo de localidad (1-6).
    float precios[7] = {0.0, 50.00, 75.00, 100.00, 100.00, 120.00, 150.00};

    // Arrays para guardar cantidad y monto recaudado por cada localidad.
    int cantidad_vendida[7] = {0};
    float monto_recaudado[7] = {0.0};

    int CLA; // Tipo de localidad.
    int CAN; // Cantidad de boletos.

    int total_boletos_vendidos = 0;
    float monto_total_general = 0.0;

    printf("¡Bienvenido al sistema de venta de boletos del circo!\n");
    printf("--------------------------------------------------\n");
    printf("Precios de las localidades:\n");
    for (int i = 1; i <= 6; i++) {
        printf("L%d: %.2f\n", i, precios[i]);
    }
    printf("--------------------------------------------------\n");
    printf("Ingresa el tipo de localidad (1-6) y la cantidad de boletos (0 0 para terminar).\n");

    while (1)
    {
        printf("\nIngresa tipo de localidad y cantidad (ej: 1 5): ");
        scanf("%d %d", &CLA, &CAN);

        if (CLA == 0 && CAN == 0)
        {
            printf("Venta de boletos finalizada.\n");
            break;
        }

        if (CLA >= 1 && CLA <= 6)
        {
            cantidad_vendida[CLA] += CAN;
            monto_recaudado[CLA] += (CAN * precios[CLA]);
            total_boletos_vendidos += CAN;
            monto_total_general += (CAN * precios[CLA]);
        }
        else
        {
            printf("Error: Tipo de localidad inválido. Por favor, ingresa un número entre 1 y 6.\n");
        }
    }

    printf("\n--- RESUMEN DETALLADO DE LA VENTA ---\n");
    for (int i = 1; i <= 6; i++) {
        printf("Localidad L%d: %d boletos vendidos (Monto: %.2f)\n", i, cantidad_vendida[i], monto_recaudado[i]);
    }
    printf("--------------------------------------------------\n");
    printf("TOTAL DE BOLETOS VENDIDOS: %d\n", total_boletos_vendidos);
    printf("MONTO TOTAL RECAUDADO: %.2f\n", monto_total_general);
    printf("--------------------------------------------------\n");
}