/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef INCLUDE
#define INCLUDE

#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

#define INVALID_SOCKET -1
#define SIZE 1024
#define ERROR 84
#define KO "ko\n"
#define closesocket(param) close(param)

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

struct zappyIA
{
    int i;
    int PORT;
    int level;
    int mapsize;

    int food;

    int linemateqtt;
    int deraumereqtt;
    int siburqtt;
    int mendianeqtt;
    int phirasqtt;
    int thystameqtt;

    std::string usage;
    std::string help;
    std::string teamname;
    std::string command;
    char *machinename;
    std::string cpltbuffer;
    SOCKET sock;
    SOCKADDR_IN sin;
};  

void                    send_teamname(zappyIA *data);
void                    sendcmd_food(zappyIA *data);
void                    sendcmd_inv(zappyIA *data);
void                    sendcmd_forward(zappyIA *data);
void                    sendcmd_right(zappyIA *data);
void                    sendcmd_left(zappyIA *data);
void                    sendcmd_eject(zappyIA *data);
void                    sendcmd_fork(zappyIA *data);
void                    sendcmd_set(zappyIA *data, std::string gem);
void                    sendcmd_look(zappyIA *data);
void                    sendcmd_take(zappyIA *data, std::string gem);
void                    sendcmd_broadc(zappyIA *data, std::string msg);
void                    sendcmd_incantation(zappyIA *data);

void                    print_usage();
zappyIA                 *init_struct();
int                     gameloop(zappyIA *data);
void                    mapsizeparser(zappyIA *data);
bool                    my_isdigit(char ch);
int                     verif_arg(char **input, zappyIA *data);
void                    confirm_set(zappyIA *data);
int                     socket_connect(zappyIA *data); 
void                    broadcastinc(zappyIA *data);
int                     send(int socket, void* buffer, size_t len, int flags);
void                    askforinv(zappyIA *data);
void                    init_game(zappyIA *data);
void                    receive_str(zappyIA *data);
void                    inventory_parser(zappyIA *data);
void                    grabsomegems(zappyIA *data);
int                     shallweimprove(zappyIA *data);
void                    letsimprove(zappyIA *data);
int                     call_lvl2(zappyIA *data);
int                     call_lvl3(zappyIA *data);

#endif /* !INCLUDE */