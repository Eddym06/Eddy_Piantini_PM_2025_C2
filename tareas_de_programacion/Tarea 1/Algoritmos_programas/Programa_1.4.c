#include <stdio.h>
int main(void)
{
float BAS, ALT, SUP;
printf("Ingrese la base y la altura del triangulo: ");
scanf("%f %f", &BAS, &ALT);
SUP = BAS * ALT / 2;
printf("La superficie del triangulo es: %.2f\n", SUP);
return 0;
}
    