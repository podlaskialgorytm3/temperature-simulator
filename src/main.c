#include <stdio.h>
#include <stdlib.h>
#include "../include/temperature.h"
#include "../include/generate-structure.h"

int main(int argc, char **argv)
{
    temperaturePointer tempList = NULL;

    getRandomTemperatures(&tempList, -10.4, 40.3, 4, 4);

    printStruct(tempList);

    return 0;
}