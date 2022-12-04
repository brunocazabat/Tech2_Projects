/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "server.h"

char        *get_next_line(int fd)
{
	static char *str;
	char *buffer;
	int size = 0;
	int n;
	
	if (str == NULL){
		if ((str = malloc(sizeof(char))) == NULL)
			return (NULL);
		str[0] = 0;
	}
	if ((buffer = malloc(sizeof(char) * READ_SIZE + 1)) == NULL
	    || (size = read(fd, buffer, READ_SIZE)) == -1)
		return (NULL);
	if (size == 0)
		return (NULL);
	buffer[size] = 0;
	str = strcat(str, buffer);
	for (size = 0; str[size] && str[size] != '\n'; size++);
	if (str[size] == 0)
		return (get_next_line(fd));
	if ((buffer = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	buffer[size] = 0;
	for (n = 0; n < size; n++)
		buffer[n] = str[n];
	str += size + 1;
	return (buffer);
}

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

my_ftp      *ftpstruct_init(void)
{
    my_ftp *ftp = malloc(sizeof(my_ftp));

    if (!ftp)
        return (NULL);
    ftp->fd             = 0;
    ftp->fd_iencli      = 0;
    ftp->status         = 0;
    ftp->port           = 0;
    ftp->path           = NULL;

    return (ftp);
}

my_client   *clientstruct_init(my_ftp *ftp, char *ip)
{
    my_client *iencli = malloc(sizeof(my_client));

    if (!iencli)
        return (NULL);
    iencli->pasv_mod       = 0;
    iencli->pasv_port      = -42;
    iencli->fd_mod          = -1;
    iencli->ret             = 0;
    iencli->log             = -42;
    iencli->fd              = ftp->fd_iencli;
    iencli->ip              = ip;
    iencli->quit            = false;
    iencli->username        = NULL;
    iencli->password        = NULL;

    return (iencli);
}