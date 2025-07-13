#include <stdio.h>
int main(void) {
int v1[9] = {2, 3, 4, 7, 0, 0, 0, 0, 0}, v2[9] = {6, 0, 0, 0, 0, 0, 0, 0, 0}, *ax, *ay;
ax = &v1[0];
ay = &v2[0];
v1[0] = *ay;
*ay = *ax - v1[0];
printf("\nV1[0] = %d \t V1[1] = %d \t V1[2] = %d \t V1[3] = %d \t V2[0] = %d \t V2[1] = %d \t V2[2] = %d \t V2[3] = %d\n", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]);
v2[1] = ++*ax;
v2[2] = (*ay)++;
*ax += 2;
printf("\nV1[0] = %d \t V1[1] = %d \t V1[2] = %d \t V1[3] = %d \t V2[0] = %d \t V2[1] = %d \t V2[2] = %d \t V2[3] = %d\n", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]);
return 0;
}
    