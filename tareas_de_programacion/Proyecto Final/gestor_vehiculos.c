#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Constantes y Estructuras
#define MAX_VEHICULOS 50
#define NOMBRE_ARCHIVO "vehiculos.dat"

// Estructura de datos del vehiculo 
typedef struct {
char placa[20];
char marca[50];
char modelo[50];
char tipo_combustible[10];
float km_por_galon_carretera;
float km_por_galon_ciudad;
float costo_gomas;
float km_gomas;
float costo_seguro_anual;
float costo_mantenimiento;
float km_por_mantenimiento;
float costo_vehiculo;
float valor_reventa;
int vida_util_anios;
float km_anual_promedio;
} Vehiculo;

typedef struct {
float costo_gasolina;
float costo_gasoil;
} DatosGenerales;

// Variables Globales
Vehiculo vehiculos[MAX_VEHICULOS];
int num_vehiculos = 0;
DatosGenerales datos_generales = { 285.50f, 231.10f }; // Precios iniciales

// Prototipos de Funciones
void crearVehiculo();
void modificarVehiculo();
void eliminarVehiculo();
void listarVehiculos();
void configurarDatosGenerales();
void calcularCostoViaje();
void mostrarMenu();

// Funciones para persistencia con archivos binarios 
void guardarDatos();
void cargarDatos();

// Funciones de utilidad
void limpiarBufferEntrada();
void presioneEnterParaContinuar();
void limpiarPantalla();
int buscarVehiculoPorPlaca(const char* placa);
void leerCadena(const char* mensaje, char* destino, int tamano);


// Funcion Principal
int main() {
cargarDatos();
mostrarMenu();
return 0;
}

// Implementacion de Funciones del Menu

void mostrarMenu() {
int opcion;
do {
limpiarPantalla();

// Configurar color cian para el titulo
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

printf("=============================================\n");
printf("     SISTEMA DE GESTION DE VEHICULOS\n");
printf("=============================================\n");

// Restablecer color a blanco
SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

printf("   Precio Gasolina: $%.2f\n", datos_generales.costo_gasolina);
printf("   Precio Gasoil:   $%.2f\n", datos_generales.costo_gasoil);

// Configurar color cian para la linea de separacion
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
printf("---------------------------------------------\n");

// Restablecer color a blanco
SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

printf("1. Crear Vehiculo\n");
printf("2. Modificar Vehiculo\n");
printf("3. Eliminar Vehiculo\n");
printf("4. Listar Vehiculos\n");
printf("5. Calcular Costo de Viaje\n");
printf("6. Configurar Precios de Combustible\n");
printf("0. Salir y Guardar\n");

// Configurar color cian para la linea de separacion
SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
printf("=============================================\n");

// Restablecer color a blanco
SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

printf("Seleccione una opcion: ");
scanf("%d", &opcion);
limpiarBufferEntrada();

switch (opcion) {
case 1: crearVehiculo(); break;
case 2: modificarVehiculo(); break;
case 3: eliminarVehiculo(); break;
case 4: listarVehiculos(); break;
case 5: calcularCostoViaje(); break;
case 6: configurarDatosGenerales(); break;
case 0:
guardarDatos();
printf("Datos guardados. Saliendo del programa...\n");
break;
default:
printf("Opcion no valida. Por favor, intente de nuevo.\n");
break;
}
if (opcion != 0) {
presioneEnterParaContinuar();
}
} while (opcion != 0);
}

