#include <stdio.h>
int main(void) {
int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;
float cal;
printf("Ingresa la calificacion del alumno: ");
if (scanf("%f", &cal ) != 1 || cal < -1 || (cal > 10 && cal != -1)) {
printf("Entrada invalida\n");
return 1;
}
while (cal != -1) {
if (cal < 4)
r1++;
else if (cal < 6)
r2++;
else if (cal < 8)
r3++;
else if (cal < 9)
r4++;
else
r5++;
printf("Ingresa la calificacion del alumno: ");
if (scanf("%f", &cal) != 1 || cal < -1 || (cal > 10 && cal != -1)) {
printf("Entrada invalida, ingrese un valor entre 0 y 10 o -1 para terminar\n");
while (getchar() != '\n');
continue;
}
}
printf("\n< 4: %d\n", r1);
printf("4  5.99: %d\n", r2);
printf("6  7.99: %d\n", r3);
printf("8  8.99: %d\n", r4);
printf("9  10: %d\n", r5);
return 0;
}
                