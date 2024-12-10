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
        fprintf(file, "%8.2f %d %d \n", list->value, list->x, list->y);
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

    int c;

    while (fscanf(file, "%lf %d %d \n", &value, &x, &y) != EOF)
    {
        *list = insert(*list, x, y, value);
    }
    fclose(file);
}