#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nombre[2];
    int carrera;
    float promedio;
} alumno;

void escribirDatosAlumnos(const char *nombreArchivo);
void leerDatosAlumnos(const char *nombreArchivo);

int main() {
    const char *nombreArchivo = "datos_alumnos.dat";

    escribirDatosAlumnos(nombreArchivo);

    printf("\n--- Lectura de datos desde el archivo ---\n");
    leerDatosAlumnos(nombreArchivo);

    printf("\nPrograma finalizado.\n");
    return 0;
}

void escribirDatosAlumnos(const char *nombreArchivo) {
    FILE *archivo;
    int numAlumnos, i;
    alumno *unAlumno;

    archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo %s para escritura.\n", nombreArchivo);
        exit(EXIT_FAILURE);
    }

    printf("--- Escritura de datos de alumnos ---\n");
    printf("Ingrese el número de alumnos a registrar: ");
    scanf("%d", &numAlumnos);

    fwrite(&numAlumnos, sizeof(int), 1, archivo);

    for (i = 0; i < numAlumnos; i++) {
        unAlumno = (alumno *)malloc(sizeof(alumno));
        if (unAlumno == NULL) {
            printf("Error: No se pudo asignar memoria para el alumno %d.\n", i + 1);
            fclose(archivo);
            exit(EXIT_FAILURE);
        }

        printf("\nDatos del alumno %d:\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &unAlumno->matricula);
        while (getchar() != '\n');
        printf("Nombre (máx. 19 caracteres): ");
        gets(unAlumno->nombre);
        printf("Carrera (1-Ciberseguridad, 2-Sonido, 3-Mecatronica, 4-Sofware, 5-Multimedia, 6-Telecomunicaciones.): ");
        scanf("%d", &unAlumno->carrera);
        printf("Promedio: ");
        scanf("%f", &unAlumno->promedio);

        fwrite(unAlumno, sizeof(alumno), 1, archivo);
        free(unAlumno);
    }

    fclose(archivo);
    printf("\nDatos de alumnos guardados exitosamente en %s.\n", nombreArchivo);
}

void leerDatosAlumnos(const char *nombreArchivo) {
    FILE *archivo;
    int numAlumnos, i;
    alumno *listaAlumnos;

    archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo %s para lectura.\n", nombreArchivo);
        return;
    }

    fread(&numAlumnos, sizeof(int), 1, archivo);
    listaAlumnos = (alumno *)malloc(numAlumnos * sizeof(alumno));
    if (listaAlumnos == NULL) {
        printf("Error: No se pudo asignar memoria para la lista de alumnos.\n");
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    fread(listaAlumnos, sizeof(alumno), numAlumnos, archivo);

    printf("Datos de los alumnos leídos:\n");
    alumno *ptr = listaAlumnos;
    for (i = 0; i < numAlumnos; i++) {
        printf("----------------------------------------\n");
        printf("Alumno %d:\n", i + 1);
        printf("  Matrícula: %d\n", ptr->matricula);
        printf("  Nombre: %s\n", ptr->nombre);
        printf("  Carrera: %d\n", ptr->carrera);
        printf("  Promedio: %.2f\n", ptr->promedio);
        ptr++;
    }
    printf("----------------------------------------\n");

    free(listaAlumnos);
    fclose(archivo);
}