#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

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
void test();
int teilt(int a, int b);
int summe(int a);
int summe2(int a);
int maximum(int a, int b);
int minimum(int a, int b);
int quersumme(int a);
int istPrimzahl(int a);
void primfaktorzerlegung(int a);
void swap(double *a, double *b);
void umbuchung(int *ptrKontoA, int *ptrKontoB, unsigned int centBetrag);
void printAsciiTable();
void test();
int maxOfArray(int array[], int length);
void primzahlen(int *array, int length);
void primzahlenHelper(int arrayLength);

int main(void)
{
    int i = teilt(1000, 0);
    printf("%d", i);
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

// Aufgabe 3 - 1
/*
    1) a=b++=c++;
    -> Die Syntax dieser Funktion ist falsch, da b++ also b + 1 nicht c++ also c + 1 zugewiesen werden kann.
    -> Man könnte sie folgendermaßen umformen:
    -> a = b++
    -> b = c++
    -> Außerdem müssten alle 3 Variablen deklariert und b und c initialisiert werden.

    2) a+=b++;
    -> Da das ++ hinter dem b steht, wird die 1 (welche durch das ++ ausgedrückt wird) erst addiert, nachdem Rechnung erfolgt.
    -> Somit wird erst a = a + b gesetzt und danach b + 1 gerechnet.
    -> Eine vorherige Deklaration von a und b ist demnach sinnvoll.

    3) a+=--b;
    -> Diese Anweisung entspricht der Anweisung a = a + (b - 1).
    -> Da das -- vor dem b steht wird 1 subtrahiert bevor die Rechnung erfolgt.
    -> Somit wird erst b = b - 1 gerechnet und dann a = a + b gesetzt.

    4) if (++a == b++)
             printf("Ok.\n");
    -> Es wird überprüft, ob a + 1  b entspricht. Erst danach wird b um 1 erhöht.
    -> Ist dies der Fall wird "Ok" ausgegeben.


    5) if (a || b)
             printf("Ok.\n");
    -> Es wird überprüft, ob entweder a oder b einen Wert haben, der nicht 0 ist.
    -> Die Ausgabe erfolgt nur dann nicht, wenn sowohl a als auch b gleich 0 sind.
    -> Eine Deklaration ist somit zwingend, eine Initalisierung sehr sinnvoll, aber nicht zwingend notwendig.
    */

// Aufgabe 3 - 2
int teilt(int a, int b)
{
    // % Zeichen heißt Modulo
    // -> b % a rechnet quasi b geteilt durch a und gibt dann den Rest zurück.
    // Wenn es teilbar ist ist der Rest 0, wenn nicht eben nicht
    if (b % a == 0 && a != 0)
    {
        return 1;
    }

    return 0;
}

// Aufgabe 3 - 3
/*
    Im if steht i=0 und nicht i==0.
    Es wird also i auf 0 gesetzt.
    0 entspricht in C immer false.
    Somit kann nur die else aufgerufen werden.
    Dort kommt es dann zum Fehler der eigentlich mit der if abgefangen werden soll,
    da 1 nicht durch 0 geteilt werden kann.
 */

// Aufgabe 3 - 4.1
// Gaußsche Summerformel btw
int summe(int a)
{
    // int ergebnis = 0;
    // for (int i = 1; i <= a; i++)
    // {
    //     ergebnis = ergebnis + i;
    // }
    // return ergebnis;

    // Einfacher (Gaußsche Summenformel):
    return (a * a + a) / 2;
}

// Aufgabe 3 - 4.2
int summe2(int a)
{
    int ergebnis = 0;
    for (int i = 1; i <= a; i += 2)
    {
        ergebnis = ergebnis + i;
    }
    return ergebnis;
}

// Aufgabe 3 - 4.3.1
int maximum(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// Aufgabe 3 - 4.3.2
int minimum(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

// Aufgabe 3 - 4.4
int maxOfArray(int array[], int length)
{
    int max = array[0];
    for (int i = 1; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

// Aufgabe 3 - 4.5
int quersumme(int a)
{
    if (a <= 0)
    {
        return -1;
    }
    int sum = 0;
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

// Aufgabe 3 - 5
void printAsciiTable()
{
    char hex;
    printf("Es wird der ASCII-Code aufgelistet.\n");
    printf("Wird hexadezimale Darstellung gewuenscht? (j/n)\n");
    scanf("%c", &hex);
    printf(" \n");
    if (hex == 'j')
    {
        printf("Tabelle: Erweiterter 8-Bit-ASCII-Code. Hexadezimale Darstellung.\n");
        for (int i = 0; i < 256; i++)
        {
            if (isprint(i))
                printf(" %c %02x\t", i, i);
            else
                printf("   %02x\t", i);
        }
    }
    else
    {
        printf("Tabelle: Erweiterter 8-Bit-ASCII-Code. Dezimale Darstellung.\n");

        for (int i = 0; i < 256; i++)
            if (isprint(i))
                printf(" %c %03d\t", i, i);
            else
                printf("   %03d\t", i);
    }
}

// Aufgabe 3 - 6
/*
1.
    a != b ? printf("a ist ungleich b") : printf("a ist gleich b");

2.
    a >= b ? max=a : max=b;
*/

// Aufgabe 3 - 7.1
int istPrimzahl(int a)
{
    if (a < 0)
    {
        return -1;
    }
    if (a == 0 || a == 1)
    {
        return 0;
    }
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Aufgabe 3 - 7.2

// Aufgabe 3 - 7.3
void primfaktorzerlegung(int a)
{
    if (a <= 1)
    {
        printf("Bitte eine Zahl größer 1 eingeben.");
        return;
    }
    int i = 2;
    while (a > 1)
    {
        if (a % i == 0)
        {
            printf("%d ", i);
            a /= i;
        }
        else
        {
            i++;
        }
    }
}

// Aufgabe 3 - 8
void primzahlen(int *array, int length)
{
    int primzahlenArray[length];
    int primzahlenLength = 0;
    for (int i = 0; i < length; i++)
    {
        if (istPrimzahl(array[i]))
        {
            primzahlenArray[primzahlenLength] = array[i];
            printf("%d ", primzahlenArray[primzahlenLength]);
            primzahlenLength++;
        }
    }
}

// Gehört zu 3 - 8
// Kann auch in der main gemacht werden.
void primzahlenHelper(int arrayLength)
{
    int array[arrayLength];
    int length = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < length; i++)
    {
        array[i] = i + 1;
    }
    primzahlen(&array, length);
}

// Warm up 4, Aufgabe 2
void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
    printf("a: %f, b: %f", *a, *b);
}

// Warm up 4, Aufgabe 3
void umbuchung(int *ptrKontoA, int *ptrKontoB, unsigned int centBetrag)
{
    if (ptrKontoA != ptrKontoB)
    {
        *ptrKontoA -= centBetrag;
        *ptrKontoB += centBetrag;
    }
    else
    {
        printf("Konten sind gleich!");
    }
    printf("Konto A: %d, Konto B: %d", *ptrKontoA, *ptrKontoB);
}

void test()
{
}
