/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** connect_server
*/

#include "../include/client.h"

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
	if ((buffer = malloc(sizeof(char) * 1 + 1)) == NULL
	    || (size = read(fd, buffer, 1)) == -1)
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

void        free_tab(char **stack)
{
    int i = -1;

    while (stack[++i])
        free(stack[i]);
    free(stack);
}

int         connect_to_socket(my_client *cli)
{
    cli->sock = socket(AF_INET, SOCK_STREAM, 0);
    cli->sin.sin_addr.s_addr = inet_addr(cli->ip);
    cli->sin.sin_family = AF_INET;
    cli->sin.sin_port = htons(cli->port);

    if (connect(cli->sock, (struct sockaddr*)&cli->sin, sizeof(cli->sin)) != -1) {
        printf("Connexion à %s sur le port %d.\n", inet_ntoa(cli->sin.sin_addr), htons(cli->sin.sin_port));
        return (1);
    } else
        printf("Impossible de se connecter à %s sur le port %d.\n", inet_ntoa(cli->sin.sin_addr), htons(cli->sin.sin_port));
    // return (0);
    return (1);
}