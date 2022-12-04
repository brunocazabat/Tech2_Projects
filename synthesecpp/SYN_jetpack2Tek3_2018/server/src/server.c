/*
** EPITECH PROJECT, 2019
** SYN_jetpack2Tek3_2018
** File description:
** server
*/


# include "../include/server.h"

void init_socket(server_t *server)
{
    int opt = 1;

    if ((server->fd_server = socket(AF_INET , SOCK_STREAM , 0)) == 0)
        exit(84);
    if (setsockopt(server->fd_server, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
    sizeof(opt)) < 0)
        exit(84);
    server->socket.sin_family = AF_INET;
    server->socket.sin_addr.s_addr = INADDR_ANY;
    server->socket.sin_port = htons(server->pid);
    if (bind(server->fd_server, (struct sockaddr *)&server->socket,
    sizeof(server->socket)) < 0) {
        perror("bind failed");
        exit(84);
    }
    if (listen(server->fd_server, 3) < 0) {
        perror("listen");
        exit(84);
    }
}

void add_socket(server_t *server)
{
    int activity;

    for (server->i = 0 ; server->i < 30 ; server->i++) {
        server->sd = server->clients[server->i];
        if (server->sd > 0)
            FD_SET(server->sd , &server->active_fd_set);
        if (server->sd > server->msd)
            server->msd = server->sd;
    }
    activity = select(server->msd + 1 ,
    &server->active_fd_set , NULL , NULL , NULL);
    if (activity < 0)
    {
        printf("select error");
        exit (84);
    }
}

void do_actions(server_t *server)
{
    int ret;
    int size;

    size = sizeof(server->client);
    server->sd = server->clients[server->i];
    if (server->ready >= 2)
        move_player(server);
    if (FD_ISSET(server->sd , &server->active_fd_set)) {
        if ((ret = read(server->sd , server->buffer, 1024)) == 0) {
            getpeername(server->sd , (struct sockaddr *)&server->client,
            (socklen_t *)&size);
            close(server->sd);
            server->clients[server->i] = 0;
        }
        else {
            server->buffer[ret] = '\0';
            check_protocol(server->buffer, server);
        }
    }
}

void in_com(server_t *server)
{
    int size;

    size = sizeof(server->client);
    if (FD_ISSET(server->fd_server, &server->active_fd_set)) {
        if ((server->fd_client = accept(server->fd_server,
        (struct sockaddr *)&server->client, (socklen_t *)&size))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        for (server->i = 0; server->i < 30; server->i++) {
            if (server->clients[server->i] == 0 ) {
                server->clients[server->i] = server->fd_client;
                break;
            }
        }
    }
    for (server->i = 0; server->i < 30; server->i++)
        do_actions(server);
}

int server_accept(server_t *server)
{
    init_socket(server);
    for (server->i = 0; server->i < 30; server->i++)
        server->clients[server->i] = 0;
    while (1) {
        FD_ZERO(&server->active_fd_set);
        FD_SET(server->fd_server, &server->active_fd_set);
        server->msd = server->fd_server;
        add_socket(server);
        in_com(server);
    }
    return 0;
}
