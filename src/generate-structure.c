#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/temperature.h"

void getRandomTemperatures(temperaturePointer *list, double min, double max, int x, int y)
{
    srand(time(NULL));

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            double value = min + (double)rand() / RAND_MAX * (max - min);
            *list = insert(*list, i, j, value);
        }
    }
}