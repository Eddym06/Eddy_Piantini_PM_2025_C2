#include <stdio.h>
#include <ctype.h>

void interpreta(char *cad) {
int i = 0, j, k;
while (cad[i] != '\0') {
if (isalpha(cad[i])) {
k = cad[i - 1] - '0';
for (j = 0; j < k; j++) {
putchar(cad[i]);
}
}
i++;
}
}

int main(void) {
char cad[50];
printf("\nIngrese la cadena de caracteres: ");
fgets(cad, sizeof(cad), stdin);
cad[strcspn(cad, "\n")] = 0;
interpreta(cad);
return 0;
}
    