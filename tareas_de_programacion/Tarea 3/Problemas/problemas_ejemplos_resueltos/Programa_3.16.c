#include <stdio.h>
int main(void) {
int i, mat, mamat = 0, memat = 0;
float sum, pro, cal, mapro = 0.0, mepro = 11.0;
printf("Ingrese la matricula del primer alumno: ");
if (scanf("%d", &mat) != 1) {
printf("Entrada invalida\n");
return 1;
}
while (mat) {
sum = 0;
for (i = 1; i <= 5; i++) {
printf("Ingrese la calificacion %d del alumno %d: ", i, mat);
if (scanf("%f", &cal) != 1 || cal < 0 || cal > 10) {
printf("Entrada invalida, ingrese un valor entre 0 y 10\n");
while (getchar() != '\n');
i--;
continue;
}
sum += cal;
}
pro = sum / 5;
printf("\nMatricula: %d Promedio: %.2f\n", mat, pro);
if (pro > mapro) {
mapro = pro;
mamat = mat;
}
if (pro < mepro) {
mepro = pro;
memat = mat;
}
printf("\nIngrese la matricula del siguiente alumno (0 para terminar): ");
if (scanf("%d", &mat) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
continue;
}
}
if (mamat != 0)
printf("\nMatricula del alumno con mejor promedio: %d\tPromedio: %.2f\n", mamat, mapro);
if (memat != 0)
printf("Matricula del alumno con peor promedio: %d\tPromedio: %.2f\n", memat, mepro);
return 0;
}
                                