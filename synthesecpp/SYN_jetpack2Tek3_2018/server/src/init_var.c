/*
** EPITECH PROJECT, 2019
** SYN JetPackTek3
** File description:
** init_var
*/

# include "../include/server.h"

char **tab_create(char *str, server_t *server)
{
    int column = 0, ligne = 0, i = 0;
    char **tab = malloc(sizeof(char *) * (strlen(str) + 1));

    while (str[i] != '\0') {
            tab[ligne] = malloc(sizeof(char) * (strlen(str) + 1));
            while (str[i] != '\n') {
                tab[ligne][column] = str[i];
                column++;
                i++;
                if (str[i] == '\0') {
                    i--;
                    break;
                }
            }
            column = 0;
            ligne++;
            i++;
    }
    server->mapping->height = ligne;
    return (tab);
}

void open_file(server_t *server)
{
    int fd;
    char *buffer;
    int offset = 0;
    int size;
        int len;

        buffer = malloc(sizeof(char) * 10000);
    fd = open(server->map, O_RDONLY);
    while ((size = read(fd, buffer + offset, 100)) > 0)
        offset = offset + size;
    buffer[offset] = '\0';
    close(fd);
        server->mapping->map_str = buffer;
        server->mapping->map_tab = tab_create(buffer, server);
        server->mapping->width = strlen(server->mapping->map_tab[0]);
}

void init_server_data(server_t *server)
{
    server->mapping = malloc(sizeof(mapping_t *));
    server->player1 = malloc(sizeof(player_t *));
    server->player2 = malloc(sizeof(player_t *));
    server->ready = 0;
    server->player1->x = 0;
    server->player1->y = 0;
    server->player2->x = 0;
    server->player2->y = 0;
    server->player1->score = 0;
    server->player2->score = 0;
    open_file(server);
}
