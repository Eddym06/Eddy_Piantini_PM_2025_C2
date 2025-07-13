#include <stdio.h>
int main(void) {
int i, n;
float lan, pro = 0;
do {
printf("Ingrese el numero de lanzamientos: ");
if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
printf("Entrada invalida, debe estar entre 1 y 10\n");
while (getchar() != '\n');
continue;
}
break;
} while (1);
for (i = 1; i <= n; i++) {
printf("Ingrese el lanzamiento %d: ", i);
if (scanf("%f", &lan) != 1 || lan < 0) {
printf("Entrada invalida, ingrese un valor no negativo\n");
while (getchar() != '\n');
i--;
continue;
}
pro += lan;
}
pro = pro / n;
printf("\nEl promedio de lanzamientos es: %.2f\n", pro);
return 0;
}
                    