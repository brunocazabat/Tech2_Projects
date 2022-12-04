/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"

char	        *index_str()
{
    char	*str;

    str = malloc(sizeof(char) * 7);
    str[0] = 'I';
    str[1] = 'M';
    str[2] = 'S';
    str[3] = 'P';
    str[4] = 'C';
    str[5] = 'F';

    return (str);
}
void	        init_tab(void (*tab[7])(char *protocol, graphical *grap))
{
    tab[0] = &protocol_id;
    tab[1] = &protocol_map;
    tab[2] = &protocol_start;
    tab[3] = &protocol_player;
    tab[4] = &protocol_coin;
    tab[5] = &protocol_finish;
}

void            check_protocol(char *str, graphical *grap)
{
    void	(*tab[7])(char *protocol, graphical *grap);
    int	v = 0;
    char *save;

    save = malloc(sizeof(char) * 7);
    save = index_str();
    init_tab(tab);
    while (save[v] != str[0]) {
        v++;
        if (save[v] == '\0')
            return ;
    }
    tab[v](str, grap);
}
