#include <stdio.h>

int main(void) {
char p1, p2, p3 = '$';
printf("\nIngrese un caracter: ");
p1 = getchar();
getchar();
putchar(p1);
printf("\n");
printf("\nEl caracter p3 es: ");
putchar(p3);
printf("\n");
printf("\nIngrese otro caracter: ");
fflush(stdin);
scanf("%c", &p2);
printf("%c", p2);
return 0;
}
    