#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cuentap(char *cad) {
int i = 0;
char *cad0;
strcat(cad, " ");
cad0 = strstr(cad, " ");
while (cad0 != NULL) {
i++;
cad0 = strstr(cad0 + 1, " ");
}
return i;
}

int main(void) {
int i;
char fra[50];
printf("\nIngrese la linea de texto: ");
fgets(fra, sizeof(fra), stdin);
fra[strcspn(fra, "\n")] = 0;
i = cuentap(fra);
printf("\nLa linea de texto tiene %d palabras", i);
return 0;
}
    