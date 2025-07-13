#include <stdio.h>
int main(void) {
int x = 5, y = 8, v[5] = {1, 3, 5, 7, 9}, *ay, *ax;
ay = &y;
x = *ay;
*ay = v[0] + v[1];
printf("\nX = %d \t Y = %d \t V[0] = %d \t V[1] = %d \t V[2] = %d \t V[3] = %d \t V[4] = %d\n", x, y, v[0], v[1], v[2], v[3], v[4]);
ax = &v[0];
x = *ax;
y = *ax * v[0];
*ax = *ay - 3;
printf("\nX = %d \t Y = %d \t V[0] = %d \t V[1] = %d \t V[2] = %d \t V[3] = %d \t V[4] = %d\n", x, y, v[0], v[1], v[2], v[3], v[4]);
return 0;
}
    