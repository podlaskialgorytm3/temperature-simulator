#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/temperature.h"

void getRandomTemperatures(temperaturePointer *list, double min, double max, int x, int y)
{
    srand(time(NULL));
    char *letters[] = {"C", "F", "K"};
    int sizeLetters = sizeof(letters) / sizeof(letters[0]);

    for (int i = 1; i < y + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            int randomIndex = rand() % sizeLetters;
            double value = min + (double)rand() / RAND_MAX * (max - min);
            char *unit = letters[randomIndex];
            *list = insert(*list, j, i, value, unit);
        }
    }
}