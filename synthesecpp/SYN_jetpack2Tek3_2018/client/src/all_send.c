/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"

void            sendcmd_id(graphical *grap)
{
    send(grap->sock, "ID\n", strlen("ID\n"), 0);
}

void            sendcmd_map(graphical *grap)
{
    send(grap->sock, "MAP\n", strlen("MAP\n"), 0);
}

void            sendcmd_ready(graphical *grap)
{
    send(grap->sock, "READY\n", strlen("READY\n"), 0);
}

void            sendcmd_fireon(graphical *grap)
{
    send(grap->sock, "FIRE 1\n", strlen("FIRE 1\n"), 0);
}

void            sendcmd_fireoff(graphical *grap)
{
    send(grap->sock, "FIRE 0\n", strlen("FIRE 0\n"), 0);
}