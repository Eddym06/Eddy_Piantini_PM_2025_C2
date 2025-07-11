#include <stdio.h>
int main(void)
{
	float p, s, r;
	printf("Ingrese las ventas de los tres vendedores: ");
	if (scanf("%f %f %f", &p, &s, &r) != 3)
	{
		printf("Entrada invalida\n");
		return 1;
	}

	if (p > s)
	{
		if (p > r)
		{
			if (s > r)
				printf("Orden: %.2f %.2f %.2f\n", p, s, r);
			else
				printf("Orden: %.2f %.2f %.2f\n", p, r, s);
		}
		else
		{
			printf("Orden: %.2f %.2f %.2f\n", r, p, s);
		}
	}
	else
	{
		if (s > r)
		{
			if (p > r)
				printf("Orden: %.2f %.2f %.2f\n", s, p, r);
			else
				printf("Orden: %.2f %.2f %.2f\n", s, r, p);
		}
		else
		{
			printf("Orden: %.2f %.2f %.2f\n", r, s, p);
		}
	}

	return 0;
}
