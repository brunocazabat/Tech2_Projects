/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define ERROR           84
#define CORRECT         0
#define MAX_CLI         100

typedef struct          protoent BRUH;
typedef struct          sockaddr_in SOCK_IN;
typedef const struct    sockaddr CSOCK;
typedef struct          sockaddr SOCK;
typedef socklen_t       SOCKLEN;