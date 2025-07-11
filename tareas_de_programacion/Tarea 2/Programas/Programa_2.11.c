#include <stdio.h>
int main(void)
{
	int dis, tie;
	float bil;
	printf("Ingrese distancia entre ciudades y tiempo de estancia: ");
	if (scanf("%d %d", &dis, &tie) != 2)
	{
		printf("Entrada invlida\n");
		return 1;
	}

	if (dis * 2 > 500 && tie > 10)
		bil = dis * 2 * 0.19 * 0.8;
	else
		bil = dis * 2 * 0.19;

	printf("Costo del billete: %.2f\n", bil);
	return 0;
}
