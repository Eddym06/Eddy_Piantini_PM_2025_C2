#include <stdio.h>
int main(void) {
int i;
float sal, nom = 0;
for (i = 1; i <= 15; i++) {
printf("Ingrese el salario del profesor %d: ", i);
if (scanf("%f", &sal) != 1 || sal < 0) {
printf("Entrada invalida, ingrese un salario no negativo\n");
while (getchar() != '\n');
i--;
continue;
}
nom += sal;
}
printf("\nEl total de la nomina es: %.2f\n", nom);
return 0;
}
            