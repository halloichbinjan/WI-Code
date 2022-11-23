#include <stdio.h>
#include <stdlib.h>

// Aufgabe 4 - 1
void scanNoten(int *noten, int length);
void printNoten(int noten[], int length);
void statistic(int noten[], int length);
void changeIndex(int *noten, int length);

int main(void)
{
    int noten[5];
    int length = sizeof(noten) / sizeof(noten[0]);

    scanNoten(noten, length);
    changeIndex(noten, length);

    return EXIT_SUCCESS;
}

void scanNoten(int *noten, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Bitte geben Sie die Note für Student %d ein: ", i + 1);
        int note;
        scanf("%d", &note);
        if (note < 0 || note > 5)
        {
            printf("Fehler: Die Note muss zwischen 0 und 5 liegen!\n");
            i--;
        }
        else
        {
            noten[i] = note;
        }
    }
}

void printNoten(int noten[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Note %d: %d\n", i + 1, noten[i]);
    }
}

void statistic(int noten[], int length)
{

    int zeros, ones, twos, threes, fours, fives;
    zeros = ones = twos = threes = fours = fives = 0;
    for (int i = 0; i < length; i++)
    {
        switch (noten[i])
        {

        case 0:
            zeros++;
            break;
        case 1:
            ones++;
            break;
        case 2:
            twos++;
            break;
        case 3:
            threes++;
            break;
        case 4:
            fours++;
            break;
        case 5:
            fives++;
            break;
        }
    }

    float average = (ones * 1 + twos * 2 + threes * 3 + fours * 4 + fives * 5) / (float)(length - zeros);

    printf("\nNicht mitgeschrieben haben: %d\n\n", zeros);
    printf("Anzahl der 1er: %d\n", ones);
    printf("Anzahl der 2er: %d\n", twos);
    printf("Anzahl der 3er: %d\n", threes);
    printf("Anzahl der 4er: %d\n", fours);
    printf("Anzahl der 5er: %d\n\n", fives);
    printf("Durchschnitt: %.2f\n", average);
}

void changeIndex(int *noten, int length)
{
    int index;
    int value;
    printf("Welcher Index soll geändert werden? ");
    scanf("%d", &index);
    // Index muss zwischen 0 und längen des Arrays liegen
    if (index < 0 || index > length)
    {
        printf("Fehler: Der Index muss zwischen 0 und %d liegen!\n", length);
    }
    else
    {
        printf("Welchen Wert soll der Index haben? ");
        scanf("%d", &value);
        if (value < 0 || value > 5)
        {
            printf("Fehler: Die Note muss zwischen 0 und 5 liegen!\n");
        }
        else
        {
            noten[index] = value;
        }
    }
}
