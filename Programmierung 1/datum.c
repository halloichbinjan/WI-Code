#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aufgabe 5-2
int *getTag(char datum[], char tag[]);

int main(void)
{
    char datum[11];
    puts("Datum eingeben: ");
    fgets(datum, 11, stdin);
    char tag[] = {datum[0], datum[1]};

    printf("Tag: %s", getTag(datum, tag));

    return 0;
}

int *getTag(char datum[], char tag[])
{
    int *ptr = tag;
    return ptr;
}