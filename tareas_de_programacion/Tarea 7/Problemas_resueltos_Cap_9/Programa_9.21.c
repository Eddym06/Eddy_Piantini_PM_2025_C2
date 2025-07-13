#include <stdio.h>
typedef struct
{
int clave;
char nombre[18];
int carrera;
float promedio;
float examen;
char telefono[25];
} alumno;
float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);
void main(void)
{
float pro;
FILE *ap, *c1, *c2, *c3, *c4, *c5;
ap = fopen("alu1.dat", "r");
c1 = fopen("car1.dat", "w+");
c2 = fopen("car2.dat", "w+");
c3 = fopen("car3.dat", "w+");
c4 = fopen("car4.dat", "w+");
c5 = fopen("car5.dat", "w+");
if (ap != NULL && c1 != NULL && c2 != NULL && c3 != NULL && c4 != NULL && c5 != NULL)
{
pro = F1(ap);
printf("PROMEDIO EXAMEN DE ADMISION: %.2f\n", pro);
F2(ap, c1, c2, c3, c4, c5);
F3(c1, c2, c3, c4, c5);
fclose(ap);
fclose(c1);
fclose(c2);
fclose(c3);
fclose(c4);
fclose(c5);
}
else
printf("El o los archivos no se pudieron abrir\n");
}
float F1(FILE *ap)
{
alumno alu;
float sum = 0;
int i = 0;
rewind(ap);
while (fread(&alu, sizeof(alumno), 1, ap))
{
i++;
sum += alu.examen;
}
return i > 0 ? sum / i : 0;
}
void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
alumno alu;
rewind(ap);
while (fread(&alu, sizeof(alumno), 1, ap))
{
if ((alu.examen >= 1300 && alu.promedio >= 8.0) || (alu.examen > 1399 && alu.promedio >= 7.0))
{
switch (alu.carrera)
{
case 1: fwrite(&alu, sizeof(alumno), 1, c1); break;
case 2: fwrite(&alu, sizeof(alumno), 1, c2); break;
case 3: fwrite(&alu, sizeof(alumno), 1, c3); break;
case 4: fwrite(&alu, sizeof(alumno), 1, c4); break;
case 5: fwrite(&alu, sizeof(alumno), 1, c5); break;
}
}
}
}
void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
alumno alu;
float cal[5] = {0};
float sum;
int i;
rewind(c1);
sum = 0; i = 0;
while (fread(&alu, sizeof(alumno), 1, c1))
{
i++;
sum += alu.examen;
}
cal[0] = i > 0 ? sum / i : 0;
rewind(c2);
sum = 0; i = 0;
while (fread(&alu, sizeof(alumno), 1, c2))
{
i++;
sum += alu.examen;
}
cal[1] = i > 0 ? sum / i : 0;
rewind(c3);
sum = 0; i = 0;
while (fread(&alu, sizeof(alumno), 1, c3))
{
i++;
sum += alu.examen;
}
cal[2] = i > 0 ? sum / i : 0;
rewind(c4);
sum = 0; i = 0;
while (fread(&alu, sizeof(alumno), 1, c4))
{
i++;
sum += alu.examen;
}
cal[3] = i > 0 ? sum / i : 0;
rewind(c5);
sum = 0; i = 0;
while (fread(&alu, sizeof(alumno), 1, c5))
{
i++;
sum += alu.examen;
}
cal[4] = i > 0 ? sum / i : 0;
for (i = 0; i < 5; i++)
printf("Promedio carrera %d: %.2f\n", i+1, cal[i]);
}
                                                            