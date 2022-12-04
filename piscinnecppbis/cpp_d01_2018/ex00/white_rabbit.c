/*
** EPITECH PROJECT, 2019
** 00
** File description:
** 00
*/

#include <stdio.h>
#include <stdlib.h>

int follow_the_white_rabbit(void)
{
    int dice = (random() % 37) + 1;
    static int result = 0;

    if ((dice >= 4 && dice <= 6) || (dice >= 17 && dice <= 21) || dice == 28) {
        printf("left\n");
    } else if (dice == 13 || (dice >= 34 && dice <= 36)) {
        printf("right\n");
    } else if (dice == 10 || dice == 15 || dice == 23) {
        printf("forward\n");
    } else if (dice == 26 || dice % 8 == 0) {
        printf("backward\n");
    }
    result += dice;
    if (dice == 1 || dice == 37 || result >= 387) {
        printf("RABBIT!!!\n");
        return (result);
    }
    follow_the_white_rabbit();
    return (result);
}