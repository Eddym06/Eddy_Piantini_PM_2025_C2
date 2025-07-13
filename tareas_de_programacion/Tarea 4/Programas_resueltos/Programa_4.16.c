#include <stdio.h>
#include <math.h>

float ACT = 0.0;
float MAX = -50.0;
float MIN = 60.0;
int HMAX;
int HMIN;

void acumular_temperatura(float);
void maxima_temperatura(float, int);
void minima_temperatura(float, int);

int main(void)
{
float temperatura;
int i;
for (i = 1; i <= 24; i++)
{
printf("Ingresa la temperatura de la hora %d: ", i);
scanf("%f", &temperatura);
acumular_temperatura(temperatura);
maxima_temperatura(temperatura, i);
minima_temperatura(temperatura, i);
}
printf("\nPromedio del dia: %.2f", ACT / 24);
printf("\nMaxima del dia: %.2f \tHora: %d", MAX, HMAX);
printf("\nMinima del dia: %.2f \tHora: %d", MIN, HMIN);
return 0;
}

void acumular_temperatura(float temp)
{
ACT += temp;
}

void maxima_temperatura(float temp, int hora)
{
if (temp > MAX)
{
MAX = temp;
HMAX = hora;
}
}

void minima_temperatura(float temp, int hora)
{
if (temp < MIN)
{
MIN = temp;
HMIN = hora;
}
}
        