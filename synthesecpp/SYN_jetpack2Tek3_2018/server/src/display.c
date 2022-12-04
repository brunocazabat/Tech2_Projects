/*
** EPITECH PROJECT, 2019
** server
** File description:
** display
*/

# include "../include/server.h"

void display_coin_player2(server_t *server, char *str)
{
    char *save = malloc(sizeof(save));

    check_coin(server);
    server->mapping->map_tab[(int)server->player1->y]
    [(int)server->player1->x] == '_';
    sprintf(save, "%d", server->player1->id);
    strcat(str, save);
    strcat(str, " ");
    sprintf(save, "%d", server->player1->x);
    strcat(str, save);
    strcat(str, " ");
    sprintf(save, "%d", server->player1->y);
    strcat(str, save);
    strcat(str, "\n");
    write(server->fd_client, str, 3);
}

void display_coin_player1(server_t *server, char *str)
{
    char *save = malloc(sizeof(save));

    check_coin(server);
    server->mapping->map_tab[(int)server->player2->y]
    [(int)server->player2->x] == '_';
    sprintf(save, "%d", server->player2->id);
    strcat(str, save);
    strcat(str, " ");
    sprintf(save, "%d", server->player2->x);
    strcat(str, save);
    strcat(str, " ");
    sprintf(save, "%d", server->player2->y);
    strcat(str, save);
    strcat(str, "\n");
    write(server->fd_client, str, 3);
}

void display_wall_player1(server_t *server, char *str)
{
    char *save = malloc(sizeof(server->mapping->map_str));

    check_coin(server);
    sprintf(save, "FINNISH 1\n");
    strcat(str, save);
    strcat(str, "\n");
    write(server->clients[0], str, 10);
    write(server->clients[1], str, 10);
}

void display_wall_player2(server_t *server, char *str)
{
    char *save = malloc(sizeof(server->mapping->map_str));

    check_coin(server);
    sprintf(save, "FINNISH 2\n");
    strcat(str, save);
    strcat(str, "\n");
    write(server->clients[0], str, 10);
    write(server->clients[1], str, 10);
}

void write_player(server_t *server)
{
    char *save = malloc(sizeof(server->mapping->map_str));

    sprintf(save, "PLAYER %d %f %f\n", server->player1->id,
    server->player1->x, server->player1->y);
    write(server->clients[0], save, strlen(save));
    sprintf(save, "PLAYER %d %f %f\n", server->player2->id,
    server->player2->x, server->player2->y);
    write(server->clients[1], save, strlen(save));
}