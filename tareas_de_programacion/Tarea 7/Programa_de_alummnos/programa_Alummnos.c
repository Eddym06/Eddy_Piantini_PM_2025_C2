#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_ALUMNOS 100
#define LIMITE_NOMBRE 50

typedef struct {
    char nombre[LIMITE_NOMBRE];
    float promedio;
} Alumno;

void mostrar_menu();
void cargar_datos(Alumno lista[], int *cantidad);
void guardar_datos(Alumno lista[], int cantidad);
void agregar(Alumno lista[], int *cantidad);
void ordenar_por_nombre(Alumno lista[], int cantidad);
void ordenar_por_promedio(Alumno lista[], int cantidad);
void mostrar_lista(Alumno lista[], int cantidad);

int main() {
    Alumno grupo[LIMITE_ALUMNOS];
    int total = 0;
    int eleccion;

    cargar_datos(grupo, &total);

    while (1) {
        mostrar_menu();
        scanf("%d", &eleccion);
        getchar(); // Limpieza rápida del buffer

        if (eleccion == 1) {
            agregar(grupo, &total);
            guardar_datos(grupo, total);
        } else if (eleccion == 2) {
            ordenar_por_nombre(grupo, total);
            mostrar_lista(grupo, total);
        } else if (eleccion == 3) {
            ordenar_por_promedio(grupo, total);
            mostrar_lista(grupo, total);
        } else if (eleccion == 4) {
            puts("Hasta luego :)");
            break;
        } else {
            puts("Opción incorrecta. Intente de nuevo.");
        }
    }

    return 0;
}

void mostrar_menu() {
    puts("\n--- Gestor de Alumnos ---");
    puts("1. Añadir alumno");
    puts("2. Ver alumnos ordenados por nombre");
    puts("3. Ver alumnos ordenados por promedio");
    puts("4. Salir");
    printf("¿Qué desea hacer?: ");
}

void agregar(Alumno lista[], int *cantidad) {
    if (*cantidad >= LIMITE_ALUMNOS) {
        puts("¡Capacidad llena! No se pueden agregar más alumnos.");
        return;
    }

    printf("Nombre: ");
    fgets(lista[*cantidad].nombre, LIMITE_NOMBRE, stdin);
    lista[*cantidad].nombre[strcspn(lista[*cantidad].nombre, "\n")] = 0;

    float nota;
    do {
        printf("Promedio (0 a 10): ");
        scanf("%f", &nota);
        getchar();
        if (nota < 0 || nota > 10) puts("Ese número está fuera de rango.");
    } while (nota < 0 || nota > 10);

    lista[*cantidad].promedio = nota;
    (*cantidad)++;
}

void guardar_datos(Alumno lista[], int cantidad) {
    FILE *archivo = fopen("alumnos.dat", "wb");
    if (!archivo) {
        puts("Error al intentar guardar.");
        return;
    }
    fwrite(lista, sizeof(Alumno), cantidad, archivo);
    fclose(archivo);
    puts("Datos guardados correctamente.");
}

void cargar_datos(Alumno lista[], int *cantidad) {
    FILE *archivo = fopen("alumnos.dat", "rb");
    if (!archivo) return;

    *cantidad = 0;
    while (fread(&lista[*cantidad], sizeof(Alumno), 1, archivo)) {
        (*cantidad)++;
    }
    fclose(archivo);
}

void ordenar_por_nombre(Alumno lista[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (strcmp(lista[j].nombre, lista[j + 1].nombre) > 0) {
                Alumno temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void ordenar_por_promedio(Alumno lista[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (lista[j].promedio < lista[j + 1].promedio) {
                Alumno temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void mostrar_lista(Alumno lista[], int cantidad) {
    if (cantidad == 0) {
        puts("Aún no hay alumnos registrados.");
        return;
    }

    puts("\nLista actual de alumnos:");
    puts("------------------------------");
    printf("%-25s | %s\n", "Nombre", "Promedio");
    puts("------------------------------");
    for (int i = 0; i < cantidad; i++) {
        printf("%-25s | %.2f\n", lista[i].nombre, lista[i].promedio);
    }
}
