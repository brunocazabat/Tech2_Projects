/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace::std;

bool            my_isdigit(char ch)
{
    return isdigit(static_cast<unsigned char>(ch));
}

void            print_usage()
{
    cerr << "USAGE: ./zappy_ai -p port -n name -h machine" << endl;
    cerr << "\tport is the port number" << endl;
    cerr << "\tname is the name of the team" << endl;
    cerr << "\tmachine is the name of the machine; localhost by default" << endl;
}

zappyIA	        *init_struct()
{
    zappyIA *data;
    data = (zappyIA *)malloc(sizeof(zappyIA));

	if (!data)
		return (NULL);
    data->help = "-help";
    data->level = 1;
	return (data);
}

void            mapsizeparser(zappyIA *data)
{
    data->mapsize = stoi(data->cpltbuffer);
}

void            grabsomegems(zappyIA *data)
{
    string linemateitm = "linemate\n";
    string deraumereitm = "deraumere\n";
    string siburitm = "sibur\n";
    string mendianeitm = "mendiane\n";
    string phirasitm = "phiras\n";
    string thystameitm = "thystame\n";
    int i = 0;
    int j = 0;

    /* FIRST ITEM */
    sendcmd_take(data, linemateitm);
    receive_str(data);
    if (strcmp(data->cpltbuffer.c_str(), KO) == 0)
        i = i + 1;

    /* SECOND ITEM */
    sendcmd_take(data, deraumereitm);
    receive_str(data);
    if (strcmp(data->cpltbuffer.c_str(), KO) == 0)
        i = i + 1;

    /* THIRD ITEM */
    sendcmd_take(data, siburitm);
    receive_str(data);
    if (strcmp(data->cpltbuffer.c_str(), KO) == 0)
        i = i + 1;

    /* FOURTH ITEM */
    sendcmd_take(data, mendianeitm);
    receive_str(data);
    if (strcmp(data->cpltbuffer.c_str(), KO) == 0)
        i = i + 1;

    /* FIFTH ITEM */
    sendcmd_take(data, phirasitm);
    receive_str(data);
    if (strcmp(data->cpltbuffer.c_str(), KO) == 0)
        i = i + 1;

    /* SIXTH ITEM */
    sendcmd_take(data, thystameitm);
    receive_str(data);
    if (strcmp(data->cpltbuffer.c_str(), KO) == 0)
        i = i + 1;

    if (i >= 3) {
        sendcmd_forward(data);
        receive_str(data);
        j = j + 1;
    }
    if (j == data->mapsize - 1) {
        cout << "--- CHANGEMENT DE COLONNE ---\n";
        j = 0;
        sendcmd_right(data);
        receive_str(data);
        sendcmd_forward(data);
        receive_str(data);
        sendcmd_left(data);
        receive_str(data);
    }
    askforinv(data);
}