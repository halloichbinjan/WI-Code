#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// Aufgabe 4 - 3

#define LAENGE 80
struct Kundendaten
{
    char KdNr[10];         /* Kundennummer */
    char Nachname[LAENGE]; /* Name         */
    char Vorname[LAENGE];
    float kto; /* Kontostand   */
} kunde1, kunde2;

void scanData(struct Kundendaten *kunde);
void printData(struct Kundendaten kunde);

int main(void)
{
    printf("Kunde 1:\n");
    scanData(&kunde1);
    printf("Kunde 2:\n");
    scanData(&kunde2);
    printData(kunde1);
    printData(kunde2);
}

void scanData(struct Kundendaten *kunde)
{
    printf("Bitte geben Sie die Kundennummer ein: ");
    scanf("%s", kunde->KdNr);
    printf("Bitte geben Sie den Nachnamen ein: ");
    scanf("%s", kunde->Nachname);
    printf("Bitte geben Sie den Vornamen ein: ");
    scanf("%s", kunde->Vorname);
    printf("Bitte geben Sie den Kontostand ein: ");
    scanf("%f", &kunde->kto);
}

void printData(struct Kundendaten kunde)
{
    printf("Kundennummer: %s \n", kunde.KdNr);
    printf("Nachname: %s \n", kunde.Nachname);
    printf("Vorname: %s \n", kunde.Vorname);
    printf("Kontostand: %f \n\n", kunde.kto);
}