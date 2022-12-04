/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include "utils.h"

typedef struct my_server_t
{
    int             max_sd, fd, sd, i, activ, cli_fd, read, port;
    int             client_socket[MAX_CLI];
    char            buffer[1025];
    fd_set          readfds;
    BRUH            *entry_of_protocol;
    SOCK_IN         sin;
    SOCKLEN         sock_size;
    struct timeval  tv;
}       my_server;

/* ####     FEATURES        ####    */
/*      CREATE.C            */
void        _create(char **stack, my_server *s);

/*      HELP.C              */
void        _help(char **stack, my_server *s);

/*      INFO.C              */
void        _info(char **stack, my_server *s);

/*      LIST.C              */
void        _list(char **stack, my_server *s);

/*      LOGIN.C             */
void        _login(char **stack, my_server *s);

/*      LOGOUT.C            */
void        _logout(char **stack, my_server *s);

/*      MESSAGES.C          */
void        _message(char **stack, my_server *s);

/*      SEND.C              */
void        _send(char **stack, my_server *s);

/*      SUBSCRIBE.C         */
void        _subscribe(char **stack, my_server *s);

/*      SUBSCRIBEDLIST.C    */
void        _subscribed(char **stack, my_server *s);

/*      UNSUBSCRIBE.C       */
void        _unsubscribe(char **stack, my_server *s);

/*      USE.C               */
void        _use(char **stack, my_server *s);

/*      USER.C              */
void        _user(char **stack, my_server *s);

/*      USERLIST.C          */
void        _users(char **stack, my_server *s);


/* ####     SRC SERV        ####    */
/*      USEFULLFUNC.C       */
char            **str_wordtab(char *str, char *tok);
my_server       *srvstruct_init(char *port);
void            free_tab(char **stack);

/*      REQUEST_HANDLER.C   */
void            point_func(char **stack, my_server *s, int func_nbr);
int             execute_request(char **stack, my_server *s);
void            request_checker(char **stack, my_server *s);
void            request_stacker(my_server *s, char *command);

/*      HANDLE_SERVER.C     */
void            handle_read(my_server *s);
void            handle_accept(my_server *s);
void            handle_select(my_server *s);
void            handle_server(my_server *s);

/*      SERVER_INIT.C       */
int             init2_serv(my_server *s);
int             init_serv(my_server *s);

/*      ERRORHANDLER.C      */
void            print_usage(void);
int             port_check(char *str);
int             check_args(my_server *srv, char **av);

/*      MAIN.C              */
int             main_handler(int ac, char **av);
int             main(int ac, char **av);