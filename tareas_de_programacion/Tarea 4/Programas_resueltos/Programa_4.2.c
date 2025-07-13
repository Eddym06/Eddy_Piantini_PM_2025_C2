#include <stdio.h>
int cubo(int);
int main(void)
{
int i, resultado;
for (i = 1; i <= 10; i++)
{
resultado = cubo(i);
printf("El cubo de %d es: %d\n", i, resultado);
}
return 0;
}
int cubo(int num)
{
return num * num * num;
}
            