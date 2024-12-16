#ifndef TEMPRATURE_H
#define TEMPRATURE_H

typedef struct temperature
{
    int x;
    int y;
    double value;
    char *unit;
    struct temperature *next;
} temperature, *temperaturePointer;

temperaturePointer insert(temperaturePointer list, int x, int y, double value, char *unit);

void printStruct(temperaturePointer list);

temperaturePointer sortListByCords(temperaturePointer);

#endif