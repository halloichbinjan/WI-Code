#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sizes();
void calculator();
void functs();
void euro();
void calc2();
int cEquals(char first, char second);
void kuerzenScanner();
int kuerzen(int zaehler, int nenner);
void arethMittel();
void arethMittel2();
float kapitalwert(float startkapital, int jahre, float zinssatz);

int main(void)
{
    float f = kapitalwert(1400, 8, 0.02);
    printf("Das Kapital nach beträgt %.2f€", f);
    return EXIT_SUCCESS;
}

// Aufgabe 1-3
void sizes()
{
    int charMemory = sizeof(char);
    int intMemory = sizeof(int);
    int floatMemory = sizeof(float);
    int longMemory = sizeof(long);
    int doubleMemory = sizeof(double);

    printf("Speicherbedarf char: %d \n", charMemory);
    printf("Speicherbedarf int: %d\n", intMemory);
    printf("Speicherbedarf float: %d\n", floatMemory);
    printf("Speicherbedarf long: %d\n", longMemory);
    printf("Speicherbedarf double: %d\n", doubleMemory);
}

// Aufgabe 1-4
void calculator()
{
    float operand1, operand2;
    char operator;
    float ergebnis;

    printf("Bitte Rechenausdruck eingeben in der Form Operand Operator Operand.");
    scanf("%f %c %f", &operand1, &operator, & operand2);

    if (operator== '+')
    {
        ergebnis = operand1 + operand2;
        printf("Kontrolle: %f %c %f", operand1, operator, operand2);
        printf("Ergebnis: %f", ergebnis);
    }
    else if (operator== '-')
    {
        ergebnis = operand1 - operand2;
        printf("Ergebnis: %f", ergebnis);
    }
    else if (operator== '*')
    {
        ergebnis = operand1 * operand2;
        printf("Ergebnis: %f", ergebnis);
    }
    else if (operator== '/')
    {
        ergebnis = operand1 / operand2;
        printf("Ergebnis: %f", ergebnis);
    }
    else
    {
        printf("Ungültiger Operator ungültige Operant");
    }
}

// Aufgabe 2-1
void functs()

{
    double value = 0;
    double sinus, squareRoots;

    printf("\nAuf zwei Nachkommastellen gerundet\n");
    printf("%7s %10s %9s \n", "x", "sin(x)", "sqrt(x)");
    while (value <= 1.05) //?????? Warum nicht 1
    {
        printf("%8.2lf %8.2lf %8.2lf\n", value, sin(value), sqrt(value));
        value += 0.05;
    }
}

// Aufgabe 2-2
void euro()
{
    float betrag;
    float wechselkurs = 0.9759;
    char direction;

    printf("EUR zu CHF (E) oder CHF zu EUR (C) \n");
    scanf("%c", &direction);

    if (direction == 'E')
    {
        printf("Euro Betrag eingeben: \n");
        scanf("%f", &betrag);
        printf("Mit dem aktuellen Wechselkurs von %.4f sind %.2f€ genau %.2fCHF wert.", wechselkurs, betrag, betrag * wechselkurs);
    }
    else if (
        direction == 'C')
    {
        printf("CHF Betrag eingeben: \n");
        scanf("%f", &betrag);
        printf("Mit dem aktuellen Wechselkurs von %.4f sind %.2fCHF genau %.2f€ wert.", wechselkurs, betrag, betrag / wechselkurs);
    }
    else
    {
        printf("Eingabe ungültig!");
    }
}

// Aufgabe 2-3
void calc2()
{
    int i = 1;
    while (i != 0)
    {

        double operand1, operand2;
        char operator;
        double ergebnis;
        char answer;

        printf("Bitte Rechenausdruck eingeben in der Form Operand Operator Operand.\n");
        scanf("%lf %c %lf", &operand1, &operator, & operand2);

        if (operator== '+')
        {
            ergebnis = operand1 + operand2;
            printf("Ergebnis: %.4lf\n", ergebnis);
        }
        else if (operator== '-')
        {
            ergebnis = operand1 - operand2;
            printf("Ergebnis: %.4lf\n", ergebnis);
        }
        else if (operator== '*')
        {
            ergebnis = operand1 * operand2;
            printf("Ergebnis: %.4lf\n", ergebnis);
        }
        else if (operator== '/')
        {
            ergebnis = operand1 / operand2;
            printf("Ergebnis: %.4lf\n", ergebnis);
        }
        else if (operator== '#')
        {
            ergebnis = pow(operand1, operand2);
            printf("Ergebnis: %.0lf\n", ergebnis);
        }
        else
        {
            printf("Ungültiger Operator ungültige Operant\n");
        }

        printf("Weiter? (j/n)\n");
        scanf(" %c", &answer);
        if (answer == 'n')
        {
            i = 0;
        }
        else
        {
            printf("----------------\n");
        }
    }
}

