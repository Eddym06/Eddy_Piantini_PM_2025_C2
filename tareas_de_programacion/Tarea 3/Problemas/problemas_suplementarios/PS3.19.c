#include <stdio.h>

void generarFiguraCompleja();

void main(void) {
printf("Generando figura numerica compleja:\n");
generarFiguraCompleja();
}

void generarFiguraCompleja() {
for (int fila = 1; fila <= 10; fila++) {
int inicio = fila - 1;
for (int i = 0; i < fila; i++) {
printf("%d ", (inicio + i) % 10);
}
for (int i = fila - 2; i >= 0; i--) {
if (fila > 1) {
printf("%d ", (inicio + i) % 10);
}
}
printf("\n");
}
}
                    