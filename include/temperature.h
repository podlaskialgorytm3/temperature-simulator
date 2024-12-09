#ifndef TEMPRATURE_H
#define TEMPRATURE_H

typedef struct temperature
{
    int x;
    int y;
    double value;
    struct temperature *next;
} temperature, *temperaturePointer;

temperaturePointer insert(temperaturePointer list, int x, int y, double value);

void printStruct(temperaturePointer list);

#endif