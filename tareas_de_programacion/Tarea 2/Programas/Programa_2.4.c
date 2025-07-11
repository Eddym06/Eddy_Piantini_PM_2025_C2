#include <stdio.h>
int main(void)
{
	float pre, npr;
	printf("Ingrese el precio: ");
	if (scanf("%f", &pre) != 1)
	{
		printf("Entrada invalida\n");
		return 1;
	}

	if (pre > 1500)
		npr = pre * 1.11;
	else
		npr = pre * 1.08;
	printf("Nuevo precio: %.2f\n", npr);
	return 0;
}
