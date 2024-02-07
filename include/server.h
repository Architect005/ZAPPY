/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** game online
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define MAX 1024
#define SOCK struct sockaddr

typedef struct param
{
    struct sockaddr_in address;
    fd_set readfds;
    int port;
    int width;
    int height;
    int freq;
    int max_clients;
    int opt;
    int master_socket, addrlen, new_socket, activity, i, valread, sd;
    int max_sd;
    int *client_socket;
    int **data;
    char **team;
    char *buffer;
    char *message;
}param;

int error(int, char **);
int err_num(char **);
bool check_number(char *);
void action(param *, int, char **);
void client(param *);
void connected(param *, char **);
void protocol(param *, char **);
void func(param *, char **);
void connect_server(param *, char **);
void server(param *);
void check(param *, char **);
void map(param *, char **);
void free_map(param *);
void team(param *, char **);
void free_team(param *);

#endif
