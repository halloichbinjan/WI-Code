#include <stdio.h>
#include <stdlib.h>

#define ZEILEN 3
#define SPALTEN 4

typedef int MATRIX[ZEILEN][SPALTEN];

void matrixEingabe(MATRIX matrix);
void matrixAusgabe(MATRIX matrix);
void matrixAddition(MATRIX matrix1, MATRIX matrix2, MATRIX matrix3);

int main(void)
{
    MATRIX matrix;
    MATRIX matrix2;
    MATRIX matrix3;
    printf("Matrizenrechnung in C - Ein erstes Programm. \n");
    printf("Bitte die erste Matrix eingeben. \nBitte die 3 x 4 Werte (zeilenweise) eingeben: \n\n");
    matrixEingabe(matrix);
    printf("\n\nBitte die zweite Matrix eingeben. \nBitte die 3 x 4 Werte (zeilenweise) eingeben: \n\n");
    matrixEingabe(matrix2);
    matrixAddition(matrix, matrix2, matrix3);
    printf("\nKontrollasugaben.\n");
    printf("Matrix 1: \n");
    matrixAusgabe(matrix);
    printf("Matrix 2: \n");
    matrixAusgabe(matrix2);
    printf("Matrix 1 + 2: \n");
    matrixAusgabe(matrix3);

    return EXIT_SUCCESS;
}

void matrixEingabe(MATRIX matrix)
{
    for (int i = 0; i < ZEILEN; i++)
    {

        printf("%d. Zeile: ", i + 1);
        scanf("%d %d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2], &matrix[i][3]);
    }
}

void matrixAusgabe(MATRIX matrix)
{
    for (int i = 0; i < ZEILEN; i++)
    {
        for (int j = 0; j < SPALTEN; j++)
        {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAddition(MATRIX matrix1, MATRIX matrix2, MATRIX matrix3)
{
    for (int i = 0; i < ZEILEN; i++)
    {
        for (int j = 0; j < SPALTEN; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}