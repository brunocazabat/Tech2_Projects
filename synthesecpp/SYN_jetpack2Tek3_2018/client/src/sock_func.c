/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"


void            receive_str(graphical *grap)
{
    char pbuffer[SIZE];
    int n = 0;
    if ((n = recv(grap->sock, pbuffer, SIZE, 0)) == -1)
        perror("recv");
    pbuffer[n] = '\0';
    grap->cpltbuf = strdup(pbuffer);
    printf("%s\n", grap->cpltbuf);
}

void            connect_seq(graphical *grap)
{
    printf("Connexion à %s sur le port %d\n", inet_ntoa(grap->sin.sin_addr)
    , htons(grap->sin.sin_port));
    sendcmd_id(grap);
    receive_str(grap);
    //check_protocol(grap->cpltbuf, grap);
    sendcmd_map(grap);
    receive_str(grap);
    //check_protocol(grap->cpltbuf, grap);
    printf("Protocol de connection achevé.\n");
}

int             socket_connect(graphical *grap)
{
    grap->sock = socket(AF_INET, SOCK_STREAM, 0);
    grap->sin.sin_addr.s_addr = inet_addr(grap->ip);
    grap->sin.sin_family = AF_INET;
    grap->sin.sin_port = htons(grap->port);

    if (connect(grap->sock, (SOCKADDR *)&grap->sin, sizeof(grap->sin)) != -1) {
        connect_seq(grap);
    }
    else
        printf("Impossible de se connecter\n");
    return (0);
}

void            *init_connect(void *grap)
{
    socket_connect((graphical *)(grap));

    return (NULL);
}
