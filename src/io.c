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
        fprintf(file, "%8.2f %d %d %s\n", list->value, list->x, list->y, list->unit);
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
    int x;
    int y;
    char unit[3];

    int c;

    while (fscanf(file, "%lf %d %d %2s\n", &value, &x, &y, unit) != EOF)
    {
        *list = insert(*list, x, y, value, unit);
    }
    fclose(file);
}