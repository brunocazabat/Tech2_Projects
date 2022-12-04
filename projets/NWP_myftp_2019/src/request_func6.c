/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

int         shw_retr(char **stack, int new_fd, my_client *iencli)
{
    FILE *file = fopen(stack[1], "r+");
    char str[ARCHI_BRUH];

    if (file == NULL) {
        close(new_fd);
        fclose(file);
        return (1);
    }
    else {
        dprintf(iencli->fd, "150 File status okay.\n");
        while (fgets(str, ARCHI_BRUH, file))
            dprintf(new_fd, "%s", str);
        fclose(file);
        dprintf(iencli->fd, "226 Requested file action successful.\n");
        iencli->pasv_mod = CORECT;
        close(new_fd);
        return (CORECT);
    }
}

void        exec_retr(char **stack, my_client *iencli)
{
    SOCK_IN sin;
    SOCKLEN sock_size = sizeof(sin);
    int new_fd = (iencli->pasv_mod == READ_SIZE) ? iencli->fd_mod : \
        accept(iencli->fd_mod, (SOCK *)&sin, &sock_size);

    if (new_fd == -1)
        dprintf(iencli->fd, "425 Can't open data connection.\n");
    else {
        if (shw_retr(stack, new_fd, iencli) == 1)
            dprintf(iencli->fd, "550 Requested action not taken\n");
    }
}

int         shw_stor(char **stack, int fd, my_client *iencli)
{
    int file = open(stack[1], O_CREAT | O_WRONLY | O_TRUNC, 0667);
    char str[ARCHI_BRUH];
    int i = CORECT;

    if (file == -1)
        return (1);
    dprintf(iencli->fd, "150 File status okay.\n");
    while (1) {
        i = read(fd, str, ARCHI_BRUH - 1);
        if (i <= CORECT)
            break;
        str[i] = '\0';
        dprintf(file, "%s", str);
    }
    dprintf(iencli->fd, "226 Requested file action successful.\n");
    close(iencli->fd_mod);
    iencli->pasv_mod = CORECT;
    close(file);

    return (CORECT);
}

void        exec_stor(char **stack, my_client *iencli)
{
    SOCK_IN sin;
    SOCKLEN sock_size = sizeof(sin);
    int new_fd = (iencli->pasv_mod == READ_SIZE) ? iencli->fd_mod : \
        accept(iencli->fd_mod, (SOCK *)&sin, &sock_size);

    if (new_fd == -1)
        dprintf(iencli->fd, "425 Can't open data connection.\n");
    else
        if (shw_stor(stack, new_fd, iencli) == 1)
            dprintf(iencli->fd, "550 Failed to open file.\n");
}

void        exec_list(my_client *iencli)
{
    char str[ARCHI_BRUH];
    SOCK_IN sin;
    SOCKLEN sock_size = sizeof(sin);
    FILE *file;
    int new_fd = (iencli->pasv_mod == READ_SIZE) ? iencli->fd_mod : \
        accept(iencli->fd_mod, (SOCK *)&sin, &sock_size);

    if (new_fd == -1)
        dprintf(iencli->fd, "425 Can't open data connection.\n");
    else {
        file = popen("ls -l", "r");
        while (fgets(str, ARCHI_BRUH, file))
            dprintf(new_fd, "%s", str);
        fclose(file);
        close(iencli->fd_mod);
        close(new_fd);
        iencli->fd_mod = -1;
        dprintf(iencli->fd, "226 Requested file action successful.\n");
    }
}