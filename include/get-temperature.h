#ifndef GET_TEMPERATURE_
#define GET_TEMPERATURE_
#include "temperature.h"

typedef struct tempInfo
{
    double value;
    char *unit;
    struct tempInfo *next;
} tempInfo, *tempInfoPointer;

tempInfoPointer insertTempInfo(tempInfoPointer list, double value, char *unit);

tempInfoPointer getMinimumTemperature(temperaturePointer list);

double getMaximumTemperature(temperaturePointer list);

double getAverageTemperature(temperaturePointer list);

#endif