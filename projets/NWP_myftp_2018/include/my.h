/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef MY_H_
    #define MY_H_


# define MAX_CONNECT_TRY	3
# define MAX_CLIENT	1000

# define MAX_OCTET	256
# define NB_OCTET_READ	5

# define ERROR_FCT	1
# define ERROR_PARAM	2
# define QUIT		221

#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

typedef struct	s_data
{
    char    *help;
	int	opt_t;
}		t_data;

/* USEFULL_FUNCTION */
short	is_digit(char *tsr);
t_data	*init_struct(void);
void    print_usage();

/* USEFULL_FUNCTION2 */
void			putstr_client(char *str, int fd_client);
void			putstr(char *str);
void			puterror(char *str);
char			*int_to_string(int nb);
char			*format_addr(char *ip);

#endif /* !MY_H_ */
