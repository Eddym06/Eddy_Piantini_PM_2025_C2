#include <stdio.h>
int main(void)
{
	int mat, car, sem;
	float pro;
	printf("Ingrese matrcula: ");
	if (scanf("%d", &mat) != 1)
	{
		printf("Entrada invlida\n");
		return 1;
	}

	printf("Ingrese carrera (1-Industrial 2-Telemtica 3-Computacin 4-Mecnica): ");
	if (scanf("%d", &car) != 1)
	{
		printf("Entrada invlida\n");
		return 1;
	}

	printf("Ingrese semestre: ");
	if (scanf("%d", &sem) != 1)
	{
		printf("Entrada invlida\n");
		return 1;
	}

	printf("Ingrese promedio: ");
	if (scanf("%f", &pro) != 1)
	{
		printf("Entrada invlida\n");
		return 1;
	}

	switch (car)
	{
		case 1:
			if (sem >= 6 && pro >= 8.5)
				printf("%d %d %.2f\n", mat, car, pro);
			break;
		case 2:
			if (sem >= 5 && pro >= 9.0)
				printf("%d %d %.2f\n", mat, car, pro);
			break;
		case 3:
			if (sem >= 6 && pro >= 8.8)
				printf("%d %d %.2f\n", mat, car, pro);
			break;
		case 4:
			if (sem >= 7 && pro >= 9.0)
				printf("%d %d %.2f\n", mat, car, pro);
			break;
		default:
			printf("Carrera invlida\n");
			break;
	}

	return 0;
}
