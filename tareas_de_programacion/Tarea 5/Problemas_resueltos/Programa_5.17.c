#include <stdio.h>
int main(void) {
int v1[9] = {1, 3, 5, 7, 0, 0, 0, 0, 0}, v2[9] = {2, 4, 0, 0, 0, 0, 0, 0, 0}, *ax, *ay;
ax = &v1[0];
ay = &v2[0];
v2[2] = *(ax + 1);
v2[0] = *ax;
ax = ax + 1;
v1[0] = *ax;
printf("\nV1[0] = %d \t V1[1] = %d \t V1[2] = %d \t V1[3] = %d \t V2[0] = %d \t V2[1] = %d \t V2[2] = %d \t V2[3] = %d\n", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]);
v1[2] = *ay;
v1[1] = --*ay;
ax = ax + 1;
v1[0] = *ax;
printf("\nV1[0] = %d \t V1[1] = %d \t V1[2] = %d \t V1[3] = %d \t V2[0] = %d \t V2[1] = %d \t V2[2] = %d \t V2[3] = %d\n", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]);
return 0;
}
    