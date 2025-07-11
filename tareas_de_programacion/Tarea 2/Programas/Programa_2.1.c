#include <stdio.h>
int main(void)
{
	float pro;
	printf("Ingrese el promedio del alumno: ");
	if (scanf("%f", &pro) != 1)
	{
		printf("Entrada invalida\n");
		return 1;
	}

	if (pro >= 6.0)
		printf("Aprobado\n");
	return 0;
}
