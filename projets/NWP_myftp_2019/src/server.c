/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

int         init_bis(my_ftp *ftp)
{
    if (bind(ftp->fd, (CSOCK *)&ftp->sin,
            sizeof(ftp->sin)) == -1) {
        shutdown(ftp->fd, 2);
        if (close(ftp->fd) == -1)
            return (ERROR);
        return (ERROR);
    }
    if (listen(ftp->fd, 10) == -1){
        if (close(ftp->fd) == -1)
            return (ERROR);
        return (ERROR);
    }
    return (CORECT);
}

int         init_serv(my_ftp *ftp)
{
    int _protocol;

    ftp->entry_of_protocol = getprotobyname("TCP");
    if (ftp->entry_of_protocol == NULL)
        _protocol = ftp->entry_of_protocol->p_proto;
    ftp->fd = socket(AF_INET, SOCK_STREAM, _protocol);
    if (ftp->fd == -1)
        return (ERROR);
    ftp->sock_size = sizeof(ftp->sin);
    ftp->sin.sin_family = AF_INET;
    ftp->sin.sin_port = htons(ftp->port);
    ftp->sin.sin_addr.s_addr = INADDR_ANY;
    if (init_bis(ftp) == ERROR)
        return (ERROR);
    return (CORECT);
}

void        request_stacker(my_client *iencli, char *command)
{
    char **stack;

    if (command != NULL) {
        if (strlen(command) > 0) {
            stack = str_wordtab(command, "  \t\n\r");
            (stack != NULL) ? request_checker(stack, iencli) : \
            dprintf(iencli->fd, "500 Unknow command.\n");
            (stack != NULL) ? free_tab(stack) : 0;
        }
        free(command);
    }
}

void        handle_request(my_ftp *ftp, char *ip)
{
    char *line = NULL;
    my_client *iencli = clientstruct_init(ftp, ip);

    if (!iencli)
        return;
    dprintf(iencli->fd, "220\n");
    while (1) {
        line = get_next_line(iencli->fd);
        request_stacker(iencli, line);
        if (iencli->ret == -1)
            break;
    }
    free_client(iencli);
}

void        handle_server(my_ftp *ftp)
{
    SOCK_IN iencli_listener;

    while (1) {
        ftp->fd_iencli = accept(ftp->fd, (SOCK *)
            &iencli_listener, &ftp->sock_size);
        if (ftp->fd_iencli != -1) {
            if (fork() == 0) {
                handle_request(ftp, inet_ntoa(iencli_listener.sin_addr));
                close(ftp->fd);
                exit(0);
            } else {
                close(ftp->fd_iencli);
            }
        }
    }
    close(ftp->fd);
}