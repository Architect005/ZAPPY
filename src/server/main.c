/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** create zappy's server
*/

#include "../../include/server.h"

int help(void) {
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
    printf("   port       is the port number\n");
    printf("   width      is the width of the world\n");
    printf("   height     is the height of the world\n");
    printf("   nameX      is the name of the team X\n");
    printf("   clientsNb  is the number of authorized clients per team\n");
    printf("   freq       is the reciprocal of time unit for execution of actions\n");
}

void action(param *pm, int cli_sckt, char **av)
{
    int freq = atoi(av[13]);
    #define f freq

    read(pm->sd, pm->buffer, 1024);
    if (strncasecmp("Forward\n", pm->buffer, 9)) {
        sleep(7/f);
        write(cli_sckt, "ok\n", sizeof("ok\n"));
    }
    if (strncasecmp("Left\n", pm->buffer, 6)) {
        sleep(7/f);
        write(cli_sckt, "ok\n", sizeof("ok\n"));
    }
    if (strncasecmp("Right\n", pm->buffer, 7)) {
        sleep(7/f);
        write(cli_sckt, "ok\n", sizeof("ok\n"));
    }
}

int main(int ac, char **av) {
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        help();
    else if (ac == 14) {
        error(ac, av);
        param *pm = malloc(sizeof(param));
        pm->max_clients = (atoi(av[11])*2);
        pm->opt = TRUE;
        pm->client_socket = malloc(sizeof(int)*(pm->max_clients));
        connect_server(pm, av);
    }
    else
        return (84);
    return (0);
}
