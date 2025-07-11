#include <stdio.h>
#include <math.h>

int main(void)
{
	float res;
	int r, t, q;
	printf("Ingrese los valores de R, T y Q: ");
	if (scanf("%d %d %d", &r, &t, &q) != 3)
	{
		printf("Entrada invalida\n");
		return 1;
	}

	res = pow(r, 4) - pow(t, 3) * 4 * pow(q, 2);
	if (res > 820)
		printf("R = %d T = %d Q = %d\n", r, t, q);
	return 0;
}