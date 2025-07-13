#include <stdio.h>
#include <string.h>

int main(void) {
char cad1[50], cad2[50], cad0[50];
char *ptr;
int i = 0;
printf("\nIngrese la primera cadena de caracteres: ");
fgets(cad1, sizeof(cad1), stdin);
cad1[strcspn(cad1, "\n")] = 0;
printf("\nIngrese la cadena a buscar: ");
fgets(cad2, sizeof(cad2), stdin);
cad2[strcspn(cad2, "\n")] = 0;
strcpy(cad0, cad1);
ptr = strstr(cad0, cad2);
while (ptr != NULL) {
i++;
ptr = strstr(ptr + 1, cad2);
}
printf("\nEl numero de veces que aparece la segunda cadena es: %d", i);
return 0;
}
        