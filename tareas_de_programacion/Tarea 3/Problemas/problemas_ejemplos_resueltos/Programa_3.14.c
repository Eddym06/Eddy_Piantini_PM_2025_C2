#include <stdio.h>
int main(void) {
int vot, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, nu = 0, svo;
float po1, po2, po3, po4, po5, pon;
printf("Ingrese el primer voto: ");
if (scanf("%d", &vot) != 1) {
printf("Entrada invalida\n");
return 1;
}
while (vot) {
switch (vot) {
case 1: c1++; break;
case 2: c2++; break;
case 3: c3++; break;
case 4: c4++; break;
case 5: c5++; break;
default: nu++; break;
}
printf("Ingrese el siguiente voto: ");
if (scanf("%d", &vot) != 1) {
printf("Entrada invalida\n");
while (getchar() != '\n');
continue;
}
}
svo = c1 + c2 + c3 + c4 + c5 + nu;
if (svo > 0) {
po1 = (float)c1 / svo * 100;
po2 = (float)c2 / svo * 100;
po3 = (float)c3 / svo * 100;
po4 = (float)c4 / svo * 100;
po5 = (float)c5 / svo * 100;
pon = (float)nu / svo * 100;
printf("\nTotal de votos: %d\n", svo);
printf("Candidato 1: %d votos  Porcentaje: %.2f\n", c1, po1);
printf("Candidato 2: %d votos  Porcentaje: %.2f\n", c2, po2);
printf("Candidato 3: %d votos  Porcentaje: %.2f\n", c3, po3);
printf("Candidato 4: %d votos  Porcentaje: %.2f\n", c4, po4);
printf("Candidato 5: %d votos  Porcentaje: %.2f\n", c5, po5);
printf("Nulos: %d votos  Porcentaje: %.2f\n", nu, pon);
} else {
printf("\nNo se ingresaron votos\n");
}
return 0;
}
                            