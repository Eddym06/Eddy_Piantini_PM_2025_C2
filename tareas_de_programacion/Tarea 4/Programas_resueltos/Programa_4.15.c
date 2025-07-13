#include <stdio.h>
int Productoria(int);
int main(void)
{
int NUM;
do
{
printf("Ingresa el numero del cual quieres calcular la productoria: ");
if (scanf("%d", &NUM) != 1 || NUM < 1 || NUM > 100)
{
printf("El numero debe estar entre 1 y 100\n");
continue;
}
break;
} while (1);
printf("\nLa productoria de %d es: %d", NUM, Productoria(NUM));
return 0;
}
int Productoria(int N)
{
int I, PRO = 1;
for (I = 1; I <= N; I++)
PRO *= I;
return PRO;
}
                