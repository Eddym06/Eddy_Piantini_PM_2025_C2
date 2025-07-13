#include <stdio.h>
void funcion1(void);
int global_k = 1;
int main(void)
{
int i;
for (i = 1; i <= 3; i++)
funcion1();
return 0;
}
void funcion1(void)
{
int local_k = 2;
local_k += local_k;
printf("Valor de la variable local: %d\n", local_k);
global_k += local_k;
printf("Valor de la variable global: %d\n", global_k);
}
        