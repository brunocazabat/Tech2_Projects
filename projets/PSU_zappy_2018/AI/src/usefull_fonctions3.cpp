/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.hpp"

using namespace std;

void            broadcastinc(zappyIA *data)
{
    int direction = data->cpltbuffer[8] - 48;

    while (direction != 0) {
        receive_str(data);
        direction = data->cpltbuffer[8] - 48;

        if (direction == 0) {
            cout << "--- DEPLACEMENT FINIS ---" << endl;
            return;
        }

        if (direction == 1) {
            sendcmd_forward(data);
            receive_str(data);
        }

        if (direction == 2) {
            sendcmd_left(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
            sendcmd_right(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
        }

        if (direction == 3) {
            sendcmd_left(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
        }

        if (direction == 4) {
            sendcmd_left(data);
            receive_str(data);
            sendcmd_left(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
            sendcmd_right(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
        }

        if (direction == 5) {
            sendcmd_right(data);
            receive_str(data);
            sendcmd_right(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
        }

        if (direction == 6) {
            sendcmd_right(data);
            receive_str(data);
            sendcmd_right(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
            sendcmd_left(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
        }

        if (direction == 7) {
            sendcmd_right(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
        }

        if (direction == 8) {
            sendcmd_right(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
            sendcmd_left(data);
            receive_str(data);
            sendcmd_forward(data);
            receive_str(data);
        }
    }
}