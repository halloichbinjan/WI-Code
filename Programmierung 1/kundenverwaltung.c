#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aufgabe 4 - 4

struct Kunde
{
    char Nachname[40];
    char Vorname[30];
    char Strasse[60];
    char Hausnummer[5];
    char PLZ[5];
    char ort[20];
    char festnetz[15];
    char mobil[15];
    char fax[30];
    char email[50];
    char geburtsdatum[11];
    char kundennummer[9];
};

#define MAX_KUNDEN 3

void kundenEingabe(struct Kunde *kunde);
void kundenAusgabe(struct Kunde kunde);
void alleKundenEingabe(int *kunden);
void findeKunde(struct Kunde *kunden, char *nachname);
void kundenListe(struct Kunde *kunden);

int main(void)
{
    struct Kunde kunden[MAX_KUNDEN];
    alleKundenEingabe(kunden);
    kundenListe(kunden);
    return 0;
}

void kundenEingabe(struct Kunde *kunde)
{
    printf("Nachname eingeben:\n");
    scanf(" %s", kunde->Nachname);

    // printf("Vorname eingeben:\n");
    // scanf("%s", kunde->Vorname);

    // printf("Straße eingeben:\n");
    // scanf("%s", kunde->Strasse);

    // printf("Hausnummer eingeben:\n");
    // scanf("%s", kunde->Hausnummer);

    // printf("PLZ eingeben:\n");
    // scanf("%s", kunde->PLZ);

    // printf("Ort eingeben:\n");
    // scanf("%s", kunde->ort);

    // printf("Festnetznummer eingeben:\n");
    // scanf("%s", kunde->festnetz);

    // printf("Handynummer eingeben:\n");
    // scanf("%s", kunde->mobil);

    // printf("Fax eingeben:\n");
    // scanf("%s", kunde->fax);

    // printf("E-Mail eingeben:\n");
    // scanf("%s", kunde->email);

    // printf("Geburtsdatum eingeben:\n");
    // scanf("%s", kunde->geburtsdatum);

    // printf("Kundennummer eingeben:\n");
    // scanf("%s", kunde->kundennummer);
}

void kundenAusgabe(struct Kunde kunde)
{
    printf("%s\n", kunde.Nachname);
    // printf("%s\n", kunde.Vorname);
    // printf("%s\n", kunde.Strasse);
    // printf("%s\n", kunde.Hausnummer);
    // printf("%s\n", kunde.PLZ);
    // printf("%s\n", kunde.ort);
    // printf("%s\n", kunde.festnetz);
    // printf("%s\n", kunde.mobil);
    // printf("%s\n", kunde.fax);
    // printf("%s\n", kunde.email);
    // printf("%s\n", kunde.geburtsdatum);
    // printf("%s\n", kunde.kundennummer);
}

void alleKundenEingabe(int *kunden)
{
    int stop = 0;
    for (int i = 0; i < MAX_KUNDEN; i++)
    {
        if (i > 0)
        {
            printf("Continue? (1/0)\n");
            scanf("%d", &stop);
            if (stop == 0)
            {
                break;
            }
        }
        kundenEingabe(&kunden[i]);
    }
}

void findeKunde(struct Kunde *kunden, char *nachname)
{
    int found = 0;
    for (int i = 0; i < MAX_KUNDEN; i++)
    {
        if (strcmp(kunden[i].Nachname, nachname) == 0)
        {
            kundenAusgabe(kunden[i]);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Kunde nicht gefunden!\n");
    }
}

void kundenListe(struct Kunde *kunden)
{
    for (int i = 0; i < MAX_KUNDEN; i++)
    {
        kundenAusgabe(kunden[i]);
    }
}
