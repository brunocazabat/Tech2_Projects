/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/server.h"

void	protocol_id(server_t *server)
{
    if (server->player1->id == 0) {
        server->player1->id = 1;
        write(server->sd, "ID 1\n", 5);
    }
    else if (server->player2->id == 0) {
        server->player2->id = 2;
        write(server->sd, "ID 2\n", 5);
    }
}

char *my_strcat_str(char *str, char *save, server_t *server)
{
    strcat(str, "MAP ");
    gcvt(server->mapping->width, 10, save);
    strcat(str, save);
    strcat(str, " ");
    gcvt(server->mapping->height, 10, save);
    strcat(str, save);
    strcat(str, " ");
}

void	protocol_map(server_t *server)
{
    char *str = malloc(sizeof(server->mapping->map_str) + 10);
    char *save = malloc(sizeof(server->mapping->map_str));
    int i = 0, c = 0;

    memset(str, 0, sizeof(server->mapping->map_str) + 10);
    my_strcat_str(str, save, server);
    while (server->mapping->map_str[i] != '\0') {
        if (server->mapping->map_str[i] != '\n') {
            save[c] = server->mapping->map_str[i];
            c++;
        }
        i++;
    }
    strcat(str, save);
    strcat(str, "\n");
    write(server->sd, str, strlen(str));
}

void	protocol_ready(server_t *server)
{
    server->ready++;
}

void    protocol_fire(server_t *server)
{
    server = server;
    printf("A PLAYER USED HIS JETPACK\n");
}
