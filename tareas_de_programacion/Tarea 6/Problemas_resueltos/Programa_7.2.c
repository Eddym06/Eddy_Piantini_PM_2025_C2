#include <stdio.h>
#include <ctype.h>

int main(void) {
char p1;
printf("\nIngrese un caracter para analizar si es un digito: ");
p1 = getchar();
getchar();
if (isdigit(p1)) {
printf("%c es un digito\n", p1);
} else {
printf("%c no es un digito\n", p1);
}

printf("\nIngrese un caracter para examinar si es una letra: ");
p1 = getchar();
getchar();
if (isalpha(p1)) {
printf("%c es una letra\n", p1);
if (islower(p1)) {
printf("%c es una letra minuscula\n", p1);
} else {
printf("%c no es una letra minuscula\n", p1);
}
if (isupper(p1)) {
printf("%c fue convertida de mayuscula a minuscula\n", tolower(p1));
}
} else {
printf("%c no es una letra\n", p1);
}

printf("\nIngrese una letra para convertirla de mayuscula a minuscula: ");
p1 = getchar();
getchar();
if (isalpha(p1)) {
if (isupper(p1)) {
printf("%c fue convertida de mayuscula a minuscula\n", tolower(p1));
} else {
printf("%c es una letra minuscula\n", p1);
}
} else {
printf("%c no es una letra\n", p1);
}
return 0;
}
                