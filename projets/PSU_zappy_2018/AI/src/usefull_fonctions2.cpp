/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace std;

int             socket_connect(zappyIA *data)
{
    data->sock = socket(AF_INET, SOCK_STREAM, 0);
    data->sin.sin_addr.s_addr = inet_addr(data->machinename);
    data->sin.sin_family = AF_INET;
    data->sin.sin_port = htons(data->PORT);

    if (connect(data->sock, (SOCKADDR*)&data->sin, sizeof(data->sin)) != ERROR)
        cout << "\nConnexion à "<< inet_ntoa(data->sin.sin_addr) 
        << " sur le port " << htons(data->sin.sin_port) << " réussie." << endl;
    else
        cerr << "\nImpossible de se connecter à " << inet_ntoa(data->sin.sin_addr)
        << " sur le port " << htons(data->sin.sin_port) << "." << endl;
    
    return (0);
}

void            receive_str(zappyIA *data)
{
	char pbuffer[SIZE];
    int n = 0;
    if ((n = recv(data->sock, pbuffer, SIZE, 0)) == -1)
        perror("recv");
    pbuffer[n] = '\0';
    data->cpltbuffer = strdup(pbuffer);
    cout << pbuffer;
    if (strncmp(data->cpltbuffer.c_str(), "message", 7) == 0 && data->level <= 2)
        broadcastinc(data);
}

void            inventory_parser(zappyIA *data)
{
    int     i = 0;
    int     nbrcnt = 0;

    while (data->cpltbuffer[i] != '\0')
    {
        if (my_isdigit(data->cpltbuffer[i]) != 0) 
        {
            switch (nbrcnt)
            {
            case 0:
                data->linemateqtt = data->cpltbuffer[i] - 48;
                break;
            case 1:
                data->siburqtt = data->cpltbuffer[i] - 48;
                break;
            case 2:
                data->deraumereqtt = data->cpltbuffer[i] - 48;
                break;
            case 3:
                data->mendianeqtt = data->cpltbuffer[i] - 48;
                break;
            case 4:
                data->phirasqtt = data->cpltbuffer[i] - 48;
                break;
            case 5:
                data->thystameqtt = data->cpltbuffer[i] - 48;
                break;
            case 6:
                data->food = data->cpltbuffer[i] - 48;
                break;
            }
            nbrcnt = nbrcnt + 1;
        }
        i = i + 1;
    }
}

int             shallweimprove(zappyIA *data)
{
    if (data->level == 1 && data->linemateqtt >= 1)
        return (0);
    if (data->level == 2 && data->linemateqtt >= 1 && data->deraumereqtt >= 1 && data->siburqtt >= 1)
        return (0);
    if (data->level == 3 && data->linemateqtt >= 2 && data->siburqtt >= 1 && data->phirasqtt >= 2)
        return (0);

    return (ERROR);
}

void            letsimprove(zappyIA *data)
{
    cout << "--- TENTATIVE DE PASSAGE AU NIVEAU SUPERIEUR ---" << endl;
    if (data->level == 1 && data->linemateqtt >= 1) {
        sendcmd_set(data, "linemate\n");
        sendcmd_incantation(data);
        data->level = 2;
        cout << "--- PASSAGE AU NIVEAU 2 REUSSI ---" << endl;
        return;
    }
    if (data->level == 2 && data->linemateqtt >= 1 && data->deraumereqtt >= 1 && data->siburqtt >= 1 && call_lvl2(data) == 0) {
        sendcmd_set(data, "linemate\n");
        sendcmd_set(data, "deraumere\n");
        sendcmd_set(data, "sibur\n");
        sendcmd_incantation(data);
        data->level = 3;
        cout << "--- PASSAGE AU NIVEAU 3 REUSSI ---";
        return;
    }
}