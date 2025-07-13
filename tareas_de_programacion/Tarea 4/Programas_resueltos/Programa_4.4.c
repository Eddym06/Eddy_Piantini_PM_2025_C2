#include <stdio.h>
int funcion1(void);
int funcion2(void);
int funcion3(void);
int funcion4(void);
int global_k = 3;
int main(void)
{
int i;
for (i = 1; i <= 3; i++)
{
printf("Funcion 1: %d\n", funcion1());
printf("Funcion 2: %d\n", funcion2());
printf("Funcion 3: %d\n", funcion3());
printf("Funcion 4: %d\n", funcion4());
}
return 0;
}
int funcion1(void)
{
global_k *= global_k;
return global_k;
}
int funcion2(void)
{
int local_k = 2;
local_k++;
return local_k;
}
int funcion3(void)
{
static int local_k = 6;
local_k += 3;
return local_k;
}
int funcion4(void)
{
int local_k = 4;
local_k += global_k;
return local_k;
}
                        