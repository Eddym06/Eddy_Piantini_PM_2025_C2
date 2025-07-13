#include <stdio.h>
int suma(int, int);
int resta(int, int);
int control(int (*)(int, int), int, int);
int main(void)
{
int resultado;
resultado = control(suma, 15, 5);
printf("Resultado suma: %d\n", resultado);
resultado = control(resta, 15, 5);
printf("Resultado resta: %d\n", resultado);
return 0;
}
int suma(int x, int y)
{
return x + y;
}
int resta(int x, int y)
{
return x - y;
}
int control(int (*operacion)(int, int), int x, int y)
{
return operacion(x, y);
}
                