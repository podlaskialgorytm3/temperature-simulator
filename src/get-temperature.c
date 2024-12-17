#include <stdio.h>
#include <stdlib.h>
#include "../include/get-temperature.h"
#include "../include/temperature.h"
#include "../include/converting.h"

tempInfoPointer insertTempInfo(tempInfoPointer list, double value, char *unit)
{
    tempInfoPointer newTempInfo = (tempInfoPointer)malloc(sizeof(tempInfo));
    if (newTempInfo == NULL)
    {
        exit(1);
    }
    newTempInfo->value = value;
    newTempInfo->unit = unit;
    return newTempInfo;
}

tempInfoPointer getMinimumTemperature(temperaturePointer list)
{
    temperaturePointer current = list;
    covertUnit(&current, "C"); // Konwertujemy wszystkie wartości na jednostkę "C" do porównania
    double minimum = current->value;
    char *originalUnit = current->unit; // Zapamiętujemy oryginalną jednostkę
    int x = current->x;
    int y = current->y;

    while (current != NULL)
    {
        if (current->value < minimum)
        {
            minimum = current->value;
            originalUnit = current->unit; // Aktualizujemy oryginalną jednostkę
            x = current->x;
            y = current->y;
        }
        current = current->next;
    }

    // Znajdź odpowiedni węzeł dla minimum, używając oryginalnej jednostki
    temperaturePointer current2 = list;
    while (current2 != NULL)
    {
        if (x == current2->x && y == current2->y)
        {
            minimum = current2->value;     // Używamy wartości z odpowiedniego węzła
            originalUnit = current2->unit; // Używamy oryginalnej jednostki
            break;
        }
        current2 = current2->next;
    }

    tempInfoPointer currentInfo = NULL;
    currentInfo = insertTempInfo(currentInfo, minimum, originalUnit); // Zwracamy oryginalną jednostkę
    return currentInfo;
}

double getMaximumTemperature(temperaturePointer list)
{
    temperaturePointer current = list;
    double maximum = list->value;
    while (current != NULL)
    {
        if (current->value > maximum)
        {
            maximum = current->value;
        }
        current = current->next;
    }
    return maximum;
}

double getAverageTemperature(temperaturePointer list)
{
    temperaturePointer current = list;
    int size = 0;
    double sum = 0;
    while (current != NULL)
    {
        sum += current->value;
        size++;
        current = current->next;
    }
    double avg = sum / size;
    return avg;
}