#include <stdio.h>
/* Traspuesta.
El programa calcula la traspuesta de una matriz. */
const int MAX = 50;
void Lectura(int [][MAX], int, int);
void Traspuesta(int [][MAX], int [][MAX], int, int);
void Imprime(int [][MAX], int, int);

int main(void) {
    int MAT[MAX][MAX], TRA[MAX][MAX];
    int FIL, COL;

    do {
        printf("Ingrese el número de filas de la matriz: ");
        scanf("%d", &FIL);
    } while (FIL > MAX || FIL < 1);

    do {
        printf("Ingrese el número de columnas de la matriz: ");
        scanf("%d", &COL);
    } while (COL > MAX || COL < 1);

    Lectura(MAT, FIL, COL);
    Traspuesta(MAT, TRA, FIL, COL);
    Imprime(TRA, COL, FIL);

    return 0;
}

/* Esta función se utiliza para una matriz de tipo entero de F filas y C columnas. */
void Lectura(int A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++) {
            printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

/* Esta función se utiliza para calcular la traspuesta. */
void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            M2[J][I] = M1[I][J];
}

/* Esta función se utiliza para escribir una matriz de tipo entero de F filas y C columnas —en este caso la traspuesta. */
void Imprime(int A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            printf("\nElemento %d %d: %d", I + 1, J + 1, A[I][J]);
}