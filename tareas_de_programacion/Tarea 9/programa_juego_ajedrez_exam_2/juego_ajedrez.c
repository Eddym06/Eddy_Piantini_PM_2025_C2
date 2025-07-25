#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

// estructuras de datos como nos enseña el libro con el cap 8
typedef struct {
char pieza[4]; // almacena el símbolo de la pieza en formato utf-8 (ej. ♟, ♜)
char color; // w (blancas), b (negras)
} Casilla;

// tablero global usando un arreglo 2d como en el libro
Casilla tablero[8][8];
char jugadorActual = 'W'; // empiezan las blancas

// nuevo: variables para rastrear el ultimo movimiento y resaltarlo
int ultimaFilaIni = -1, ultimaColIni = -1;
int ultimaFilaFin = -1, ultimaColFin = -1;

// prototipos de funciones 
void establecer_color(int color);
void configurar_terminal();
void inicializarTablero();
void imprimirTablero();
int parsearMovimiento(const char* mov, int* filaIni, int* colIni, int* filaFin, int* colFin);
int esMovimientoValido(int filaIni, int colIni, int filaFin, int colFin, int verificarJaquePropio);
void hacerMovimiento(int filaIni, int colIni, int filaFin, int colFin);
int estaElReyEnJaque(char colorRey);
int hayPiezasEnMedio(int filaIni, int colIni, int filaFin, int colFin);
int esJaqueMate(char colorRey);
void limpiarBufferEntrada();


int main() {

configurar_terminal();

char entradaMov[10];
int juegoTerminado = 0;
inicializarTablero(); 

while (!juegoTerminado) {
imprimirTablero(); 


if (estaElReyEnJaque(jugadorActual)) {
if (esJaqueMate(jugadorActual)) {
printf("\n!!! JAQUE MATE !!!\n");
printf("Gana el jugador %s\n", (jugadorActual == 'W') ? "Negro" : "Blanco");
juegoTerminado = 1; 
continue; 
}
establecer_color(14); 
printf("\n JAQUE!! Tu rey esta en peligroooo!!!.\n");
establecer_color(7); // restaura el color por defecto
}

establecer_color(11);
printf("\nTurno del jugador %s. Ingrese movimiento (ej: e2e4) o para finalizar (salir): ", (jugadorActual == 'W') ? "Blanco" : "Negro");
establecer_color(7);
scanf("%s", entradaMov);


if (strcmp(entradaMov, "salir") == 0) {
break;
}

int filaIni, colIni, filaFin, colFin;

if (!parsearMovimiento(entradaMov, &filaIni, &colIni, &filaFin, &colFin)) {
establecer_color(12); 
printf("Formato de movimiento invalido.\n");
establecer_color(7);
printf("Presiona Enter para continuar...");
limpiarBufferEntrada();
getchar();
continue; 
}


if (esMovimientoValido(filaIni, colIni, filaFin, colFin, 1)) {
// guardar las coordenadas antes de hacer el movimiento para resaltarlas, y funciona con la funcion esUltimoMovimiento
ultimaFilaIni = filaIni;
ultimaColIni = colIni;
ultimaFilaFin = filaFin;
ultimaColFin = colFin;


hacerMovimiento(filaIni, colIni, filaFin, colFin);
jugadorActual = (jugadorActual == 'W') ? 'B' : 'W';
} else {
establecer_color(12);
printf("MOVIMIENTO INVALIDO\n");
establecer_color(7);
printf("Presiona Enter para continuar...");
limpiarBufferEntrada();
getchar();
}
}
return 0;
}

// IMPLEMENTACION DE FUNCIONES (La mejor parte del codigo)

// limpiamos el buffer de entrada para evitar lecturas indeseadas con scanf
void limpiarBufferEntrada() {
int c;
while ((c = getchar()) != '\n' && c != EOF);
}

