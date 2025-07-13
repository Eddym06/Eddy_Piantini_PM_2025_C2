#include <stdio.h>
#define MAX 100
int main(void) {
int arre[MAX], i, num, cue = 0;
for (i = 0; i < MAX; i++) {
printf("Ingrese el elemento %d del arreglo: ", i + 1);
if (scanf("%d", &arre[i]) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
i--;
continue;
}
}
printf("\nIngrese el numero que se va a buscar en el arreglo: ");
if (scanf("%d", &num) != 1) {
printf("Entrada invalida\n");
return 1;
}
for (i = 0; i < MAX; i++)
if (arre[i] == num)
cue++;
printf("\nEl %d se encuentra %d veces en el arreglo\n", num, cue);
return 0;
}
                