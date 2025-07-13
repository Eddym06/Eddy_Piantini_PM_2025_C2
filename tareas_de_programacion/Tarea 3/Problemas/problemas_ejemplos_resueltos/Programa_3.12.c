#include <stdio.h>
int main(void) {
int num;
printf("Ingrese el numero: ");
if (scanf("%d", &num) != 1 || num <= 0) {
printf("Error en el dato ingresado\n");
return 1;
}
printf("%d", num);
while (num != 1) {
if (num % 2)
num = num * 3 + 1;
else
num = num / 2;
printf("\n%d", num);
}
printf("\n");
return 0;
}
            