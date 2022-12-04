#include "../include/server.h"

char *create_map(t_team *team, t_case **map, t_option options)
{
    char buf[4096 * 8];
    char *tmp = buf;

    for (int i = 0; i < options.x; i++) {
        for (int j = 0; j < options.y; j++) { 
            tmp += sprintf(tmp, "%i,", map[i][j].linemate);
            tmp += sprintf(tmp, "%i,", map[i][j].deraumere);
            tmp += sprintf(tmp, "%i,", map[i][j].sibur);
            tmp += sprintf(tmp, "%i,", map[i][j].mendiane);
            tmp += sprintf(tmp, "%i,", map[i][j].phiras);
            tmp += sprintf(tmp, "%i,", map[i][j].thystame);
            tmp += sprintf(tmp, "%i[", map[i][j].food);
            for (int k = 0; map[i][j].player[k] != -1; k++) {
                tmp += sprintf(tmp, "P:%i", map[i][j].player[k]);
                tmp += sprintf(tmp, ":%s", get_team(map[i][j].player[k], team)->name);
                tmp += sprintf(tmp, ":%i", get_team(map[i][j].player[k], team)->player[k].direction);
                tmp += sprintf(tmp, ":%i", get_team(map[i][j].player[k], team)->player[k].direction);
            }
            tmp += sprintf(tmp, "];");
       }
    }
    return (strdup(buf));
}

char *create_msg(t_case **map, t_team *team, t_option options)
{
    char buf[4096 * 8];
    char *tmp = buf;
    char *map_msg = create_map(team, map, options);

    static int test = 0;
    tmp += sprintf(tmp, "(%i,%i)", options.x, options.y);
    tmp += sprintf(tmp, "%s", map_msg);
    free(map_msg);
    return (strdup(buf));
}