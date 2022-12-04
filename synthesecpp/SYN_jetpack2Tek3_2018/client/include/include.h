/*
** EPITECH PROJECT, 2019
** -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window
** File description:
** -lc_graph_prog
*/

#ifndef oui
#define oui

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#define ERROR   84
#define SIZE    1024

typedef int     SOCKET;
typedef struct  sockaddr_in SOCKADDR_IN;
typedef struct  sockaddr    SOCKADDR;

typedef struct graphical_t
{
    int             success;
    sfRenderWindow	*window;

    sfTexture*	    textu1;
    sfTexture*	    textu2;
    sfTexture*	    textu3;

    sfVector2f	    vect1;
    sfVector2f	    vect2;
    sfVector2f	    vect3;

    sfSprite*	    sprite1;
    sfSprite*	    sprite2;
    sfSprite*	    sprite3;

    sfVector2f	    mouse;

    pthread_t       thread1;
    pthread_t       thread2;

    int             id;
    int             x;
    int             x2;
    int             y;
    int             y2;
    int             score;
    int             score2;
    char            **map;
    int             map_width;
    int             map_height;
    int             occ;
    int             icc;
    int             print_wid;
    int             print_hei;

    int             finish;

    char            *cpltbuf;
    int             port;
    char            *ip;
    SOCKET          sock;
    SOCKADDR_IN     sin;
}       graphical;

struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
};

typedef struct framebuffer framebuffer_t;


/* ALL_SEND.C */
void            sendcmd_id(graphical *grap);
void            sendcmd_map(graphical *grap);
void            sendcmd_ready(graphical *grap);
void            sendcmd_fireon(graphical *grap);
void            sendcmd_fireoff(graphical *grap);

/* GAME_INIT.C    1*/
void            strmappar(graphical *grap);
void            launchgame(graphical *grap);

/* SFML_FUNC.C    2*/
void	        window_init(graphical *grap);
void	        text_init(graphical *grap);
void	        drawsprite(graphical *grap);
void	        init_graph(graphical *grap);

/* ERROR_FUNC.C   3*/
int             ip_check(char *str);
int             port_check(char *str);
int             error_handler(char **av);

/* MENU_INIT.C    4*/
void            quit_game(graphical *grap, sfEvent	event);
void            launchmenu(graphical *grap);
void            *game_loop(void *grap);

/* USEFULL_FUN.C  5*/
void            check_protocol(char *str, graphical *grap);

/* PROTO_PARSER.C 6*/
void	protocol_id(char *str, graphical *grap);
void	protocol_map(char *str, graphical *grap);
void	protocol_start(char *str, graphical *grap);
void	protocol_player(char *str, graphical *grap);
void	protocol_coin(char *str, graphical *grap);
void	protocol_finish(char *str, graphical *grap);


/* MAIN.C         7*/
void            *init_connect(void *grap);
graphical       *graphicalstruct_init();
int             init_thread(graphical *grap);
int             main(int ac, char **av);

#endif /* !oui */
