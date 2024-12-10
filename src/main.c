#include <stdio.h>
#include <stdlib.h>
#include "../include/temperature.h"
#include "../include/generate-structure.h"
#include "../include/io.h"
#include "../include/set-temperature.h"

int main(int argc, char **argv)
{
    temperaturePointer tempList = NULL;
    int mode = atoi(argv[1]);

    if (mode == 0)
    {
        double min = atof(argv[2]);
        double max = atof(argv[3]);
        int x = atoi(argv[4]);
        int y = atoi(argv[5]);
        getRandomTemperatures(&tempList, min, max, x, y);
        writeToFile("data.txt", tempList);
    }
    if (mode == 1)
    {
        readFromFile("data.txt", &tempList);
        int feature = atoi(argv[2]);
        if (feature == 2)
        {
            int x = atoi(argv[3]);
            int y = atoi(argv[4]);
            double newValue = atoi(argv[5]);
            printf("Mesh with new value!:\n");
            tempList = changeValue(tempList, x, y, newValue);
        }
        writeToFile("data.txt", tempList);
    }

    printStruct(tempList);

    return 0;
}