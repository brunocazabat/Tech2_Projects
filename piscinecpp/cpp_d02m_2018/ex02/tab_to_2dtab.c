/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **new_tab = malloc(sizeof(int *) * (length + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < length) {
        new_tab[i] = malloc(sizeof(int) * (width + 1));
        i++;
    }
    i = 0;
    while (i < length) {
        while (j < width) {
            new_tab[i][j] = tab[k];
            j++;
            k++;
        }
        i++;
        j = 0;
    }
    *res = new_tab;
}
