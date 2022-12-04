/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

# include "../include/server.h"

int parse_g(char *str, server_t *server)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '.')
            i++;
        else if (str[i] < '0' || str[i] > '9')
            return 84;
        i++;
    }
    server->gravity = atoi(str);
    return 0;
}

int parse_p(char *str, server_t *server)
{
    int i = 0;
    while (str[i]) {
        if (str[i] < 48 || str[i] > 57)
            return 84;
        i++;
    }
    server->pid = atoi(str);
    return 0;
}

int parse_m(char *str, server_t *server)
{
    FILE *fptr;
    if (!(fptr = fopen( str, "r")))
        return 84;
    fseek(fptr, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(fptr);
    if (len == 0)
        return 84;
    fclose(fptr);
    server->map = str;
    return 0;
}

int check_args(char **tab, server_t *server)
{
    int i = 0, ret = 0;

    while (tab[i]) {
        if (strcmp(tab[i], "-p") == 0)
            ret = parse_p(tab[i + 1], server);
        if (strcmp(tab[i], "-g") == 0)
            ret = parse_g(tab[i + 1], server);
        if (strcmp(tab[i], "-m") == 0)
            ret = parse_m(tab[i + 1], server);
        if (ret != 0)
            return (84);
        i++;
    }
}
