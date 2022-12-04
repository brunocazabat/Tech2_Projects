/*
** EPITECH PROJECT, 2019
** Synthesis pool - JetPackTek3
** File description:
** movement
*/

#include "../include/server.h"

void move_player_y(server_t *server)
{
    int fire_status = 1;

    if (server->player1->fire == 0)
        fire_status = -1;
    server->player1->y += (server->g * fire_status * 5) / 100;
    if (server->player2->fire == 0)
        fire_status = -1;
    else
        fire_status = 1;
    server->player2->y += (server->g * fire_status * 5) / 100;
    if (server->player1->y < 0)
        server->player1->y = 0;
    if (server->player2->y < 0)
        server->player2->y = 0;
}

void check_coin(server_t *server)
{
    char *str = malloc(sizeof(server->mapping->map_str));

    strcat(str, "COIN ");
    if (server->mapping->map_tab[(int)server->player1->y]
    [(int)server->player1->x] == 'c')
        display_coin_player1(server, str);
    if (server->mapping->map_tab[(int)server->player2->y]
    [(int)server->player2->x] == 'c')
        display_coin_player2(server, str);
}

void check_end_end(server_t *server)
{
    char *str = malloc(sizeof(server->mapping->map_str));
    char *save = malloc(sizeof(save));

    strcat(str, "FINISH ");
    if (server->player1->x >= server->mapping->width && server->player1->x >=
    server->mapping->width) {
        if (server->player1->score >= server->player2->score)
            write(server->sd, "FINISH 1\n", 9);
        else if (server->player1->score < server->player2->score)
            write(server->sd, "FINISH 2\n", 9);
        else
            write(server->sd, "FINISH -1\n", 10);
        exit(0);
    }
}

void check_end(server_t *server)
{
    char *str = malloc(sizeof(server->mapping->map_str));

    if (server->mapping->map_tab[(int)server->player1->y]
    [(int)server->player1->x] == 'e') {
        display_wall_player1(server, str);
        exit(0);
    }
    if (server->mapping->map_tab[(int)server->player2->y]
    [(int)server->player2->x] == 'e') {
        display_wall_player2(server, str);
        exit(0);
    }
}

void move_player(server_t *server)
{
    if (server->ready == 2) {
        write(server->clients[0], "START\n", 6);
        write(server->clients[1], "START\n", 6);
        server->ready++;
    }
    server->player1->x += (1.0 / 2.0);
    server->player2->x += 0.5;
    check_end(server);
    check_end_end(server);
    check_coin(server);
    move_player_y(server);
    printf("player 1 x: %g\n", server->player1->x);
    printf("player 1 y: %g\n\n", server->player1->y);
    printf("player 2 x: %g\n", server->player2->x);
    printf("player 2 y: %g\n\n", server->player2->y);
    write_player(server);
}
