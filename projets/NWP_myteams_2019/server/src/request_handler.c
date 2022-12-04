/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

void        point_func(char **stack, my_server *s, int func_nbr)
{
    static void (*pointfunc[14])(char **stack, my_server *s) =
        {&_help, &_login, &_logout, &_users, &_user, &_send, &_message, \
        &_subscribe, &_subscribed, &_unsubscribe, &_use, &_create, &_list, &_info};
    (*pointfunc[func_nbr])(stack, s);
}

int         execute_request(char **stack, my_server *s)
{
    static const char *func[15] =  {"/help", "/login", "/logout", "/users", \
                                    "/user", "/send", "/message", "/subscribe", \
                                    "/subscribed ?", "/unsubscribe", "/use ?", "/create", \
                                    "/list", "/info", NULL};
    for (int i = 0; func[i] != NULL ; i++) {
        if (strcasecmp(stack[0], func[i]) == 0) {
            point_func(stack, s, i);
            return (CORRECT);
        }
    }
    return (ERROR);
}

void        request_checker(char **stack, my_server *s)
{
    if (stack == NULL)
        dprintf(s->sd, "500 Unknow command.\n");
    else if (execute_request(stack, s) == 0) {
        return;
    } else {
        dprintf(s->sd, "500 Unknow command.\n");
        return;
    }
}

void        request_stacker(my_server *s, char *command)
{
    char **stack;

    if (command != NULL) {
        if (strlen(command) > 0) {
            stack = str_wordtab(command, "  \t\n\r");
            (stack != NULL) ? request_checker(stack, s) : \
            dprintf(s->sd, "500 Unknow command.\n");
            (stack != NULL) ? free_tab(stack) : 0;
        }
    }
}