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
temperaturePointer changeRow(temperaturePointer list, int row, int newRow)
{
    if (list == NULL || row == newRow)
    {
        return list;
    }
    temperaturePointer current = list;
    while (current != NULL)
    {
        if (current->y == row)
        {
            current->y = -1;
        }
        current = current->next;
    }
    current = list;
    while (current != NULL)
    {
        if (current->y == newRow)
        {
            current->y = row;
        }
        current = current->next;
    }
    current = list;
    while (current != NULL)
    {
        if (current->y == -1)
        {
            current->y = newRow;
        }
        current = current->next;
    }
    list = sortListByCords(list);
    return list;
}

temperaturePointer changeColumn(temperaturePointer list, int column, int newColumn)
{
    if (list == NULL || column == newColumn)
    {
        return list;
    }
    temperaturePointer current = list;
    while (current != NULL)
    {
        if (current->x == column)
        {
            current->x = -1;
        }
        current = current->next;
    }
    current = list;
    while (current != NULL)
    {
        if (current->x == newColumn)
        {
            current->x = column;
        }
        current = current->next;
    }
    current = list;
    while (current != NULL)
    {
        if (current->x == -1)
        {
            current->x = newColumn;
        }
        current = current->next;
    }
    list = sortListByCords(list);
    return list;
}