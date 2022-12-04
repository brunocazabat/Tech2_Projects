/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/server.h"

void        handle_read(my_server *s)
{
    for (s->i = 0; s->i < MAX_CLI; s->i++) {
        s->sd = s->client_socket[s->i];
        if (FD_ISSET(s->sd, &s->readfds)) {
            if ((s->read = read(s->sd, s->buffer, 1024)) == 0) {
                getpeername(s->sd, (SOCK *)&s->sin, (SOCKLEN *)&s->sock_size);
                printf("Host disconnected, ip %s, port %d.\n", inet_ntoa(s->sin.sin_addr), ntohs(s->sin.sin_port));
                close(s->sd);
                s->client_socket[s->i] = 0;
            } else {
                s->buffer[s->read] = '\0';
            }
        }
    }
}

void        handle_accept(my_server *s)
{
    if ((s->activ < 0) && (errno != EINTR))
            printf("select error");
    if (FD_ISSET(s->fd, &s->readfds)) {
        if ((s->cli_fd = accept(s->fd, (SOCK *)&s->sin, (SOCKLEN *)&s->sock_size)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New connection, socket fd is %d , ip is : %s , port : %d.\n", s->cli_fd, inet_ntoa(s->sin.sin_addr), ntohs(s->sin.sin_port));
        for (s->i = 0; s->i < MAX_CLI; s->i++) {
            if (s->client_socket[s->i] == 0) {
                s->client_socket[s->i] = s->cli_fd;
                printf("Adding to list of sockets as %d.\n", s->i);
                break;
            }
        }
    }
}

void        handle_select(my_server *s)
{
    FD_ZERO(&s->readfds);
    FD_SET(s->fd, &s->readfds);
    s->max_sd = s->fd;
    for (s->i = 0; s->i < MAX_CLI; s->i++) {
        s->sd = s->client_socket[s->i];
        if (s->sd > 0)
            FD_SET(s->sd, &s->readfds);
        if (s->sd > s->max_sd)
            s->max_sd = s->sd;
    }
    s->activ = select(s->max_sd + 1, &s->readfds, NULL, NULL, &s->tv);
}

void        handle_server(my_server *s)
{
    while (1) {
        handle_select(s);
        handle_accept(s);
        handle_read(s);
        if (s->buffer)
            request_stacker(s, s->buffer);
    }
    close(s->fd);
}