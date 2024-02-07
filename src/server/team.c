/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** zappy
*/

#include "../../include/server.h"
#define size 2

void team(param *pm, char **av)
{
    int y = 0, st = 8;

    pm->team = (char **)malloc(1*sizeof(char*));
    for(int x = 0; x < size; x++) {
        pm->team[x] = (char *)malloc(size*sizeof(char));
    }
    for(; y < size; y++) {
        pm->team[y] = av[st];
        //printf("%s\n", pm->team[y]);
        st+=1;
    }
}

void free_team(param *pm)
{
    free(pm->team);
}
