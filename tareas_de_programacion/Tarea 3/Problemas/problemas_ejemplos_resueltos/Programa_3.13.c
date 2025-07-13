#include <stdio.h>
int main(void) {
int i, pri = 0, seg = 1, sig;
printf("\t%d\t%d", pri, seg);
for (i = 3; i <= 50; i++) {
sig = pri + seg;
pri = seg;
seg = sig;
printf("\t%d", sig);
}
printf("\n");
return 0;
}
        