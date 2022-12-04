/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "../include/include.h"

/*
void            map_local(graphical *grap)
{
    int pix_lar = 1200 / grap->map_width;
    int pix_hau = 900 / grap->map_height;

    printf("La largeur d'une texture : %d\n", pix_lar);
    printf("La hauteur d'une texture : %d\n", pix_hau);

    printf("Le nombre de texture en largeur : %d\n", grap->map_width);
    printf("Le nombre de texture en hauteur : %d\n", grap->map_height);

}
*/

void            launchgame(graphical *grap)
{
    sfEvent	event;

    window_init(grap);
    text_init(grap);
    //sendcmd_fireon(grap);

    while (sfRenderWindow_isOpen(grap->window)) {
        drawsprite(grap);
        //map_local(grap);
        while (sfRenderWindow_pollEvent(grap->window, &event))
            quit_game(grap, event);
        sfRenderWindow_display(grap->window);
    }
}