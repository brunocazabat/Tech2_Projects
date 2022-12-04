/*
** EPITECH PROJECT, 2019
** food
** File description:
** food
*/
#include "../include/server.h"

void handle_food(t_team *team, t_option *opt)
{
    int i = 0;
    int j = 0;
    int k = 1;
    double elapsed;

    while (team[i].name != NULL) {
        while (j < team[i].len_team) {
            elapsed = (double)(clock() - team[i].player[j].food) / CLOCKS_PER_SEC;
            if (elapsed >= ((double)1 / (double)opt->f)) {
                team[i].player[j].time_death--;
                team[i].player[j].food = clock();
            }
            if (team[i].player[j].time_death < 126 && team[i].player[j].iventory.food > 0) {
                team[i].player[j].time_death+=126;
                team[i].player[j].iventory.food -= 1;
            } else if (team[i].player[j].time_death <= 0){
                send_message(team[i].player[j].sd, _dead);
                printf("Host dead\n");
                close(team[i].player[j].sd);
            }
            j++;
        }
        i++;
    }
}