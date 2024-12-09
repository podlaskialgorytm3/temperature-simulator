#include <stdlib.h>
#include <stdio.h>
#include "../include/temperature.h"

temperaturePointer insert(temperaturePointer list, int x, int y, double value)
{
    if (list == NULL)
    {
        temperaturePointer newTemperature = (temperaturePointer)malloc(sizeof(temperature));
        if (newTemperature == NULL)
        {
            exit(1);
        }
        newTemperature->x = x;
        newTemperature->y = y;
        newTemperature->value = value;
        newTemperature->next = NULL;
        return newTemperature;
    }
    else
    {
        list->next = insert(list->next, x, y, value);
        return list;
    }
}

void printStruct(temperaturePointer list)
{
    while (list != NULL)
    {
        printf("[%d,%d] = %.2f\n", list->x, list->y, list->value);
        list = list->next;
    }
}