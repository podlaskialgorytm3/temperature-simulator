#ifndef IO_
#define IO_
#include "temperature.h"

void writeToFile(char *filename, temperaturePointer list);
void readFromFile(char *filename, temperaturePointer *list);

#endif