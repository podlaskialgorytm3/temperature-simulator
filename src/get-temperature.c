#include <stdio.h>
#include <stdlib.h>
#include "../include/temperature.h"

double getMinimumTemperature(temperaturePointer list)
{
    temperaturePointer current = list;
    double minimum = list->value;
    while (current != NULL)
    {
        if (current->value < minimum)
        {
            minimum = current->value;
        }
        current = current->next;
    }
    return minimum;
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