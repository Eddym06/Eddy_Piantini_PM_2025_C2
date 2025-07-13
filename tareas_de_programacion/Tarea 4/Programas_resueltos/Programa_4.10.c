#include <stdio.h>
int multiplo(int, int);
int main(void)
{
int NU1, NU2, RES;
printf("\nIngresa los dos numeros: ");
if (scanf("%d %d", &NU1, &NU2) != 2)
{
printf("Entrada invalida\n");
return 1;
}
RES = multiplo(NU1, NU2);
if (RES)
printf("\nEl segundo numero es multiplo del primero");
else
printf("\nEl segundo numero no es multiplo del primero");
return 0;
}
int multiplo(int N1, int N2)
{
if (N1 == 0)
return 0;
if ((N2 % N1) == 0)
return 1;
else
return 0;
}
            