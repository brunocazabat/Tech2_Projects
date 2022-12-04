/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"


int             init_thread(graphical *grap)
{
    if (pthread_create(&grap->thread1, NULL, init_connect, (void *)(grap)) == -1)
        return (ERROR);
    if (pthread_create(&grap->thread2, NULL, game_loop, (void *)(grap)) == -1)
        return (ERROR);

    if (pthread_join(grap->thread1, NULL))
        return (ERROR);
    if (pthread_join(grap->thread2, NULL))
        return (ERROR);
    return (0);
}

graphical       *graphicalstruct_init(void)
{
    graphical *grap = malloc(sizeof(graphical));
    grap->finish = 0;

    if (!grap)
        return (NULL);
    return (grap);
}

void            arg_parser(graphical *grap, char **av)
{
    grap->port = atoi(av[4]);
    grap->ip = strdup(av[2]);
}

int             main(int ac, char **av)
{
    graphical   *grap = graphicalstruct_init();

    if (ac != 5) {
        write(2, "ERROR: BAD ARGUMENTS.\n", 23);
        return (ERROR);
    }
    if (error_handler(av) == ERROR || !grap)
        return (ERROR);
    arg_parser(grap, av);
    if (init_thread(grap) == ERROR)
        return (ERROR);

    free(grap);
    return (0);
}