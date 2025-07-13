#include <stdio.h>
int mcd(int, int);
int main(void)
{
int NU1, NU2, RES;
printf("\nIngresa los dos numeros enteros: ");
if (scanf("%d %d", &NU1, &NU2) != 2 || NU1 == 0 || NU2 == 0)
{
printf("Los numeros no pueden ser cero\n");
return 1;
}
RES = mcd(NU1, NU2);
printf("\nEl maximo comun divisor de %d y %d es: %d", NU1, NU2, RES);
return 0;
}
int mcd(int N1, int N2)
{
int I;
if (N1 < N2)
I = N1 / 2;
else
I = N2 / 2;
while (I >= 1)
{
if ((N1 % I == 0) && (N2 % I == 0))
return I;
I--;
}
return 1;
}
                