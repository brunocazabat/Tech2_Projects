/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace std;

void            send_teamname(zappyIA *data)
{
    send(data->sock, data->teamname.c_str(), strlen(data->teamname.c_str()), 0);
}

void            sendcmd_food(zappyIA *data)
{
    send(data->sock, "Take food\n", strlen("Take food\n"), 0);
    receive_str(data);
    if (strcmp(data->cpltbuffer.c_str(), KO) == 0) {
        sendcmd_forward(data);
        receive_str(data);
        data->i = data->i + 1;
    }
    if (data->i == data->mapsize - 1) {
        cout << "--- CHANGEMENT DE COLONNE ---\n";
        sendcmd_right(data);
        receive_str(data);
        sendcmd_forward(data);
        receive_str(data);
        sendcmd_left(data);
        receive_str(data);
        data->i = 0;
    }
    sendcmd_inv(data);
    receive_str(data);
}

void            sendcmd_inv(zappyIA *data)
{
    send(data->sock, "Inventory\n", strlen("Inventory\n"), 0);
}

void            sendcmd_forward(zappyIA *data)
{
    send(data->sock, "Forward\n", strlen("Forward\n"), 0);
}

void            sendcmd_right(zappyIA *data)
{
    send(data->sock, "Right\n", strlen("Right\n"), 0);
}

void            sendcmd_left(zappyIA *data)
{
    send(data->sock, "Left\n", strlen("Left\n"), 0);
}