#include <stdio.h>
int a, b, c, d;
void funcion1(int, int *, int *);
int funcion2(int *, int);
int main(void)
{
int a;
a = 1;
b = 2;
c = 3;
d = 4;
printf("\n%d %d %d %d", a, b, c, d);
c = funcion2(&c, d);
printf("\n%d %d %d %d", a, b, c, d);
return 0;
}
void funcion1(int r, int *b, int *c)
{
int d;
a = *c;
d = a + 3 + *b;
if (r)
{
*b = *b + 2;
*c = *c + 3;
printf("\n%d %d %d %d", a, *b, *c, d);
}
else
{
*b = *b + 5;
*c = *c + 4;
printf("\n%d %d %d %d", a, *b, *c, d);
}
}
int funcion2(int *d, int c)
{
int b;
a++;
b = 7;
c += 3;
(*d) += 2;
printf("\n%d %d %d %d", a, b, c, *d);
return (c);
}
                    