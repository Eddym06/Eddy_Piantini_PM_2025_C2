#include <stdio.h>

int cuenta(char *cadena) {
if (cadena[0] == '\0') {
return 0;
}
return 1 + cuenta(&cadena[1]);
}

int main(void) {
char cad[50];
int i;
printf("\nIngrese la cadena de caracteres: ");
fgets(cad, sizeof(cad), stdin);
cad[strcspn(cad, "\n")] = 0;
i = cuenta(cad);
printf("\nLongitud de la cadena: %d", i);
return 0;
}
    