/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** zappy
*/

#include "../../include/server.h"

bool check_number(char *av)
{
    for (int x = 0; x < strlen(av); x++) {
        if (av[x] >= '0' & av[x] <= '9')
            return (true);
        else
            return (false);
    }
}

int error(int ac, char **av)
{
    int chk, x;
    for (x = 0; x < ac; x++) {
        if (strcmp(av[x], "-p") == 0)
            chk+=1;
        if (strcmp(av[x], "-x") == 0)
            chk+=1;
        if (strcmp(av[x], "-y") == 0)
            chk+=1;
        if (strcmp(av[x], "-n") == 0)
            chk+=1;
        if (strcmp(av[x], "-c") == 0)
            chk+=1;
        if (strcmp(av[x], "-f") == 0)
            chk+=1;
    }
    if (chk != 6) {
        printf("Wrong option\nEnter -help for help\n");
        exit (84);
    }
    if (atoi(av[4]) < 10 || atoi(av[4]) > 30) {
        printf("Width should be between 10 and 30\n");
        exit (84);
    }
    if (atoi(av[6]) < 10 || atoi(av[6]) > 30) {
        printf("Height should be between 10 and 30\n");
        exit (84);
    }
    if (atoi(av[13]) < 2 || atoi(av[13]) > 10000) {
        printf("f should be between 2 and 10000\n");
        exit (84);
    }
    err_num(av);
    return (0);
}

int err_num(char **av)
{
    if (!check_number(av[2])) {
        printf("Enter -help for help\n");
        exit (84);
    }
    if (!check_number(av[4])) {
        printf("Enter -help for help\n");
        exit (84);
    }
    if (!check_number(av[6])) {
        printf("Enter -help for help\n");
        exit (84);
    }
    if (!check_number(av[11])) {
        printf("Enter -help for help\n");
        exit (84);
    }
    if (!check_number(av[13])) {
        printf("Enter -help for help\n");
        exit (84);
    }
    return (0);
}
