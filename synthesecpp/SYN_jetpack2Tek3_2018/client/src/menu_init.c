/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"


void            launchmenu(graphical *grap)
{
    sfEvent	event;
    window_init(grap);
    text_init(grap);

    while (sfRenderWindow_isOpen(grap->window)) {
        drawsprite(grap);
        while (sfRenderWindow_pollEvent(grap->window, &event)) {
            quit_game(grap, event);
        }
        sfRenderWindow_display(grap->window);
    }
}

void             *game_loop(void *grap)
{
    init_graph((graphical *)(grap));
    launchmenu((graphical *)(grap));
    if (((graphical *)grap)->success == 1)
        launchgame((graphical *)(grap));
    return (NULL);
}