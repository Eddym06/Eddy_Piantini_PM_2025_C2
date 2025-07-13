#include <stdio.h>

int main(void) {
char *cad0 = "Argentina";
puts(cad0);
cad0 = "Brasil";
puts(cad0);

char cad1[50] = "";
printf("\nIngrese una linea de texto: ");
gets(cad1);
puts(cad1);

char cad2[20] = "Mexico";
puts(cad2);
printf("\nIngrese una linea de texto: ");
gets(cad2);
puts(cad2);

return 0;
}
