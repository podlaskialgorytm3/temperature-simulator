#include <stdio.h>
#include <stdlib.h>
#include "../include/temperature.h"
#include "../include/io.h"

temperaturePointer changeValue(temperaturePointer list, int x, int y, double newValue)
{
    if (list == NULL)
    {
        exit(1);
    }
    temperaturePointer current = list;
    temperaturePointer previous = NULL;
    while (current != NULL)
    {
        if (current->x == x && current->y == y)
        {
            current->value = newValue;
            return list;
        }

        current = current->next;
    }
    return list;
}