/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** zappy
*/

#include "../../include/server.h"

void map(param *pm, char **av)
{
    int x, y;
    pm->width = atoi(av[4]);
    pm->height = atoi(av[6]);
    srand (time(NULL));

    pm->data = (int**)malloc(pm->width * sizeof(int*));
    for (x = 0; x < pm->width; x++)
        pm->data[x] = (int*)malloc(pm->height * sizeof(int));

    for (x = 0; x < pm->width; x++) {
        for (y = 0; y < pm->height; y++) {
            pm->data[x][y] = (rand() % 7) + 0;
            //printf("%d ", pm->data[x][y]);
        }
        //printf("\n");
    }
}

void free_map(param *pm)
{
    for (int i = 0; i < pm->height; i++)
        free(pm->data[i]);
    free(pm->data);
}
