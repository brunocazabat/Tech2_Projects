/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include "utils.h"

typedef struct my_ftp_t
{
    int             fd;
    int             fd_iencli;
    int             status;
    int             port;
    char            *path;
    BRUH            *entry_of_protocol;
    SOCK_IN         sin;
    SOCKLEN         sock_size;
}       my_ftp;

typedef struct my_client_t {
    int             fd;
    int             ret;
    int             fd_mod;
    int             pasv_port;
    int             pasv_mod;
    int             log;
    char            *ip;
    char            *username;
    char            *password;
    char            *path_cl;
    bool            quit;
}       my_client;

/*      ALL CLIENTS FUNC PROTOTYPES     */
//request_func1.c and request_func2.c
void        user(char **stack, my_client *iencli);
void        pass(char **stack, my_client *iencli);
void        _cwd(char **stack, my_client *iencli);
void        cdup(char **stack, my_client *iencli);
void        quit(char **stack, my_client *iencli);
int         path_changer(char **stack);
int         path_changer_wdup(char *path);
char        *get_ip(char **stack);
//request_func3.c and request_func4.c
void        dele(char **stack, my_client *iencli);
void        _pwd(char **stack, my_client *iencli);
void        pasv(char **stack, my_client *iencli);
void        port(char **stack, my_client *iencli);
void        help(char **stack, my_client *iencli);
int         init_port2(my_client *cli, char **stack, SOCK_IN *sock_in);
int         init_port(char **stack, my_client *cli, BRUH *prot_entry);
void        open_port(char **stack, my_client *cli, BRUH *prot_entry);
//request_func5.c and request_func6.c
void        noop(char **stack, my_client *iencli);
void        retr(char **stack, my_client *iencli);
void        stor(char **stack, my_client *iencli);
void        list(char **stack, my_client *iencli);
int         shw_retr(char **stack, int new_fd, my_client *iencli);
void        exec_retr(char **stack, my_client *iencli);
int         shw_stor(char **stack, int fd, my_client *iencli);
void        exec_stor(char **stack, my_client *iencli);
void        exec_list(my_client *iencli);


/*      PUTIN DE PASV       */
void        print_pasv(char **stack, my_client *iencli);
int         init_pasv(my_client *iencli, SOCK_IN *sock_in);
int         pasv_mod(my_client *iencli, BRUH *proto_entry);

/*      UTILSCLIENTFUNC.C   */
void        point_func(char **stack, my_client *iencli, int func_nbr);
int         execute_request(char **stack, my_client *iencli);
void        request_checker(char **stack, my_client *iencli);
void        free_tab(char **stack);
void        free_client(my_client *iencli);

/*      UTILSSERVERFUNC.C         */
char	    *get_next_line(int fd);
char        **str_wordtab(char *str, char *tok);
my_ftp      *ftpstruct_init();
my_client   *clientstruct_init(my_ftp *ftp, char *ip);

/*      ERRORHANDLER.C      */
void        print_usage(void);
int         port_check_tab(char **stack);
int         port_check(char *str);
int         path_check(char *str);
int         check_args(my_ftp *ftp, char **av);

/*      SERVER.C            */
int         init_serv(my_ftp *ftp);
void        request_stacker(my_client *iencli, char *command);
void        handle_request(my_ftp *ftp, char *ip);
void        handle_server(my_ftp *ftp);

/*      MAIN.C              */
int         main_handler(int ac, char **av);
int         main(int ac, char **av);