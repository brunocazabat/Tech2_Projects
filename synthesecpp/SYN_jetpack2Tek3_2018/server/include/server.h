/*
** EPITECH PROJECT, 2019
** SELECT
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_
# define TIMEOUT 25000
#define _GNU_SOURCE
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/select.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct player
{
    float x;
    float y;
    int id;
    int score;
    int fire;
}       player_t;

typedef struct map
{
    char *map_str;
    char **map_tab;
    int width;
    int height;
}           mapping_t;

typedef struct server
{
    int pid;
    int fd_server;
    int fd_client;
    int i;
    int msd;
    int sd;
    int count;
    int ready;
    int sock;
    int g;
    int clients[30];
    char started;
    char *buffer;
    char *map;
    int gravity;
    fd_set active_fd_set;
    fd_set read_fd_set;
    struct sockaddr_in socket;
    struct sockaddr_in client;
    player_t *player1;
    player_t *player2;
    mapping_t *mapping;
}       server_t;

int check_args(char **tab, server_t *server);
void init_server_data(server_t *server);
int server_accept(server_t *server);
int lauching_server(int fd, server_t *server);
void check_protocol(char *protocol, server_t  *server);
void	protocol_id(server_t *server);
void	protocol_map(server_t *server);
void	protocol_ready(server_t *server);
void    protocol_fire(server_t *server);
void move_player(server_t *server);
void display_wall_player2(server_t *server, char *str);
void display_wall_player1(server_t *server, char *str);
void display_coin_player2(server_t *server, char *str);
void display_coin_player1(server_t *server, char *str);
void check_coin(server_t *server);

#endif /* !SERVER_H_ */
