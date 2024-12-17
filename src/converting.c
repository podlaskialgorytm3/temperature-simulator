#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/temperature.h"

void covertUnit(temperaturePointer *list, char *targetUnit)
{
    temperaturePointer newList = *list;
    if (strcmp(targetUnit, "C") == 0)
    {
        while (newList != NULL)
        {
            if (strcmp(newList->unit, "F") == 0)
            {
                newList->value = 5.0 / 9.0 * (newList->value - 32);
            }
            else if (strcmp(newList->unit, "K") == 0)
            {
                newList->value = newList->value - 273.15;
            }
            newList->unit = targetUnit;
            newList = newList->next;
        }
    }
    else if (strcmp(targetUnit, "K") == 0)
    {
        while (newList != NULL)
        {
            if (strcmp(newList->unit, "F") == 0)
            {
                newList->value = 5.0 / 9.0 * (newList->value - 32) + 273.15;
            }
            else if (strcmp(newList->unit, "C") == 0)
            {
                newList->value = newList->value + 273.15;
            }
            newList->unit = targetUnit;
            newList = newList->next;
        }
    }
    else if (strcmp(targetUnit, "F") == 0)
    {
        while (newList != NULL)
        {
            if (strcmp(newList->unit, "K") == 0)
            {
                newList->value = 9.0 / 5.0 * (newList->value - 273.15) + 32;
            }
            else if (strcmp(newList->unit, "C") == 0)
            {
                newList->value = 9.0 / 5.0 * newList->value + 32;
            }
            newList->unit = targetUnit;
            newList = newList->next;
        }
    }
}