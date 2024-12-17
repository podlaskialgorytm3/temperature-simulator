#include <stdio.h>
#include <stdlib.h>
#include "../include/temperature.h"
#include "../include/generate-structure.h"
#include "../include/io.h"
#include "../include/set-temperature.h"
#include "../include/get-temperature.h"
#include "../include/converting.h"

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
        if (feature == 1)
        {
            int x = atoi(argv[3]);
            int y = atoi(argv[4]);
            double newValue = atoi(argv[5]);
            printf("Mesh with new value!:\n");
            tempList = changeValue(tempList, x, y, newValue);
        }
        else if (feature == 2)
        {
            int row = atoi(argv[3]);
            int newRow = atoi(argv[4]);
            printf("Changed row in mesh!:\n");
            tempList = changeRow(tempList, row, newRow);
        }
        else if (feature == 3)
        {
            int column = atoi(argv[3]);
            int newColumn = atoi(argv[4]);
            printf("Changed column in mesh!:\n");
            tempList = changeColumn(tempList, column, newColumn);
        }
        else if (feature == 4)
        {
            tempInfoPointer currentInfo = NULL;
            currentInfo = getMinimumTemperature(tempList);
            printf("The minimum value: %.2f *%s\n", currentInfo->value, currentInfo->unit);
        }
        else if (feature == 5)
        {
            tempInfoPointer currentInfo = NULL;
            currentInfo = getMaximumTemperature(tempList);
            printf("The maximum value: %.2f *%s\n", currentInfo->value, currentInfo->unit);
        }
        else if (feature == 6)
        {
            char *unit = argv[3];
            tempInfoPointer currentInfo = NULL;
            currentInfo = getAverageTemperature(tempList, unit);
            printf("The minimum value: %.2f *%s\n", currentInfo->value, currentInfo->unit);
        }
        writeToFile("data.txt", tempList);
    }

    printStruct(tempList);

    return 0;
}