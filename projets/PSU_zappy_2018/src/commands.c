#include "../include/server.h"

void player_to_tile(t_case **map, t_player *p)
{
    int i = 0;

    while (map[p->y][p->x].player[i] > 0 || i > 9)
        i++;
    map[p->y][p->x].player[i] = p->sd;
}

void Forward(t_player *p, t_option *options, t_case **map)
{
    printf("direction %i\n", p->direction);
     for (int i = 0;map[p->y][p->x].player[i] >= 0;i++)
        if (map[p->y][p->x].player[i] == p->sd)
            map[p->y][p->x].player[i] = 0;
    switch (p->direction) {
        case DOWN:
            if (p->y - 1 < 0)
                p->y = options->y -1;
            else
                p->y -= 1;
            player_to_tile(map, p);
            break;
        case UP:
            if (p->y + 1 >= options->y)
                p->y = 0;
            else
                p->y += 1;
            player_to_tile(map, p);
            break;
        case LEFT:
            if (p->x - 1 < 0)
                p->x = options->x - 1;
            else
                p->x -= 1;
            player_to_tile(map, p);
            break;
        case RIGHT:
            if (p->x + 1 >= options->x)
                p->x = 0;
            else
                p->x += 1;
            player_to_tile(map, p);
            break;
    }
    printf("%i coordonées %i:%i\n", p->sd, p->x, p->y);
    
}

void Set(t_player *p, t_case **map, char *str)
{
    if (strcmp(str, "linemate") == 0) {
        if (p->iventory.linemate > 0) {
            p->iventory.linemate -= 1;
            map[p->y][p->x].linemate += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("sibur", str) == 0) {
        if (p->iventory.sibur > 0) {
            p->iventory.sibur -= 1;
            map[p->y][p->x].sibur += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("mendiane", str) == 0) {
        if (p->iventory.mendiane > 0) {
            p->iventory.mendiane -= 1;
            map[p->y][p->x].mendiane += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("phiras", str) == 0) {
        if (p->iventory.phiras > 0) {
            p->iventory.phiras -= 1;
            map[p->y][p->x].phiras += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("thystame", str) == 0) {
        if (p->iventory.thystame > 0) {
            p->iventory.thystame -= 1;
            map[p->y][p->x].thystame += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("deraumere", str) == 0) {
        if (p->iventory.deraumere > 0) {
            p->iventory.deraumere -= 1;
            map[p->y][p->x].deraumere += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp(str, "food") == 0) {
        if (p->iventory.food > 0) {
            p->iventory.food -= 1;
            map[p->y][p->x].food += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else
        send_message(p->sd, _ko);
    
}

void Take(t_player *p, t_case **map, char *str)
{
    if (strcmp(str, "linemate") == 0) {
        if (map[p->y][p->x].linemate > 0) {
            map[p->y][p->x].linemate -= 1;
            p->iventory.linemate += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);  
    } else if (strcmp("sibur", str) == 0) {
        if (map[p->y][p->x].sibur > 0) {
            map[p->y][p->x].sibur -= 1;
            p->iventory.sibur += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("mendiane", str) == 0) {
        if (map[p->y][p->x].mendiane > 0) {
            map[p->y][p->x].mendiane -= 1;
            p->iventory.mendiane += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("phiras", str) == 0) {
        if (map[p->y][p->x].phiras > 0) {
            map[p->y][p->x].phiras -= 1;
            p->iventory.phiras += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("thystame", str) == 0) {
        if (map[p->y][p->x].thystame > 0) {
            map[p->y][p->x].thystame -= 1;
            p->iventory.thystame += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp("deraumere", str) == 0) {
        if (map[p->y][p->x].deraumere > 0) {
            map[p->y][p->x].deraumere -= 1;
            p->iventory.deraumere += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else if (strcmp(str, "food") == 0) {
        if (map[p->y][p->x].food > 0) {
            map[p->y][p->x].food -= 1;
            p->iventory.food += 1;
            send_message(p->sd, _ok);
        } else
            send_message(p->sd, _ko);
    } else
        send_message(p->sd, _ko);
}

void right(t_player *p)
{
    if (p->direction == 3)
        p->direction = 0;
    else
        p->direction += 1;
}

void left(t_player *p)
{
    if (p->direction == 0)
        p->direction = 3;
    else
        p->direction -= 1;
}

void inventory(t_player *p)
{
    char *str = malloc(sizeof(char) * 83);

    memset(str, '\0', 83);
    sprintf(str, "[linemate %i, sibur %i, deraumere %i, mendiane %i, phiras %i, thystame %i, food %i]\n", p->iventory.linemate, p->iventory.sibur, p->iventory.deraumere, p->iventory.mendiane, p->iventory.phiras, p->iventory.thystame, p->iventory.food);
    send_message(p->sd, str);
}

int connect_nbr(t_team *team, t_player *p, t_option *options)
{
    int i = 0;
    int j = 0;
    char *msg = malloc(sizeof(char) * 10);

    memset(msg, '\0', 10);
    while (team[i].name != NULL) {
        while (&team[i].player[j] != NULL) {
            if (team[i].player[j].sd == p->sd) {
                sprintf(msg, "%i\n", options->c - team[i].len_team);
                send_message(p->sd, msg);
                free(msg);
                return (0);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

/*void eject(t_player *p, t_team *team, t_case **map)
{
    
}

*/



int cmd(int sd, t_team *team,  char *str, t_case **map, t_option *options)
{
    char *buffer = malloc(sizeof(char) * 20);
    memset(buffer, '\0', 20);
    char *buf = malloc(sizeof(char) * 20);
    memset(buf, '\0', 20);
    str[strlen(str) - 1] = '\0';

    t_player *p = get_player(sd, team);

    printf("%s", str);
    if(strcmp(str, "Forward") == 0) {
        Forward(p, options, map);
        send_message(sd, _ok);
    } else if(strncmp("Take", str, 4) == 0) {
        sscanf(str, "%s %s", buf, buffer);
        Take(p, map, buffer);
        free(buf);
        free(buffer);
    } else if(strcmp("Right", str) == 0) {
        right(p);
        send_message(sd, _ok);
    } else if(strcmp("Left", str) == 0) {
        left(p);
        send_message(sd, _ok);
    } else if(strcmp("Inventory", str) == 0) {
        inventory(p);
        send_message(sd, _ok);
    } else if(strncmp("Set", str, 3) == 0) {
        sscanf(str, "%s %s", buf, buffer);
        Set(p, map, buffer);
        free(buf);
        free(buffer);
    } else if(strncmp("Broadcast", str, 9) == 0) {
        printf("broadcast\n");
        sscanf(str, "%s %s", buf, buffer);
        broadcast(p, map, buffer, team, options);
        free(buf);
        free(buffer);
        send_message(sd, _ok);
    } else if(strcmp("Connect_nbr", str) == 0) {
        connect_nbr(team, p, options);
    } /*else if(strcmp("Eject", str) == 0) {
        eject(p, team, map);
    } */
    else if(strcmp("Incantation", str) == 0) {
        send_message(sd, _ko);
    } else if(strcmp("Fork", str) == 0) {
        send_message(sd, _ko);
    } else if(strcmp("Look", str) == 0) {
        look_cmd(map, p, options);
        send_message(sd, _ok);
    } else
        send_message(sd, _ko);
}