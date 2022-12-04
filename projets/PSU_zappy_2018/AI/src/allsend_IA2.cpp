/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace std;

void            sendcmd_eject(zappyIA *data)
{
    send(data->sock, "Eject\n", strlen("Eject\n"), 0);
}

void            sendcmd_fork(zappyIA *data)
{
    send(data->sock, "Fork\n", strlen("Fork\n"), 0);
}

void            sendcmd_set(zappyIA *data, std::string gem)
{
    string command = "Set ";
    command += gem;

    send(data->sock, command.c_str(), strlen(command.c_str()), 0);
    receive_str(data);
}

void            sendcmd_look(zappyIA *data)
{
    send(data->sock, "Look\n", strlen("Look\n"), 0);
}

void            sendcmd_take(zappyIA *data, std::string gem)
{
    string command = "Take ";
    command += gem;

    send(data->sock, command.c_str(), strlen(command.c_str()), 0);
}

void            sendcmd_broadc(zappyIA *data, string msg)
{
    string command = "Broadcast ";
    command += msg;

    send(data->sock, command.c_str(), strlen(command.c_str()), 0);
}

void            sendcmd_incantation(zappyIA *data)
{
    send(data->sock, "Incantation\n", strlen("Incantation\n"), 0);
    receive_str(data);
}

int             call_lvl2(zappyIA *data)
{
    int i = 0;
    cout << "--- CALLING AN LVL 2 PLAYER ---" << endl;
    
    while (i != 10) {
        sendcmd_broadc(data, "JOIN\n");
        receive_str(data);
        i = i + 1;
        sleep(1);
    }
    return (0);
}