void crearVehiculo() {
limpiarPantalla();
printf("--- CREAR NUEVO VEHICULO ---\n");
if (num_vehiculos >= MAX_VEHICULOS) {
printf("Error: Se ha alcanzado el maximo de vehiculos.\n");
return;
}

Vehiculo v;
float temp_float;
int temp_int;

leerCadena("Placa: ", v.placa, 20);
if (buscarVehiculoPorPlaca(v.placa) != -1) {
printf("Error: La placa '%s' ya existe.\n", v.placa);
return;
}

leerCadena("Marca: ", v.marca, 50);
leerCadena("Modelo: ", v.modelo, 50);

do {
leerCadena("Tipo de combustible (Gasolina/Gasoil): ", v.tipo_combustible, 10);
} while (strcmp(v.tipo_combustible, "Gasolina") != 0 && strcmp(v.tipo_combustible, "Gasoil") != 0);

// Bucle do-while para validacion de entrada 
do {
printf("Rendimiento en carretera (Km/Galon): ");
scanf("%f", &temp_float);
limpiarBufferEntrada();
} while (temp_float <= 0);
v.km_por_galon_carretera = temp_float;

do {
printf("Rendimiento en ciudad (Km/Galon): ");
scanf("%f", &temp_float);
limpiarBufferEntrada();
} while (temp_float <= 0);
v.km_por_galon_ciudad = temp_float;

printf("Costo de las 4 gomas: ");
scanf("%f", &v.costo_gomas);
limpiarBufferEntrada();

printf("Duracion de las gomas (Km): ");
scanf("%f", &v.km_gomas);
limpiarBufferEntrada();

printf("Costo del seguro anual: ");
scanf("%f", &v.costo_seguro_anual);
limpiarBufferEntrada();

printf("Costo por mantenimiento: ");
scanf("%f", &v.costo_mantenimiento);
limpiarBufferEntrada();

printf("Kilometros entre mantenimientos: ");
scanf("%f", &v.km_por_mantenimiento);
limpiarBufferEntrada();

printf("Costo inicial del vehiculo: ");
scanf("%f", &v.costo_vehiculo);
limpiarBufferEntrada();

printf("Valor de reventa del vehiculo: ");
scanf("%f", &v.valor_reventa);
limpiarBufferEntrada();

do {
printf("Vida util del vehiculo (anios): ");
scanf("%d", &temp_int);
limpiarBufferEntrada();
} while (temp_int <= 0);
v.vida_util_anios = temp_int;

do {
printf("Kilometraje anual promedio: ");
scanf("%f", &temp_float);
limpiarBufferEntrada();
} while (temp_float <= 0);
v.km_anual_promedio = temp_float;

vehiculos[num_vehiculos] = v;
num_vehiculos++;
printf("\nVehiculo anadido correctamente!\n");
}

void modificarVehiculo() {
char placa_buscada[20];
limpiarPantalla();
printf("--- MODIFICAR VEHICULO ---\n");
if (num_vehiculos == 0) {
printf("No hay vehiculos para modificar.\n");
return;
}

listarVehiculos();
leerCadena("\nIngrese la placa del vehiculo a modificar: ", placa_buscada, 20);

int indice = buscarVehiculoPorPlaca(placa_buscada);
if (indice == -1) {
printf("Error: No se encontro un vehiculo con esa placa.\n");
return;
}

printf("\nModificando vehiculo con placa %s. Deje en blanco para no cambiar.\n", placa_buscada);

// Pedir todos los datos de nuevo, 
Vehiculo* v = &vehiculos[indice]; // Puntero a la estructura en el arreglo 

printf("Introduzca los nuevos datos:\n");
leerCadena("Marca: ", v->marca, 50);
leerCadena("Modelo: ", v->modelo, 50);

do {
leerCadena("Tipo de combustible (Gasolina/Gasoil): ", v->tipo_combustible, 10);
} while (strcmp(v->tipo_combustible, "Gasolina") != 0 && strcmp(v->tipo_combustible, "Gasoil") != 0);

printf("Rendimiento en carretera (Km/Galon): ");
scanf("%f", &v->km_por_galon_carretera);
limpiarBufferEntrada();

printf("Rendimiento en ciudad (Km/Galon): ");
scanf("%f", &v->km_por_galon_ciudad);
limpiarBufferEntrada();

printf("Costo de las 4 gomas: ");
scanf("%f", &v->costo_gomas);
limpiarBufferEntrada();

printf("Duracion de las gomas (Km): ");
scanf("%f", &v->km_gomas);
limpiarBufferEntrada();

printf("Costo del seguro anual: ");
scanf("%f", &v->costo_seguro_anual);
limpiarBufferEntrada();

printf("Costo por mantenimiento: ");
scanf("%f", &v->costo_mantenimiento);
limpiarBufferEntrada();

printf("Kilometros entre mantenimientos: ");
scanf("%f", &v->km_por_mantenimiento);
limpiarBufferEntrada();

printf("Costo inicial del vehiculo: ");
scanf("%f", &v->costo_vehiculo);
limpiarBufferEntrada();

printf("Valor de reventa del vehiculo: ");
scanf("%f", &v->valor_reventa);
limpiarBufferEntrada();

printf("Vida util del vehiculo (anios): ");
scanf("%d", &v->vida_util_anios);
limpiarBufferEntrada();

printf("Kilometraje anual promedio: ");
scanf("%f", &v->km_anual_promedio);
limpiarBufferEntrada();

printf("\nVehiculo modificado correctamente!\n");
}

