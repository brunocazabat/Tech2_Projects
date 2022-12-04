/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

int         path_changer(char **stack)
{
    char *path = realpath(stack[1], NULL);

    if ((stack[1] && stack[2] != NULL) || (path == NULL)
    || (chdir(stack[1]) == -1))
        return (1);
    return (CORECT);
}

int         path_changer_wdup(char *path)
{
    if (chdir(path) == -1)
        return (1);
    return (CORECT);
}

char        *get_ip(char **stack)
{
    char *adress = malloc(sizeof(char) * (strlen(stack[0]) + \
    strlen(stack[1]) + strlen(stack[2]) + strlen(stack[3]) + 5));
    int i = 0;
    int j = 0;
    int k = 0;

    while (stack[i] && i != 4) {
        while (stack[i][j] != '\0') {
            adress[k] = stack[i][j];
            j++;
            k++;
        }
        adress[k] = '.';
        k++;
        j = 0;
        i++;
    }
    adress[k - 1] = '\0';
    return (adress);
}