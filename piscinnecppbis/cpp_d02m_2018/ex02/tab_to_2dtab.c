/*
** EPITECH PROJECT, 2019
** 02
** File description:
** 02
*/

#include <stdlib.h>
#include <stdio.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **new_tab;
    int i = -1;
    int j = 0;
    int k = 0;

    new_tab = malloc(sizeof(int*) * length);
    while (++i < length)
        new_tab[i] = malloc(sizeof(int) * width);

    while (j < length) {
        while (k < width) {
            new_tab[j][k] = *tab++;
            k++;
        }
        j++;
        k = 0;
    }
    *res = new_tab;
}