void eliminarVehiculo() {
char placa_buscada[20];
limpiarPantalla();
printf("--- ELIMINAR VEHICULO ---\n");
if (num_vehiculos == 0) {
printf("No hay vehiculos para eliminar.\n");
return;
}

listarVehiculos();
leerCadena("\nIngrese la placa del vehiculo a eliminar: ", placa_buscada, 20);

int indice = buscarVehiculoPorPlaca(placa_buscada);
if (indice == -1) {
printf("Error: No se encontro un vehiculo con esa placa.\n");
return;
}

// Desplazar los elementos del arreglo para llenar el hueco
for (int i = indice; i < num_vehiculos - 1; i++) {
vehiculos[i] = vehiculos[i + 1];
}
num_vehiculos--;

printf("\nVehiculo con placa %s eliminado correctamente.\n", placa_buscada);
}


void listarVehiculos() {
limpiarPantalla();
printf("--- LISTA DE VEHICULOS ---\n");
if (num_vehiculos == 0) {
printf("No hay vehiculos registrados.\n");
return;
}

printf("%-15s | %-15s | %-15s | %-10s\n", "Placa", "Marca", "Modelo", "Combustible");
printf("------------------------------------------------------------------\n");
for (int i = 0; i < num_vehiculos; i++) {
printf("%-15s | %-15s | %-15s | %-10s\n",
vehiculos[i].placa,
vehiculos[i].marca,
vehiculos[i].modelo,
vehiculos[i].tipo_combustible);
}
}

void calcularCostoViaje() {
char placa_buscada[20];
limpiarPantalla();
printf("--- CALCULAR COSTO DE VIAJE ---\n");
if (num_vehiculos == 0) {
printf("No hay vehiculos registrados para calcular.\n");
return;
}

listarVehiculos();
leerCadena("\nIngrese la placa del vehiculo a utilizar: ", placa_buscada, 20);

int indice = buscarVehiculoPorPlaca(placa_buscada);
if (indice == -1) {
printf("Error: Vehiculo no encontrado.\n");
return;
}

Vehiculo v = vehiculos[indice];
float km_viaje, porc_ciudad;

printf("Ingrese los kilometros totales del viaje: ");
scanf("%f", &km_viaje);
limpiarBufferEntrada();

printf("Ingrese el porcentaje del viaje en ciudad (0-100): ");
scanf("%f", &porc_ciudad);
limpiarBufferEntrada();

// Validar porcentaje
if (porc_ciudad < 0) porc_ciudad = 0;
if (porc_ciudad > 100) porc_ciudad = 100;

// Calculos
float km_ciudad = km_viaje * (porc_ciudad / 100.0);
float km_carretera = km_viaje - km_ciudad;

float costo_comb_tipo = (strcmp(v.tipo_combustible, "Gasolina") == 0) ? datos_generales.costo_gasolina : datos_generales.costo_gasoil;

// Estructura selectiva 'if' 
float costo_combustible = 0;
if (v.km_por_galon_ciudad > 0) {
costo_combustible += (km_ciudad / v.km_por_galon_ciudad) * costo_comb_tipo;
}
if (v.km_por_galon_carretera > 0) {
costo_combustible += (km_carretera / v.km_por_galon_carretera) * costo_comb_tipo;
}

float costo_gomas = (v.km_gomas > 0) ? v.costo_gomas * (km_viaje / v.km_gomas) : 0;
float costo_seguro = (v.km_anual_promedio > 0) ? v.costo_seguro_anual * (km_viaje / v.km_anual_promedio) : 0;
float costo_mantenimiento = (v.km_por_mantenimiento > 0) ? v.costo_mantenimiento * (km_viaje / v.km_por_mantenimiento) : 0;

float depreciacion_total = v.costo_vehiculo - v.valor_reventa;
float km_vida_util = v.vida_util_anios * v.km_anual_promedio;
float costo_depreciacion = (km_vida_util > 0) ? (depreciacion_total / km_vida_util) * km_viaje : 0;

float costo_total = costo_combustible + costo_gomas + costo_seguro + costo_mantenimiento + costo_depreciacion;
float costo_por_km = (km_viaje > 0) ? costo_total / km_viaje : 0;

printf("\n--- DESGLOSE DE COSTOS ---\n");
printf("Combustible:       $ %8.2f\n", costo_combustible);
printf("Gomas:             $ %8.2f\n", costo_gomas);
printf("Seguro:            $ %8.2f\n", costo_seguro);
printf("Mantenimiento:     $ %8.2f\n", costo_mantenimiento);
printf("Depreciacion:      $ %8.2f\n", costo_depreciacion);
printf("--------------------------------\n");
printf("COSTO TOTAL:       $ %8.2f\n", costo_total);
printf("COSTO POR KM:      $ %8.2f\n", costo_por_km);
}


