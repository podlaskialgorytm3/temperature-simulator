#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if (list == NULL)
    {
        return NULL;
    }

    temperaturePointer current = list;
    double minimum = current->value;
    char *originalUnit = current->unit;
    int x = current->x;
    int y = current->y;

    while (current != NULL)
    {

        double currentValueInC = 0.0;
        if (strcmp(current->unit, "F") == 0)
        {
            currentValueInC = 5.0 / 9.0 * (current->value - 32);
        }
        else if (strcmp(current->unit, "K") == 0)
        {
            currentValueInC = current->value - 273.15;
        }
        else
        {
            currentValueInC = current->value;
        }

        if (currentValueInC < minimum)
        {
            minimum = currentValueInC;
            originalUnit = current->unit;
            x = current->x;
            y = current->y;
        }

        current = current->next;
    }

    current = list;
    while (current != NULL)
    {
        if (current->x == x && current->y == y)
        {
            minimum = current->value;
            originalUnit = current->unit;
            break;
        }
        current = current->next;
    }

    tempInfoPointer currentInfo = NULL;
    currentInfo = insertTempInfo(currentInfo, minimum, originalUnit);

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