// establece el color del texto y del fondo en la consola de windows
void establecer_color(int color) {
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// se configura la consola de windows para que acepte caracteres utf-8
void configurar_terminal() {
// esto asegura que la consola entienda los símbolos unicode. 
SetConsoleOutputCP(65001); 
}

// coloca las piezas en su posición inicial en el tablero
void inicializarTablero() {
// matriz de caracteres con Char para la configuración inicial de las piezas
char setup_inicial[8][8] = {
{'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'}, {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, {'t', 'c', 'a', 'd', 'r', 'a', 'c', 't'}
};

// símbolos unicode para las piezas negras y blancas
const char* piezas_negras[] = {"\xE2\x99\x9F", "\xE2\x99\x9C", "\xE2\x99\x9E", "\xE2\x99\x9D", "\xE2\x99\x9B", "\xE2\x99\x9A"}; // ♟ ♜ ♞ ♝ ♛ ♚
const char* piezas_blancas[] = {"\xE2\x99\x99", "\xE2\x99\x96", "\xE2\x99\x98", "\xE2\x99\x97", "\xE2\x99\x95", "\xE2\x99\x94"}; // ♙ ♖ ♘ ♗ ♕ ♔
// Yo he añadido un arreglo de cadenas para las piezas, lo que permite usar los símbolos unicode directamente en el tablero
// recorre la matriz de configuración para inicializar el tablero global
for (int f = 0; f < 8; f++) {
for (int c = 0; c < 8; c++) {
char pieza = setup_inicial[f][c];
if (islower(pieza)) { // las letras minúsculas son piezas blancas
tablero[f][c].color = 'W';
// asigna el símbolo unicode correcto a la pieza blanca
switch (tolower(pieza)) {
case 't': strcpy_s(tablero[f][c].pieza, 4, piezas_blancas[1]); break; // torre (♖)
case 'c': strcpy_s(tablero[f][c].pieza, 4, piezas_blancas[2]); break; // caballo (♘)
case 'a': strcpy_s(tablero[f][c].pieza, 4, piezas_blancas[3]); break; // alfil (♗)
case 'd': strcpy_s(tablero[f][c].pieza, 4, piezas_blancas[4]); break; // dama (♕)
case 'r': strcpy_s(tablero[f][c].pieza, 4, piezas_blancas[5]); break; // rey (♔)
case 'p': strcpy_s(tablero[f][c].pieza, 4, piezas_blancas[0]); break; // peón (♙)
}
} else if (isupper(pieza)) { // las letras mayúsculas son piezas negras
tablero[f][c].color = 'B';
// asigna el símbolo unicode correcto a la pieza negra
switch (pieza) {
case 'T': strcpy_s(tablero[f][c].pieza, 4, piezas_negras[1]); break; // torre (♜)
case 'C': strcpy_s(tablero[f][c].pieza, 4, piezas_negras[2]); break; // caballo (♞)
case 'A': strcpy_s(tablero[f][c].pieza, 4, piezas_negras[3]); break; // alfil (♝)
case 'D': strcpy_s(tablero[f][c].pieza, 4, piezas_negras[4]); break; // dama (♛)
case 'R': strcpy_s(tablero[f][c].pieza, 4, piezas_negras[5]); break; // rey (♚)
case 'P': strcpy_s(tablero[f][c].pieza, 4, piezas_negras[0]); break; // peón (♟)
}
} else { // si es un espacio, simplemente la casilla está vacía
tablero[f][c].color = ' ';
tablero[f][c].pieza[0] = ' ';
tablero[f][c].pieza[1] = '\0';
}
}
}
}

// Como me gusta la estetica esta funcion dibuja el tablero en la consola con colores y coordenadas
void imprimirTablero() {
system("cls"); // limpia la pantalla para redibujar el tablero
printf("\n\n            negras\n");
printf("    a  b  c  d  e  f  g  h\n\n");
for (int f = 0; f < 8; f++) {
printf(" %d ", 8 - f); // imprime el número de la fila
for (int c = 0; c < 8; c++) {
char* pieza = tablero[f][c].pieza;
char color = tablero[f][c].color; 

// comprueba si la casilla actual fue parte del último movimiento, recuerden que les mencione arriba con lo que se usaba esta funcion
int esCasillaUltimoMov = (f == ultimaFilaIni && c == ultimaColIni) || (f == ultimaFilaFin && c == ultimaColFin);
// alterna el color de fondo de las casillas, para eso implemente esa pequeña logica matematica
int fondo = ((f + c) % 2 == 0) ? 240 : 0;

if (esCasillaUltimoMov) {
fondo = 204; // fondo rojo intenso para el ultimo movimiento
}

if (pieza[0] == ' ') { // si la casilla está vacía
establecer_color(fondo);
printf("   ");
} else { // si hay una pieza en la casilla
int color_pieza = (color == 'W') ? 8 : 7; 
establecer_color(fondo | color_pieza);
printf(" %s ", pieza); // imprime el símbolo de la pieza
}
}
establecer_color(7); // restaura el color por defecto
printf(" %d\n", 8 - f);
}
printf("\n    a  b  c  d  e  f  g  h\n");
printf("           blancas\n");
}

// convierte una entrada de texto (ej. "a1b2") en coordenadas numéricas
int parsearMovimiento(const char* mov, int* filaIni, int* colIni, int* filaFin, int* colFin) {
if (strlen(mov) != 4) return 0; // el movimiento debe tener 4 caracteres
// convierte la letra de la columna a un número (a=0, b=1, ...)
*colIni = tolower(mov[0]) - 'a';
// convierte el número de la fila a un índice del arreglo (8=0, 7=1, ...)
*filaIni = '8' - mov[1];
*colFin = tolower(mov[2]) - 'a';
*filaFin = '8' - mov[3];
// valida que las coordenadas estén dentro del tablero (0-7)
if (*filaIni < 0 || *filaIni > 7 || *colIni < 0 || *colIni > 7 ||
*filaFin < 0 || *filaFin > 7 || *colFin < 0 || *colFin > 7) {
return 0; // coordenadas fuera de rango
}
return 1;
}

// actualiza el tablero moviendo una pieza de una casilla a otra
void hacerMovimiento(int filaIni, int colIni, int filaFin, int colFin) {
// copia la pieza y el color a la nueva casilla
strcpy_s(tablero[filaFin][colFin].pieza, 4, tablero[filaIni][colIni].pieza);
tablero[filaFin][colFin].color = tablero[filaIni][colIni].color;
// vacía la casilla de origen
tablero[filaIni][colIni].pieza[0] = ' ';
tablero[filaIni][colIni].pieza[1] = '\0';
tablero[filaIni][colIni].color = ' ';
}

// verifica si el rey de un color específico está bajo ataque
int estaElReyEnJaque(char colorRey) {
int filaRey = -1, colRey = -1;
// primero, encuentra la posición del rey
for (int f = 0; f < 8; f++) {
for (int c = 0; c < 8; c++) {
// busca el símbolo del rey (negro o blanco) del color correspondiente
if ((strcmp(tablero[f][c].pieza, "\xE2\x99\x9A") == 0 || strcmp(tablero[f][c].pieza, "\xE2\x99\x94") == 0) && tablero[f][c].color == colorRey) {
filaRey = f;
colRey = c;
break; // rey encontrado
}
}
}
// ahora, comprueba si alguna pieza del oponente puede atacar esa casilla
char colorOponente = (colorRey == 'W') ? 'B' : 'W';
for (int f = 0; f < 8; f++) {
for (int c = 0; c < 8; c++) {
// para cada pieza del oponente...
if (tablero[f][c].color == colorOponente) {
char jugadorOriginal = jugadorActual;
jugadorActual = colorOponente; // simula que es el turno del oponente
// con esmovimientovalido comprueba si alguna pieza puede moverse a la casilla del rey
if (esMovimientoValido(f, c, filaRey, colRey, 0)) {
jugadorActual = jugadorOriginal; // restaura el turno
return 1; // el 1 significa quel rey está en jaque
}
jugadorActual = jugadorOriginal; // restaura el turno
}
}
}
return 0; // y el 0 es que el rey no está en jaque
}

// verifica si hay piezas bloqueando un movimiento en línea recta o diagonal
int hayPiezasEnMedio(int filaIni, int colIni, int filaFin, int colFin) {
int difFila = filaFin - filaIni;
int difCol = colFin - colIni;
// aqui se determina la dirección del movimiento paso a paso
int pasoFila = (difFila > 0) ? 1 : (difFila < 0) ? -1 : 0;
int pasoCol = (difCol > 0) ? 1 : (difCol < 0) ? -1 : 0;
// se empieza a revisar desde la siguiente casilla en la trayectoria
int filaActual = filaIni + pasoFila;
int colActual = colIni + pasoCol;
// recorre la trayectoria hasta llegar a la casilla final
while (filaActual != filaFin || colActual != colFin) {
if (tablero[filaActual][colActual].pieza[0] != ' ') return 1; // hay una pieza bloqueando
filaActual += pasoFila;
colActual += pasoCol;
}
return 0; // no hay piezas en medio
}

// valida si un movimiento es legal según las reglas del ajedrez
int esMovimientoValido(int filaIni, int colIni, int filaFin, int colFin, int verificarJaquePropio) {
Casilla piezaInicio = tablero[filaIni][colIni];
Casilla piezaFin = tablero[filaFin][colFin];
int esValido = 0;

// validaciones básicas
if (piezaInicio.pieza[0] == ' ') return 0; // no se puede mover una casilla vacía
if (piezaInicio.color != jugadorActual) return 0; // no es el turno de este jugador
if (piezaFin.color == jugadorActual) return 0; // no se puede capturar una pieza propia

int difFilaAbs = abs(filaIni - filaFin);
int difColAbs = abs(colIni - colFin);

// lógica de movimiento para cada tipo de pieza
// esta estructura de if-else if funciona como un 'switch' para cadenas de texto
if (strcmp(piezaInicio.pieza, "\xE2\x99\x9F") == 0 || strcmp(piezaInicio.pieza, "\xE2\x99\x99") == 0) { // peón (♟ o ♙)
if (piezaInicio.color == 'W') { // peón blanco
if (difColAbs == 0 && piezaFin.pieza[0] == ' ' && filaFin == filaIni - 1) esValido = 1; // movimiento simple
if (filaIni == 6 && difColAbs == 0 && piezaFin.pieza[0] == ' ' && filaFin == filaIni - 2 && !hayPiezasEnMedio(filaIni, colIni, filaFin, colFin)) esValido = 1; // primer movimiento doble
if (difColAbs == 1 && piezaFin.pieza[0] != ' ' && filaFin == filaIni - 1) esValido = 1; // captura
} else { // peón negro
if (difColAbs == 0 && piezaFin.pieza[0] == ' ' && filaFin == filaIni + 1) esValido = 1; 
if (filaIni == 1 && difColAbs == 0 && piezaFin.pieza[0] == ' ' && filaFin == filaIni + 2 && !hayPiezasEnMedio(filaIni, colIni, filaFin, colFin)) esValido = 1; 
if (difColAbs == 1 && piezaFin.pieza[0] != ' ' && filaFin == filaIni + 1) esValido = 1; 
}
} else if (strcmp(piezaInicio.pieza, "\xE2\x99\x9C") == 0 || strcmp(piezaInicio.pieza, "\xE2\x99\x96") == 0) { // torre (♜ o ♖)
if ((difFilaAbs == 0 || difColAbs == 0) && !hayPiezasEnMedio(filaIni, colIni, filaFin, colFin)) esValido = 1;
} else if (strcmp(piezaInicio.pieza, "\xE2\x99\x9E") == 0 || strcmp(piezaInicio.pieza, "\xE2\x99\x98") == 0) { // caballo (♞ o ♘)
if ((difFilaAbs == 2 && difColAbs == 1) || (difFilaAbs == 1 && difColAbs == 2)) esValido = 1;
} else if (strcmp(piezaInicio.pieza, "\xE2\x99\x9D") == 0 || strcmp(piezaInicio.pieza, "\xE2\x99\x97") == 0) { // alfil (♝ o ♗)
if (difFilaAbs == difColAbs && !hayPiezasEnMedio(filaIni, colIni, filaFin, colFin)) esValido = 1;
} else if (strcmp(piezaInicio.pieza, "\xE2\x99\x9B") == 0 || strcmp(piezaInicio.pieza, "\xE2\x99\x95") == 0) { // dama (♛ o ♕)
if ((difFilaAbs == difColAbs || difFilaAbs == 0 || difColAbs == 0) && !hayPiezasEnMedio(filaIni, colIni, filaFin, colFin)) esValido = 1;
} else if (strcmp(piezaInicio.pieza, "\xE2\x99\x9A") == 0 || strcmp(piezaInicio.pieza, "\xE2\x99\x94") == 0) { // rey (♚ o ♔)
if (difFilaAbs <= 1 && difColAbs <= 1) esValido = 1;
}

if (!esValido) return 0; // si no cumple ninguna regla de movimiento, es inválido

// si la bandera está activa, verifica si el movimiento deja al propio rey en jaque
if (verificarJaquePropio) {
Casilla copiaTablero[8][8];
memcpy(copiaTablero, tablero, sizeof(tablero)); // crea una copia del tablero
hacerMovimiento(filaIni, colIni, filaFin, colFin); // realiza el movimiento en el tablero real
if (estaElReyEnJaque(piezaInicio.color)) { // comprueba si el rey quedó en jaque
esValido = 0; // si es así, el movimiento no es válido
}
memcpy(tablero, copiaTablero, sizeof(tablero)); // restaura el tablero a su estado original
}

return esValido;
}

// verifica si el jugador está en jaque mate
int esJaqueMate(char colorRey) {
// por que obvio no puede ser jaque mate si el rey no está actualmente en jaque
if (!estaElReyEnJaque(colorRey)) return 0;

// recorre todas las piezas del jugador en jaque
for (int f1 = 0; f1 < 8; f1++) {
for (int c1 = 0; c1 < 8; c1++) {
if (tablero[f1][c1].color == colorRey) {
// intenta mover cada pieza a cada una de las 64 casillas del tablero
for (int f2 = 0; f2 < 8; f2++) {
for (int c2 = 0; c2 < 8; c2++) {
// esmovimientovalido con '1' ya comprueba si el movimiento saca al rey del jaque
if (esMovimientoValido(f1, c1, f2, c2, 1)) {
return 0; // si se encuentra al menos un movimiento legal, no es jaque mate, el jugador se habrá salvado
}
}
}
}
}
}
// si después de probar todos los movimientos posibles, ninguno es legal, lamentablemente es jaque mate
return 1;
}