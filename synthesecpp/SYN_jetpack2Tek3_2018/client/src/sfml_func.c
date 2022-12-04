/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"


/* ALL FUNCTIONS FOR THE MENU */

void            quit_game(graphical *grap, sfEvent	event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(grap->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(grap->window);
    if (event.type == sfEvtMouseButtonPressed) {
        if (grap->mouse.x >= grap->vect3.x &&
        grap->mouse.x <= grap->vect3.x + 293 &&
        grap->mouse.y >= grap->vect3.y &&
        grap->mouse.y <= grap->vect3.y + 100
        && grap->success == 0)
            sfRenderWindow_close(grap->window);
        if (grap->mouse.x >= grap->vect2.x &&
        grap->mouse.x <= grap->vect2.x + 301 &&
        grap->mouse.y >= grap->vect2.y &&
        grap->mouse.y <= grap->vect2.y + 100
        && grap->success == 0) {
            sfRenderWindow_close(grap->window);
            grap->success = 1;
        }
    }
}

void	    window_init(graphical *grap)
{
    if (grap->success == 0) {
        sfVideoMode mode1 = {1280, 720, 90};
        grap->window = sfRenderWindow_create(mode1,
        "JETPACK2TEK3", sfResize | sfClose, NULL);
    }
    if (grap->success == 1) {
        sfVideoMode mode2 = {1200, 900, 90};
        grap->window = sfRenderWindow_create(mode2,
        "JETPACK2TEK3", sfResize | sfClose, NULL);
    }
}

void	text_init(graphical *grap)
{
    grap->vect2.x = 490;
    grap->vect2.y = 80;
    grap->vect3.x = 490;
    grap->vect3.y = 620;
    sfSprite_setTexture(grap->sprite1, grap->textu1, sfTrue);
    sfSprite_setTexture(grap->sprite2, grap->textu2, sfTrue);
    sfSprite_setTexture(grap->sprite3, grap->textu3, sfTrue);
    sfSprite_setPosition(grap->sprite1, grap->vect1);
    sfSprite_setPosition(grap->sprite2, grap->vect2);
    sfSprite_setPosition(grap->sprite3, grap->vect3);
}

void	drawsprite(graphical *grap)
{
    sfRenderWindow_clear(grap->window, sfBlack);
    grap->mouse.x = sfMouse_getPositionRenderWindow(grap->window).x;
    grap->mouse.y = sfMouse_getPositionRenderWindow(grap->window).y;
    if (grap->success == 0) {
        sfRenderWindow_drawSprite(grap->window, grap->sprite1, NULL);
        sfRenderWindow_drawSprite(grap->window, grap->sprite2, NULL);
        sfRenderWindow_drawSprite(grap->window, grap->sprite3, NULL);
    }
}

void	init_graph(graphical *grap)
{
    grap->textu1 = sfTexture_createFromFile("sprites/oui.jpg", NULL);
    grap->textu2 = sfTexture_createFromFile("sprites/logo_play.png", NULL);
    grap->textu3 = sfTexture_createFromFile("sprites/logo_quit.png", NULL);
    grap->sprite1 = sfSprite_create();
    grap->sprite2 = sfSprite_create();
    grap->sprite3 = sfSprite_create();
}