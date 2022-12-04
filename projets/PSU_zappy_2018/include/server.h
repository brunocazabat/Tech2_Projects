/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** zappy
*/

#include <string.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <getopt.h>
#include <netdb.h>
#include <stdbool.h>
#include <signal.h>
#include <time.h>
#include <errno.h>


#define _ok "ok\n"
#define _ko "ko\n"
#define _dead "_dead\n"
#define _message "WELCOME\n"
#define MAX_CLIENTS 8

typedef enum direction_s direction_s;
typedef	struct	timespec	t_time;
typedef struct s_player t_player;
typedef struct orientation_s orientation_t;
typedef struct s_cmds t_cmds;

enum direction_s
{
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NO_DIR
};

struct orientation_s {
	direction_s	dir;
	int	up_left;
	int	up_center;
	int	up_right;
	int	down_left;
	int	down_center;
	int down_right;
	int	center_left;
	int	center_right;
};

typedef struct s_case
{
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int food;
    int *player;
    int *egg;
} t_case;

typedef struct s_cmds
{
    char *cmd;
    t_cmds *next;
} t_cmds;

typedef struct s_player
{
    int x;
    int y;
    int sd;
    int lvl;
    t_case iventory;
    enum direction_s direction;
    t_cmds *cmds;
    int time_remain;
    clock_t food;
    int time_death;
    clock_t start;
} t_player;

typedef struct s_egg
{
    int x;
    int y;
    int id;
    enum direction_s direction;
} t_egg;

typedef struct s_team
{
  int	len_team;
  char		*name;
  t_player	*player;
  t_egg     *egg;
} t_team;

typedef struct s_option
{
  char		*p;
  char		*n;
  int	x;
  int	y;
  int	c;
  int	f;
  bool		g;
  char		**team;
} t_option;

typedef struct s_vector {
	int	x;
	int	y;
} t_vector;

typedef struct s_graph {
    int fd;
    clock_t cycle;
} t_graph;

bool show_option(t_option *const option);
bool get_option(t_option *const option, char **argv, int const argc);
t_case **init_map(int x, int y);
int cmd(int sd, t_team *team,  char *str, t_case **map, t_option *options);
int send_message(int sd, char *msg);
void Take(t_player *p, t_case **map, char *str);
void print_map(t_case **map, int x, int y);
t_player *get_player(int sd, t_team *team);
void look_cmd(t_case **map, t_player *p, t_option *options);
char *create_msg(t_case **map, t_team *team, t_option options);
t_team *get_team(int sd, t_team *team);
void broadcast(t_player *p, t_case **map, char *buffer, t_team *team, t_option *options);
int stock_move(int sd, char *buffer, t_team *team);
int check_cmd(char *buffer);

int stock_move(int sd, char *buffer, t_team *team);
int handle_move(int *client_socket, t_team *team, t_case **map, t_option *opt);
void handle_food(t_team *team, t_option *opt);