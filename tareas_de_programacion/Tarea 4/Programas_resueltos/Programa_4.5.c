#include <stdio.h>
int cubo(int);
int main(void)
{
int i;
for (i = 1; i <= 10; i++)
printf("El cubo de %d es: %d\n", i, cubo(i));
return 0;
}
int cubo(int num)
{
return num * num * num;
}
        