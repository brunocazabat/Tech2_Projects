/*
** EPITECH PROJECT, 2019
** look
** File description:
** look
*/

#include "../include/server.h"

t_case *check_case(t_case **map, int y, int x, t_option *opt)
{
   	if (y < 0)
		y = opt->y + y;
	if (x < 0)
		x = opt->x + x;
	return (&map[y % opt->y][x % opt->x]);
}

t_case *get_real(t_player *p, t_case **map, t_option *opt, int i, int j)
{
	switch (p->direction) {
		case (UP):
			return (check_case(map, p->y - i, p->x + j, opt));
		case (RIGHT):
			return (check_case(map, p->y + j, p->x + i, opt));
		case (DOWN):
			return (check_case(map, p->y + i, p->x - j, opt));
		case (LEFT):
			return (check_case(map, p->y - j, p->x - i, opt));
		default:
			return (NULL);
	}
}

int get_nb_player(t_case *c)
{
    int nb_player = 0;

    for (int i = 0;c->player[i] >= 0 || i > 9;i++) {
        if (c->player[i] > 0)
            nb_player++;
    }
    printf("player : %i\n", nb_player);
    return (nb_player);
}

char *get_item(int nb_item, char *name, int prev)
{
    char    buff[4095];/*  = malloc(sizeof(char) * 4095);*/
    char    *tmp = buff;

    printf("prev = %i\n", prev);
    if (prev > 0)
        tmp += sprintf(tmp, " ");
    for (int i = 0; i < nb_item; i++) {
        tmp += sprintf(tmp, "%s", name);
        if (i < nb_item - 1)
			tmp += sprintf(tmp, " ");
    }
    return (strdup(buff));
}

char *get_items(t_case *c, int nb_player)
{
    char    buff[4095];
    char    *tmp = buff;// = malloc(sizeof(char) * 4095);
    int     i = nb_player;

    if (c->deraumere > 0 || c->food > 0 || c->linemate > 0 
    || c->mendiane > 0 || c->phiras > 0 || c->sibur > 0 || c->thystame > 0) {
        if (c->deraumere > 0)
            tmp += sprintf(tmp, "%s", get_item(c->deraumere, "deraumere", i));
        i += (c->deraumere > 0) ? 1 : 0;
        if (c->food > 0)
            tmp += sprintf(tmp, "%s", get_item(c->food, "food", i));
        i += (c->food > 0) ? 1 : 0;
        if (c->linemate > 0)
            tmp += sprintf(tmp, "%s", get_item(c->linemate, "linemate", i));
        i += (c->linemate > 0) ? 1 : 0;
        if (c->mendiane > 0)
            tmp += sprintf(tmp, "%s", get_item(c->mendiane, "mendiane", i));
        i += (c->mendiane > 0) ? 1 : 0;
        if (c->phiras > 0)
            tmp += sprintf(tmp, "%s", get_item(c->phiras, "phiras", i));
        i += (c->phiras > 0) ? 1 : 0;
        if (c->sibur > 0)
            tmp += sprintf(tmp, "%s", get_item(c->sibur, "sibur", i));
        i += (c->sibur > 0) ? 1 : 0;
        if (c->thystame > 0)
            tmp += sprintf(tmp, "%s", get_item(c->thystame, "thystame", i));
        return (strdup(buff));
    } else
        return ("");
}

char *get_case_content(t_case *c, int nb_player)
{
    char    buf[4095];
    char    *tmp = buf; //malloc(sizeof(char) * 4095);
    char    *items;

    if (nb_player > 0) {
        for (int i = 0; i < nb_player; i++) {
            tmp += sprintf(tmp, "player");
            if (i < nb_player - 1)
    			tmp += sprintf(tmp, " ");
        }
    }
    items = get_items(c, nb_player);
    tmp += sprintf(tmp, "%s", items);
    return (strdup(buf));
}

void look_cmd(t_case **map, t_player *p, t_option *options)
{
    int     nb_player = 0;
    char    buf[4096];
    char    *msg = buf; //malloc(sizeof(char) * 4096);
    char    *content;
    t_case  *c;

    msg += sprintf(msg, "[ ");
    for (int i = 0; i <= p->lvl; i++) {
		for (int j = 0; j < (2 * i) + 1; j++) {
            c = get_real(p, map, options, i, j - i);
            nb_player = get_nb_player(c);
            content = get_case_content(c, nb_player);
			msg += sprintf(msg, "%s, ", content);
			free(content);
        }
    }
    msg += sprintf(msg, "]\n");
    send_message(p->sd, strdup(buf));
}