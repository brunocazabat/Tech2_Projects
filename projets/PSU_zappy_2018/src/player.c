#include "../include/server.h"

t_player *get_player(int sd, t_team *team)
{
    int i = 0;
    int j = 0;

    while (team[i].name != NULL) {
        while (j < team[i].len_team) {
            if (team[i].player[j].sd == sd) 
                return (&team[i].player[j]);
            j++;
        }
        j = 0;
        i++;
    }
    return (NULL);
}

t_team *get_team(int sd, t_team *team)
{
    int i = 0;
    int j = 0;

    while (team[i].name != NULL) {
        while (j < team[i].len_team) {
            if (team[i].player[j].sd == sd) 
                return (&team[i]);
            j++;
        }
        j = 0;
        i++;
    }
    return (NULL);
}