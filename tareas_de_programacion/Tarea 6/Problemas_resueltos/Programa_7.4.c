#include <stdio.h>
/* Declaración de cadenas de caracteres y asignación de valores. */
void main(void)
{
char *cad0;
cad0 = "Argentina"; puts(cad0);
/* La declaración y la asignación son correctas. */
cad0 = "Brasil";
/* Correcto. Se modifica el contenido de la posición en memoria a la que apunta ➥la variable cad0 —apuntador de tipo cadena de caracteres. */
puts(cad0);
char *cad1;
gets(*cad1); gets(cad1);
/* Incorrecto. Ambas lecturas generan un error en la ejecución del programa. ➥Para que un apuntador de tipo cadena de caracteres se pueda utilizar con la ➥función de lectura gets, es necesario inicializarlo como se hace en la siguiente ➥instrucción. */
char *cad1 = "";
gets(cad1);
/* Correcto. Primero se le asigna un valor a la posición de memoria a la que ➥apunta cad1. Luego podemos modificar el contenido de esta posición de memoria ➥utilizando la función gets. */
char cad1[50]; /* Se reserva espacio para 50 caracteres. */
/* Incorrecto. Se genera un error en la compilación del programa, porque no ➥se reserva el espacio correspondiente. */
char cad2[20] = "México"; /* Correcto. */
puts(cad2);
gets(cad2);
/* El valor de una cadena (declarada como cadena[longitud]) se puede modificar ➥por medio de lecturas o utilizando funciones de la biblioteca string.h (ejemplo 7.6). */
puts(cad2);
/* Incorrecto. No se puede asignar una cadena a un solo elemento del arreglo. Si quieres copiar "Guatemala" a partir de la posición 10, usa strcpy(&cad2[10], "Guatemala"); si solo quieres asignar un carácter, usa cad2[10] = 'G'; */
}