// Aufgabe 2-4
int cEquals(char first, char second)
{
    if (first == second)
    {
        // printf("1");
        return 1;
    }
    else
    {
        // printf("0");
        return 0;
    }
}

// Aufgabe 2-5
// Eingabe zum Kürzen verarbeiten
void kuerzenScanner()
{
    int zaehler;
    int nenner;
    printf("Bitte Zähler eingeben: \n");
    scanf(" %d", &zaehler);
    printf("Bitte Nenner eingeben: \n");
    scanf(" %d", &nenner);

    kuerzen(zaehler, nenner);
}

// Aufgabe 2-5
int kuerzen(int zaehler, int nenner)
{
    int baseZahler = zaehler;
    int baseNenner = nenner;
    int kuerzWert;
    int gekZaehler;
    int gekNenner;
    int anzVorzeichen = 0;

    // Vorzeichen überprüfen und anpassen
    if ((zaehler < 0 && nenner > 0))
    {
        anzVorzeichen = 1;
        baseZahler = baseZahler * (-1);
        zaehler = zaehler * (-1);
        printf("A");
    }
    else if ((nenner < 0 && zaehler > 0))
    {
        anzVorzeichen = 1;
        baseNenner = baseNenner * (-1);
        nenner = nenner * (-1);
        printf("Nenner: %d\n", nenner);
        printf("B");
    }
    else if (zaehler < 0 && nenner < 0)
    {
        anzVorzeichen = 2;
        baseZahler = baseZahler * (-1);
        baseNenner = baseNenner * (-1);
        zaehler = zaehler * (-1);
        nenner = nenner * (-1);
        printf("C");
    }

    // Gemeinsamen Kürzwert berechnen
    if (zaehler != nenner)
    {
        while (zaehler != nenner)
        {

            if (zaehler > nenner)
            {
                zaehler = zaehler - nenner;
            }
            else
            {
                nenner = nenner - zaehler;
            }
        }
        kuerzWert = nenner;
    }
    else
    {
        kuerzWert = zaehler;
    }

    // Zahler und Nenner mit gem. Kürzwert kürzen
    gekZaehler = baseZahler / kuerzWert;
    gekNenner = baseNenner / kuerzWert;

    // Vorzeichen wenn nötig anpassen
    if (anzVorzeichen == 1)
    {
        gekZaehler = gekZaehler * (-1);
    }

    // Ausgabe
    printf("\n\n%d\n", gekZaehler);
    printf("--\n");
    printf("%d\n", gekNenner);

    return 1;
}

// Warm up 2
void arethMittel()
{
    int value = 0;
    int current;
    int howMuch;
    double howMuchDouble;
    double aM;

    printf("Wie viele Werte wollen sie? (Maximal 10) \n");
    scanf("%d", &howMuch);
    if (howMuch <= 10 && howMuch > 0)
    {

        printf("Bitte %d Werte eingeben \n", howMuch);

        for (int i = 0; i < howMuch; i++)
        {
            printf("Wert %d?\n", i + 1);
            scanf("%d", &current);
            value = value + current;
        }
        howMuchDouble = howMuch;
        aM = value / howMuchDouble;

        printf("\nArithmetisches Mittel: %lf", aM);
    }
    else
    {
        printf("Bitte maximal 10 und minimal einen Wert");
    }
}

// Warm up 2 - weitere Möglichkeit    
void arethMittel2()

{
    double anzahl;
    double sum = 0;

    printf("Bitte maximal 10 Werte eingeben. Wenn sie die gewünschte Anzahl erreicht haben geben sie -1 ein.\n");
    for (int i = 0; i < 10; i++)
    {

        int cur;
        printf("Wert %d?    ", i + 1);
        scanf("%d", &cur);
        if (cur == -1)
        {
            break;
        }
        else
        {
            if (cur >= 0)
            {
                sum += cur;
            }
            else
            {
                printf("Bitte minimal 0 als Wert verwenden");
                break;
            }
        }
        anzahl++;
    }
    if (anzahl > 1)
    {
        printf("Arithmetisches Mittel: %lf", sum / anzahl);
    }
    else
    {
        printf("Bitte mehr als einen Wert eingeben.");
    }
}

// Warmp up 3 - Aufgabe 3
float kapitalwert(float startkapital, int jahre, float zinssatz)
{
    float ergebnis = startkapital;
    for (int i = 1; i <= jahre; i++)
    {
        ergebnis = ergebnis + (ergebnis * zinssatz);
    }

    return ergebnis;
}