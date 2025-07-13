#include <stdio.h>
int main(void) {
int i = 2, cam = 1;
long sse = 0;
while (i <= 2500) {
sse += i;
printf("\t%d", i);
if (cam) {
i += 5;
cam = 0;
} else {
i += 3;
cam = 1;
}
}
printf("\nLa suma de la serie es: %ld\n", sse);
return 0;
}
                