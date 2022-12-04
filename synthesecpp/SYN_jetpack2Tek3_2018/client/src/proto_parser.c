/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"

char **tab_create(char *str, graphical *grap)
{
    int column = 0;
    int ligne = 0;
    int i = 0;
    char **tab;

    tab = malloc(sizeof(char *) * (strlen(str) + 1));
    while (str[i] != '\0') {
            tab[ligne] = malloc(sizeof(char) * (strlen(str) + 1));
            while (column != grap->map_width) {
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
    return (tab);
}

void	protocol_id(char *str, graphical *grap)
{
    int i = 3;
    int c = 0;
    char *save = malloc(sizeof(str));

    while (str[i] != '\n') {
        save[c] = str[i];
        i++;
        c++;
    }
    grap->id = atoi(save);
}

void	protocol_map(char *str, graphical *grap)
{
    int i = 4;
    int c = 0;
    char *save = malloc((sizeof(str)) + (strlen(grap->cpltbuf) * 2));

    while (str[i] != ' ') {
        save[c] = str[i];
        i++;
        c++;
    }
    grap->map_width = atoi(save);
    i++;
    c = 0;
    memset(save, 0, SIZE);
    while (str[i] != ' ') {
        save[c] = str[i];
        i++;
        c++;
    }
    grap->map_height = atoi(save);
    i++;
    c = 0;
    memset(save, 0, SIZE);
    while (str[i] != '\0') {
        save[c] = str[i];
        i++;
        c++;
    }
    grap->map = tab_create(save, grap);

    protocol_finish(str, grap);
    free(save);
}

void	protocol_start(char *str, graphical *grap)
{
    str = str;
    grap = grap;
}

void	protocol_player(char *str, graphical *grap)
{
    int i = 7;
    int c = 0;
    char *save = malloc(sizeof(str));
    int player = 2;

    while (str[i] != ' ') {
        save[c] = str[i];
        i++;
        c++;
    }

    if (grap->id == atoi(save))
        player = 1;
    i++;
    c = 0;
    save = realloc(save, sizeof(str));
    while (str[i] != ' ') {
        save[c] = str[i];
        i++;
        c++;
    }
    if (player == 1) {
        grap->x = atoi(save);
        printf("PLAYER 1 x: %d\n", atoi(save));
    }
    else {
        grap->x2 = atoi(save);
        printf("PLAYER 2 x: %d\n", atoi(save));
    }
    i++;
    c = 0;
    save = realloc(save, sizeof(str));
    while (str[i] != ' ') {
        save[c] = str[i];
        i++;
        c++;
    }
    if (player == 1) {
        grap->y = atoi(save);
        printf("PLAYER 1 y: %d\n", atoi(save));
    }
    else {
        grap->y2 = atoi(save);
        printf("PLAYER 2 y: %d\n", atoi(save));
    }
    i++;
    c = 0;
    save = realloc(save, sizeof(str));
    while (str[i] != '\0') {
        save[c] = str[i];
        i++;
        c++;
    }
    if (player == 1) {
        grap->score = atoi(save);
        printf("PLAYER 1 score: %d\n", atoi(save));
    }
    else {
        grap->score2 = atoi(save);
        printf("PLAYER 2 score: %d\n", atoi(save));
    }
}

void	protocol_coin(char *str, graphical *grap)
{
    int i = 5;
    int c = 0;
    char *save = malloc(sizeof(str));
    int x = 0;
    int y = 0;
    int player = 2;

    while (str[i] != ' ') {
        save[c] = str[i];
        i++;
        c++;
    }
    if (grap->id == atoi(save))
        player = 1;
    i++;
    c = 0;
    save = realloc(save, sizeof(str));
    while (str[i] != ' ') {
        save[c] = str[i];
        i++;
        c++;
    }
    x = atoi(save);
    i++;
    c = 0;
    save = realloc(save, sizeof(str));
    while (str[i] != '\0') {
        save[c] = str[i];
        i++;
        c++;
    }
    y = atoi(save);
    grap->map[y][x] = '_';
    if (player == 1) {
        printf("COIN get by player 1 at x:%d and y:%d\n", x, y);
        grap->score += 10;
    }
    else {
        printf("COIN get by player 2 at x:%d and y:%d\n", x, y);
        grap->score2 += 10;
    }
}

void	protocol_finish(char *str, graphical *grap)
{
    grap->finish = 1;
    pthread_exit(NULL);
}
