#ifndef SET_TEMPERATURE_
#define SET_TEMPERATURE_
#include "../include/temperature.h"

temperaturePointer changeValue(temperaturePointer list, int x, int y, double newValue);
temperaturePointer changeRow(temperaturePointer list, int row, int newRow);

#endif