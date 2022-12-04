/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

char        **str_wordtab(char *str, char *tok)
{
    int i = 0;
    char **stack = malloc(sizeof(char *));
    char *token = strtok(str, tok);

    if (!str || !stack || !token)
        return (NULL);
    while (1) {
        stack[i] = strdup(token);
        i = i + 1;
        stack = realloc(stack, (sizeof(char *) * (i + 1)));
        token = strtok(NULL, tok);
        if (token == NULL){
            stack[i] = token;
            break;
        }
    }
    free(token);
    return (stack);
}

my_server       *srvstruct_init(char *port)
{
    my_server *srv  = malloc(sizeof(my_server));

    if (!srv)
        return (NULL);
    //INIT ALL STRUCT VALUE HERE
    srv->port       = atoi(port);
    srv->fd         = 0;

    return (srv);
}

void        free_tab(char **stack)
{
    int i = -1;

    while (stack[++i])
        free(stack[i]);
    free(stack);
}