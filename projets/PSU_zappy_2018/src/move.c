/*
** EPITECH PROJECT, 2019
** move
** File description:
** move
*/

#include "../include/server.h"

int check_cmd(char *buffer)
{
    if(strcmp(buffer, "Forward\n") == 0) {
        return (7);
    } else if(strncmp("Take", buffer, 4) == 0) {
        return (7);
    } else if(strcmp("Right\n", buffer) == 0) {
        return (7);
    } else if(strcmp("Left\n", buffer) == 0) {
        return (7);
    } else if(strcmp("Inventory\n", buffer) == 0) {
        return (1);
    } else if(strncmp("Set", buffer, 3) == 0) {
        return (7);
    } else if(strncmp("Broadcast", buffer, 9) == 0) {
        return (7);
    } else if(strcmp("Connect_nbr\n", buffer) == 0) {
        return (0);
    } else if(strcmp("Fork\n", buffer) == 0) {
        return (42);
    } else if(strcmp("Eject\n", buffer) == 0) {
        return (7);
    } else if(strcmp("Incantation\n", buffer) == 0) {
        return (300);
    } else if(strcmp("Look\n", buffer) == 0) {
        return (7);
    } else
        return (-1);
}

int handle_move(int *client_socket, t_team *team, t_case **map, t_option *opt)
{
    int i = 0;
    int j = 0;
    int k = 0;
    double elapsed;
    t_player *p;
    t_cmds *tmp;

    while (team[i].name != NULL) {
        while (j < team[i].len_team) {
            p = get_player(team[i].player[j].sd, team);
            if (p->cmds != NULL) {
                elapsed  = (double)(clock() - p->start) / CLOCKS_PER_SEC;
                //printf("%f, %f\n", elapsed, ((double)p->time_remain / (double)opt->f));
                if (check_cmd(p->cmds->cmd) == -1) {
                    send_message(p->sd, _ko);
                    if (p->cmds->next != NULL) {
                        tmp = p->cmds;
                        p->cmds = p->cmds->next;
                        p->time_remain = ((k = check_cmd(p->cmds->cmd)) == -1) ? 0: k;
                        p->start = clock();
                    } else
                        p->cmds = NULL;
                } else if (elapsed >= ((double)p->time_remain / (double)opt->f)) {
                    cmd(p->sd, team, p->cmds->cmd, map, opt);
                    tmp = p->cmds;
                    if (p->cmds->next != NULL) {
                        p->cmds = p->cmds->next;
                        p->time_remain = ((k = check_cmd(p->cmds->cmd)) == -1) ? 0: k;
                        p->start = clock();
                    } else
                        p->cmds = NULL;              
                    free(tmp);
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
    return(1);
}

t_cmds *create_cmd(char *buffer)
{
    t_cmds *cmd = malloc(sizeof(t_cmds));

    cmd->cmd = strdup(buffer);
    cmd->next = NULL;
    return (cmd);
}

int stock_move(int sd, char *buffer, t_team *team)
{
    t_player *p = get_player(sd, team);
    t_cmds *tmp;
    int i = check_cmd(buffer);

//    if ((i = check_cmd(buffer)) == -1) {
    if (p->cmds == NULL) {
        p->cmds = create_cmd(buffer);
        p->start = clock();
        p->time_remain = i;
    } else {
        tmp = p->cmds;
        i = 0;
        while (tmp->next != NULL) {
            tmp = tmp->next;
            i++;
        }
        if (i > 10)
            return (0);
        else {
            tmp->next = create_cmd(buffer);
            return (1);
        }
    }
    return (1);
}