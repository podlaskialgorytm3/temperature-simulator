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
void readFromFile(char *filename, temperaturePointer *list)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Erorr with reading from file: %s \n", filename);
        return;
    }

    double value;
    int x = 1;
    int y = 1;

    int c;

    while (fscanf(file, "%lf", &value) != EOF)
    {
        *list = insert(*list, x, y, value);
        c = fgetc(file);
        if (c == '\n' || c == EOF)
        {
            y++;
            x = 1;
        }
        else
        {
            x++;
        }
    }
    fclose(file);
}