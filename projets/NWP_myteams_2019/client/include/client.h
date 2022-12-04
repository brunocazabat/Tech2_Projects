/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <sys/socket.h>
#include "utils.h"

typedef struct my_client_t
{
    char *ip;
    int port;
    int sock;
    struct sockaddr_in sin;
} my_client;

typedef struct command_s {
    char *str;
    void (*func)(my_client *);
} command_t;

/* ####     FEATURES        ####    */
/*      CREATE.C            */
void        _create(char **stack, my_client *s);

/*      HELP.C              */
void        _help(char **stack, my_client *s);

/*      INFO.C              */
void        _info(char **stack, my_client *s);

/*      LIST.C              */
void        _list(char **stack, my_client *s);

/*      LOGIN.C             */
void        _login(char **stack, my_client *s);

/*      LOGOUT.C            */
void        _logout(char **stack, my_client *s);

/*      MESSAGES.C          */
void        _message(char **stack, my_client *s);

/*      SEND.C              */
void        _send(char **stack, my_client *s);

/*      SUBSCRIBE.C         */
void        _subscribe(char **stack, my_client *s);

/*      SUBSCRIBEDLIST.C    */
void        _subscribed(char **stack, my_client *s);

/*      UNSUBSCRIBE.C       */
void        _unsubscribe(char **stack, my_client *s);

/*      USE.C               */
void        _use(char **stack, my_client *s);

/*      USER.C              */
void        _user(char **stack, my_client *s);

/*      USERLIST.C          */
void        _users(char **stack, my_client *s);


/*      CLI_LOOP.C          */
void            point_func(char **stack, my_client *s, int func_nbr);
int             execute_request(char **stack, my_client *s);
void            request_checker(char **stack, my_client *s);
void            request_stacker(my_client *s, char *command);
void            cli_loop(my_client *cli);

/*      CONNECT_SERVER.C    */
int             connect_to_socket(my_client *cli);
char            *get_next_line(int fd);
char            **str_wordtab(char *str, char *tok);
void            free_tab(char **stack);

/*      ERRORHANDLER.C      */
void            print_usage(void);
int             port_check(char *str);
int             ip_check(char *str);
int             check_args(my_client *cli, char **av);

/*      MAIN.C              */
my_client       *clistruct_init(void);
int             main_handler(int ac, char **av);
int             main(int ac, char **av);