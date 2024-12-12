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
        printf("%8.2f *C", list->value);
        if (list->next != NULL && list->x > list->next->x)
        {
            printf("\n");
        }
        list = list->next;
    }
    printf("\n");
}

temperaturePointer sortListByCords(temperaturePointer list)
{
    if (list == NULL || list->next == NULL)
    {
        return list;
    }
    temperaturePointer sorted = NULL;

    while (list != NULL)
    {
        temperaturePointer current = list;
        list = list->next;
        if (sorted == NULL || current->y < sorted->y || (current->y == sorted->y && current->x < sorted->x))
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            temperaturePointer temp = sorted;
            while (temp->next != NULL && (temp->next->y < current->y || (temp->next->y == current->y && temp->next->x < current->x)))
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    return sorted;
}