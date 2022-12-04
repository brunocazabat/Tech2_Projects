/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/server.h"

char	*index_str(void)
{
    char *str;

    str = malloc(sizeof(char) * 5);
    str[0] = 'I';
    str[1] = 'M';
    str[2] = 'R';
    str[3] = 'F';
    return (str);
}
void	init_tab(int (**tab)(server_t  *server))
{
    tab[0] = &protocol_id;
    tab[1] = &protocol_map;
    tab[2] = &protocol_ready;
    tab[3] = &protocol_fire;
}

void check_protocol(char *protocol, server_t  *server)
{
    int (*tab[5])(server_t  *server);
    int v = 0;
    char *save;
    save = malloc(sizeof(char) * 5);
    save = index_str();
    init_tab(tab);
    while (save[v] != protocol[0]) {
        v++;
        if (save[v] == '\0')
            return ;
    }
    tab[v](server);
}
