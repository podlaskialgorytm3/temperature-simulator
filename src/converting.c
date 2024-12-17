#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/temperature.h"

temperaturePointer covertUnit(temperaturePointer list, char *targetUnit)
{
    temperaturePointer current = list; // Wskaźnik na aktualny element listy
    while (current != NULL)
    {
        if (strcmp(targetUnit, "C") == 0)
        {
            if (strcmp(current->unit, "F") == 0)
            {
                current->value = 5.0 / 9.0 * (current->value - 32);
            }
            else if (strcmp(current->unit, "K") == 0)
            {
                current->value = current->value - 273.15;
            }
        }
        else if (strcmp(targetUnit, "K") == 0)
        {
            if (strcmp(current->unit, "F") == 0)
            {
                current->value = 5.0 / 9.0 * (current->value - 32) + 273.15;
            }
            else if (strcmp(current->unit, "C") == 0)
            {
                current->value = current->value + 273.15;
            }
        }
        else if (strcmp(targetUnit, "F") == 0)
        {
            if (strcmp(current->unit, "K") == 0)
            {
                current->value = 9.0 / 5.0 * (current->value - 273.15) + 32;
            }
            else if (strcmp(current->unit, "C") == 0)
            {
                current->value = 9.0 / 5.0 * current->value + 32;
            }
        }
        current->unit = targetUnit; // Zaktualizuj jednostkę
        current = current->next;    // Przejdź do następnego elementu
    }
    return list; // Zwróć wskaźnik na początek listy
}
