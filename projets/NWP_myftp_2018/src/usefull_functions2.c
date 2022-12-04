/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "my.h"

void    putstr_client(char *str, int fd_client)
{
    int	i = -1;

    while (str[++i]) {
        write(fd_client, &str[i], 1);
    }
}

void	putstr(char *str)
{
    int	i = -1;

    while (str[++i]) {
        write(1, &str[i], 1);
    }
}

void	puterror(char *str)
{
    int	i = -1;

    while (str[++i]) {
        write(2, &str[i], 1);
    }
}

char	*int_to_string(int nb)
{
    int	i = 0;
    int	x = nb;
    char	*str;

    while (x > 0)
    {
        x /= 10;
        i += 1;
    }
    if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
        return (NULL);
    snprintf(str, (i + 1), "%d", nb);
    return (str);
}

char    *format_addr(char *ip)
{
    int	i = -1;

    while (ip[++i])
    {
        if (ip[i] == '.')
	        ip[i] = ',';
    }
    return (ip);
}