#include <stdio.h>
int a, b, c, d;
void funcion1(int, int *, int *);
int funcion2(int, int *);
int main(void)
{
int local_a = 1;
b = 2;
c = 3;
d = 4;
printf("%d %d %d %d\n", local_a, b, c, d);
funcion1(local_a, &b, &c);
printf("%d %d %d %d\n", local_a, b, c, d);
local_a = funcion2(c, &d);
printf("%d %d %d %d\n", local_a, b, c, d);
return 0;
}
void funcion1(int valor, int *b_ptr, int *c_ptr)
{
int local_d = 3;
a = *c_ptr;
local_d = a + 3 + *b_ptr;
printf("%d %d %d %d\n", a, *b_ptr, *c_ptr, local_d);
*b_ptr += 2;
*c_ptr += 2;
}
int funcion2(int valor_c, int *d_ptr)
{
int local_b = 7;
a++;
printf("%d %d %d %d\n", a, local_b, valor_c, *d_ptr);
valor_c += 3;
*d_ptr += 2;
printf("%d %d %d %d\n", a, local_b, valor_c, *d_ptr);
return valor_c;
}
            