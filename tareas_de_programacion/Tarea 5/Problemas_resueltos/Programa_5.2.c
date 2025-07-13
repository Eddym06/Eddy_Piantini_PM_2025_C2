#include <stdio.h>
int main(void) {
int ele[5] = {0}, i, vot;
printf("Ingresa el primer voto (0 para terminar): ");
if (scanf("%d", &vot) != 1) {
printf("Entrada invalida\n");
return 1;
}
while (vot) {
if (vot >= 1 && vot <= 5)
ele[vot - 1]++;
else
printf("\nEl voto registrado es incorrecto\n");
printf("Ingresa el siguiente voto (0 para terminar): ");
if (scanf("%d", &vot) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
continue;
}
}
printf("\nResumen de Votaciones\n");
for (i = 0; i < 5; i++)
printf("\nCandidato %d: %d", i + 1, ele[i]);
printf("\n");
return 0;
}
                