void configurarDatosGenerales() {
limpiarPantalla();
printf("--- CONFIGURAR PRECIOS ---\n");
printf("Precio actual de Gasolina: %.2f\n", datos_generales.costo_gasolina);
printf("Nuevo precio por galon de Gasolina: ");
scanf("%f", &datos_generales.costo_gasolina);
limpiarBufferEntrada();

printf("\nPrecio actual de Gasoil: %.2f\n", datos_generales.costo_gasoil);
printf("Nuevo precio por galon de Gasoil: ");
scanf("%f", &datos_generales.costo_gasoil);
limpiarBufferEntrada();

printf("\nPrecios actualizados!\n");
}


// Funciones de Persistencia para guardsar los datos 

void guardarDatos() {
FILE *archivo = fopen(NOMBRE_ARCHIVO, "wb"); // "wb" para escritura binaria
if (archivo == NULL) {
printf("Error: No se pudo abrir el archivo %s para guardar.\n", NOMBRE_ARCHIVO);
return;
}

// Guardar primero la configuracion general
fwrite(&datos_generales, sizeof(DatosGenerales), 1, archivo);
// Guardar el numero de vehiculos
fwrite(&num_vehiculos, sizeof(int), 1, archivo);
// Guardar el arreglo completo de vehiculos
fwrite(vehiculos, sizeof(Vehiculo), num_vehiculos, archivo);

fclose(archivo);
}


void cargarDatos() {
FILE *archivo = fopen(NOMBRE_ARCHIVO, "rb"); // "rb" para lectura binaria
if (archivo == NULL) {
printf("Archivo de datos no encontrado. Se creara uno nuevo al salir.\n");
return;
}

// Cargar la configuracion general
fread(&datos_generales, sizeof(DatosGenerales), 1, archivo);
// Cargar el numero de vehiculos
fread(&num_vehiculos, sizeof(int), 1, archivo);
// Cargar el arreglo de vehiculos
fread(vehiculos, sizeof(Vehiculo), num_vehiculos, archivo);

fclose(archivo);
printf("Se cargaron %d vehiculos desde %s\n", num_vehiculos, NOMBRE_ARCHIVO);
presioneEnterParaContinuar();
}


// Funciones de Utilidad

void limpiarBufferEntrada() {
int c;
while ((c = getchar()) != '\n' && c != EOF);
}

void presioneEnterParaContinuar() {
printf("\nPresione ENTER para continuar...");
getchar();
}

void limpiarPantalla() {
system("cls"); // Para Windows

}

int buscarVehiculoPorPlaca(const char* placa) {
for (int i = 0; i < num_vehiculos; i++) {
if (strcmp(vehiculos[i].placa, placa) == 0) {
return i; // Devuelve el indice del vehiculo
}
}
return -1; // No se encontro
}

// Funcion para leer una linea de texto de forma segura
void leerCadena(const char* mensaje, char* destino, int tamano) {
printf("%s", mensaje);
fgets(destino, tamano, stdin);
// Eliminar el salto de linea que fgets suele anadir
destino[strcspn(destino, "\n")] = 0;
}

// Espero que le haya gustado mi codigo profesor ;)
