/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace std;

int         verif_arg(char **input, zappyIA *data)
{
    if (strcmp(input[1], "-p") == 0 && strcmp(input[3], "-n") == 0 && strcmp(input[5], "-h") == 0) {
        data->PORT = atoi(input[2]);
        data->teamname = input[4];
        data->machinename = input[6];
        return (1);
    }
    else
        return (ERROR);
}

void        confirm_set(zappyIA *data)
{
    cout << "Port name    :" << data->PORT << endl;
    cout << "Team name    :" << data->teamname << endl;
    cout << "Machine name :" << data->machinename << endl;
    data->teamname[strlen(data->teamname.c_str())] = '\n';
}