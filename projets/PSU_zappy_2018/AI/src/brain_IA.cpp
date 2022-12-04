/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace std;

void        askforinv(zappyIA *data)
{
    sendcmd_inv(data);
    receive_str(data);
    inventory_parser(data);
}

void        init_game(zappyIA *data)
{
    receive_str(data);
	send_teamname(data);
    receive_str(data);
    receive_str(data);
    mapsizeparser(data);
}

int         gameloop(zappyIA *data)
{
    int     death = 0;
    int     tour = 0;
    
    /* PROTOCOLE DE DEBUT */
    init_game(data);

    //sendcmd_look(data);

    while (!death) {
        if (tour % 6 == 5) {
            askforinv(data);
        }
        if (data->food <= 5)
            sendcmd_food(data);
        else
            grabsomegems(data);
        if (shallweimprove(data) == 0 && data->food > 5)
            letsimprove(data);
        tour = tour + 1;  
    }
    return (0);
}