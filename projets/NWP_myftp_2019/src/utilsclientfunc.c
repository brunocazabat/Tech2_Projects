/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

void        point_func(char **stack, my_client *iencli, int func_nbr)
{
    static void (*pointfunc[14])(char **stack, my_client *iencli) =
        {&user, &pass, &_cwd, &cdup, &quit, &dele, &_pwd, \
        &pasv, &port, &help, &noop, &retr, &stor, &list};
    (*pointfunc[func_nbr])(stack, iencli);
}

int         execute_request(char **stack, my_client *iencli)
{
    static const char *func[15] =  {"USER", "PASS", "CWD", "CDUP", \
                                    "QUIT", "DELE", "PWD", "PASV", \
                                    "PORT", "HELP", "NOOP", "RETR", \
                                    "STOR", "LIST", NULL};
    for (int i = 0; func[i] != NULL ; i++){
        if (strcasecmp(stack[0], func[i]) == 0) {
            point_func(stack, iencli, i);
            return (CORECT);
        }
    }
    return (ERROR);
}

void        request_checker(char **stack, my_client *iencli)
{
    if (stack == NULL)
        dprintf(iencli->fd, "500 Unknow command.\n");
    else if (execute_request(stack, iencli) == 0) {
        return;
    } else {
        dprintf(iencli->fd, "500 Unknow command.\n");
        return;
    }
}

void        free_tab(char **stack)
{
    int i = -1;

    while (stack[++i])
        free(stack[i]);
    free(stack);
}

void        free_client(my_client *iencli)
{
    if (close(iencli->fd) == -1)
        exit(84);
    if (close(iencli->fd_mod) == -1)
        exit(84);
    free(iencli->username);
    free(iencli->password);
    free(iencli);
}