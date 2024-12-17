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

tempInfoPointer getMaximumTemperature(temperaturePointer list)
{
    if (list == NULL)
    {
        return NULL;
    }

    temperaturePointer current = list;
    double maximum = current->value;
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

        if (currentValueInC > maximum)
        {
            maximum = currentValueInC;
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
            maximum = current->value;
            originalUnit = current->unit;
            break;
        }
        current = current->next;
    }

    tempInfoPointer currentInfo = NULL;
    currentInfo = insertTempInfo(currentInfo, maximum, originalUnit);

    return currentInfo;
}

tempInfoPointer getAverageTemperature(temperaturePointer list, char *unit)
{
    if (list == NULL || unit == NULL)
    {
        return NULL;
    }

    temperaturePointer current = list;
    int count = 0;
    double sum = 0;

    while (current != NULL)
    {
        double valueInTargetUnit = 0.0;

        if (strcmp(unit, "C") == 0)
        {
            if (strcmp(current->unit, "F") == 0)
            {
                valueInTargetUnit = 5.0 / 9.0 * (current->value - 32);
            }
            else if (strcmp(current->unit, "K") == 0)
            {
                valueInTargetUnit = current->value - 273.15;
            }
            else
            {
                valueInTargetUnit = current->value;
            }
        }
        else if (strcmp(unit, "F") == 0)
        {
            if (strcmp(current->unit, "C") == 0)
            {
                valueInTargetUnit = 9.0 / 5.0 * current->value + 32;
            }
            else if (strcmp(current->unit, "K") == 0)
            {
                valueInTargetUnit = 9.0 / 5.0 * (current->value - 273.15) + 32;
            }
            else
            {
                valueInTargetUnit = current->value;
            }
        }
        else if (strcmp(unit, "K") == 0)
        {
            if (strcmp(current->unit, "C") == 0)
            {
                valueInTargetUnit = current->value + 273.15;
            }
            else if (strcmp(current->unit, "F") == 0)
            {
                valueInTargetUnit = 5.0 / 9.0 * (current->value - 32) + 273.15;
            }
            else
            {
                valueInTargetUnit = current->value;
            }
        }
        else
        {
            return NULL;
        }

        sum += valueInTargetUnit;
        count++;
        current = current->next;
    }

    if (count == 0)
    {
        return NULL;
    }

    double avg = sum / count;

    tempInfoPointer avgInfo = NULL;
    avgInfo = insertTempInfo(avgInfo, avg, unit);

    return avgInfo;
}
