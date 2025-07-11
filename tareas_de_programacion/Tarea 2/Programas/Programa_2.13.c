#include <stdio.h>
#include <math.h>

int main(void)
{
	float x;
	int y;

	printf("Ingrese el valor de Y: ");
	if (scanf("%d", &y) != 1)
	{
		printf("Entrada invalida\n");
		return 1;
	}

	if (y == 0)
	{
		printf("Y no puede ser cero\n");
		return 1;
	}
	else if (y > 0 && y > 50)
	{
		x = 0;
	}
	else if (y >= 25)
	{
		x = pow(y, 3) - 12;
	}
	else if (y >= 10)
	{
		x = 4.0 / y - y;
	}
	else
	{
		x = pow(y, 2) * pow(y, 3) - 18;
	}

	printf("Y = %d X = %.2f\n", y, x);
	return 0;
}
