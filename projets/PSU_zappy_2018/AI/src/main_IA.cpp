/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace std;

int         main (int ac, char **input)
{
    /* INITIALISATION */
    zappyIA	*data = init_struct();
    
    if (ac != 7 || strcmp(input[2], data->help.c_str()) == 0) {
        print_usage();
        return (ERROR);
    }
    if (verif_arg(input, data) == ERROR)
        return (ERROR);
    confirm_set(data);

    /* CONNECTION AU SERVEUR */
    socket_connect(data);

    /* BOUCLE DE JEU */
    gameloop(data);

    /* EXIT */
    cout << "fermeture de la socket." << endl;
    closesocket(data->sock);
    free (data);
    return (0);
}