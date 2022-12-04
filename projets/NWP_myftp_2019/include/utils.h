/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERROR       84
#define CORECT      0
#define READ_SIZE   2
#define MALLOC_BRUH 200
#define ARCHI_BRUH  4096
#define MAGIC_WRD   42

typedef struct  protoent BRUH;
typedef struct  sockaddr_in SOCK_IN;
typedef const struct sockaddr CSOCK;
typedef struct sockaddr SOCK;
typedef socklen_t SOCKLEN;