#include <stdio.h>
int main(void)
{
	int zon, min;
	float cos;
	printf("Ingrese zona geogrfica y duracin de la llamada en minutos: ");
	if (scanf("%d %d", &zon, &min) != 2)
	{
		printf("Entrada invlida\n");
		return 1;
	}

	switch (zon)
	{
		case 1:
			cos = min * 15.0;
			break;
		case 2:
			cos = min * 10.0;
			break;
		case 3:
			cos = min * 12.0;
			break;
		case 4:
			cos = min * 20.0;
			break;
		default:
			cos = -1;
			break;
	}

	if (cos != -1)
		printf("Costo de la llamada: %.2f\n", cos);
	else
		printf("Zona invlida\n");
	return 0;
}
