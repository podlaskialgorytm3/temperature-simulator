#include <stdio.h>
#include <stdlib.h>
#include "../include/temperature.h"

void writeToFile(char *filename, temperaturePointer list)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error with writing to file: %s\n", filename);
        return;
    }

    while (list != NULL)
    {
        fprintf(file, "%8.2f", list->value);
        if (list->next != NULL && list->x > list->next->x)
        {
            fprintf(file, "\n");
        }
        list = list->next;
    }
    fprintf(file, "\n");
    fclose(file);
}