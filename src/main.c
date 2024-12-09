#include <stdio.h>
#include <stdlib.h>
#include "../include/temperature.h"
#include "../include/generate-structure.h"
#include "../include/io.h"

int main(int argc, char **argv)
{
    temperaturePointer tempList = NULL;

    getRandomTemperatures(&tempList, -10.4, 40.3, 10, 15);

    printStruct(tempList);

    writeToFile("data.txt", tempList);

    return 0;
}