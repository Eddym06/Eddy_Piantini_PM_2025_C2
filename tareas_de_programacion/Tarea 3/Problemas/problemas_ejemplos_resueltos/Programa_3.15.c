#include <stdio.h>
#include <math.h>
int main(void) {
int i = 1, b = 0, c = 1;
double res = 4.0 / i;
while (fabs(3.1415 - res) > 0.0005) {
i += 2;
if (b) {
res += 4.0 / i;
b = 0;
} else {
res -= 4.0 / i;
b = 1;
}
c++;
}
printf("\nNumero de terminos: %d\n", c);
return 0;
}
                