/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** server game
*/

#include "../../include/server.h"

void check(param *pm, char **av)
{
    if (bind(pm->master_socket, (struct sockaddr *)&pm->address, sizeof(pm->address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", atoi(av[2]));
    if (listen(pm->master_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    pm->addrlen = sizeof(pm->address);
    puts("Waiting for connections ...");
}

void client(param *pm)
{
    if (FD_ISSET(pm->master_socket, &pm->readfds))
    {
        if ((pm->new_socket = accept(pm->master_socket, (struct sockaddr *)&pm->address, (socklen_t*)&pm->addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New connection , socket fd is %d , ip is : %s , port : %f\n" , pm->new_socket , inet_ntoa(pm->address.sin_addr) , ntohs
                (pm->address.sin_port));

        if(send(pm->new_socket, pm->message, strlen(pm->message), 0) != strlen(pm->message))  
        {
            perror("send");
        }
        puts("Welcome message sent successfully");
        for (pm->i = 0; pm->i < pm->max_clients; pm->i++)
        {
            if(pm->client_socket[pm->i] == 0)
            {
                pm->client_socket[pm->i] = pm->new_socket;
                printf("Adding to list of sockets as %d\n" , pm->i);
                break;
            }
        }
    }
}

void connected(param *pm, char **av)
{
    for (pm->i = 0; pm->i < pm->max_clients; pm->i++)
    {
        pm->sd = pm->client_socket[pm->i];

        if (FD_ISSET(pm->sd , &pm->readfds))
        {
            if ((pm->valread = read(pm->sd, pm->buffer, 1024)) == 0)
            {
                getpeername(pm->sd, (SOCK*)&pm->address , (socklen_t*)&pm->addrlen);
                printf("Host disconnected , ip %s , port %d \n", inet_ntoa(pm->address.sin_addr) , ntohs(pm->address.sin_port));  
                close(pm->sd);
                pm->client_socket[pm->i] = 0;
            }
            else
            {
                pm->buffer[pm->valread] = '\0';
                send(pm->sd , pm->buffer , strlen(pm->buffer) , 0 );
            }
        }
    }
}

void protocol(param *pm, char **av)
{
    while(TRUE)
    {
        FD_ZERO(&pm->readfds);
        FD_SET(pm->master_socket, &pm->readfds);
        pm->max_sd = pm->master_socket;
        for (pm->i = 0; pm->i < pm->max_clients; pm->i++)
        {
            pm->client_socket[pm->i] = 0;
            pm->sd = pm->client_socket[pm->i];
            if(pm->sd > 0)
                FD_SET(pm->sd, &pm->readfds);
            if(pm->sd > pm->max_sd)
                pm->max_sd = pm->sd;
        }

        pm->activity = select(pm->max_sd+1, &pm->readfds, NULL, NULL, NULL);

        if ((pm->activity < 0) && (errno!=EINTR))
        {
            printf("select error");
        }

        client(pm);
        
        connected(pm, av);

        action(pm, pm->client_socket[pm->i], av);
    }
}

void connect_server(param *pm, char **av)
{
    pm->buffer[MAX];
    pm->message = "ZAPPY server connected";

    for (pm->i = 0; pm->i < pm->max_clients; pm->i++)
    {
        pm->client_socket[pm->i] = 0;
    }
    if((pm->master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(pm->master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&pm->opt, sizeof(pm->opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    pm->address.sin_family = AF_INET;
    pm->address.sin_addr.s_addr = INADDR_ANY;
    pm->address.sin_port = htons(atoi(av[2]));

    check(pm, av);

    protocol(pm, av);
}
