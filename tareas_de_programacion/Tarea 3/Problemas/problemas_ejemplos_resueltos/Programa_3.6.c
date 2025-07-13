#include <stdio.h>
int main(void) {
int i = 0;
float sal, nom = 0, pro;
printf("Ingrese el salario del profesor: ");
if (scanf("%f", &sal) != 1 || sal < 0) {
printf("Entrada invalida\n");
return 1;
}
do {
nom += sal;
i++;
printf("Ingrese el salario del profesor (0 para terminar): ");
if (scanf("%f", &sal) != 1 || sal < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
continue;
}
} while (sal);
pro = nom / i;
printf("\nNomina: %.2f\tPromedio de salarios: %.2f\n", nom, pro);
return 0;
}
                