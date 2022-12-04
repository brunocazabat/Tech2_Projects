/*
** EPITECH PROJECT, 2019
** broadcast
** File description:
** broadcast
*/

#include "../include/server.h"

static const orientation_t ORIENTATIONS[] = {
	{ UP, 2, 1, 8, 4, 5, 6, 3, 7 },
	{ RIGHT, 4, 3, 2, 6, 7, 8, 5, 1 },
	{ DOWN, 6, 5, 4, 8, 1, 2, 7, 3 },
	{ LEFT, 8, 7, 6, 2, 3, 4, 1, 5 },
	{ NO_DIR, 0, 0, 0, 0, 0, 0, 0, 0 }
};

t_vector calc_k(t_player *src, t_player *dest, t_option *opt)
{
    int x = dest->x - src->x;
    int y = dest->y - src->y;
    int i = opt->x - (x < 0 ? -x : x);
    int j = opt->y - (y < 0 ? -y : y);
    int x1 = (src->x < dest->x) ? 1 : (src->x > dest->x) ? -1 :0;
    int y1 = (src->y < dest->y) ? 1 : (src->y > dest->y) ? -1 :0;
    t_vector dist;

    if ((i < 0 ? -i : i) < (x < 0 ? -x : x))
        x1 = x1 * -1;
    if ((j < 0 ? -j : j) < (y < 0 ? -y : y))
        y1 = y1 * -1;
    dist.x = x1;
    dist.y = y1;
    return (dist);
}

int get_real_dir(int orientation, int dir)
{
    int i = -1;
    while (ORIENTATIONS[++i].dir != dir);
	switch (orientation) {
		case (11):
			return (ORIENTATIONS[i].up_left);
		case (21):
			return (ORIENTATIONS[i].down_left);
		case (31):
			return (ORIENTATIONS[i].center_left);
		case (12):
			return (ORIENTATIONS[i].up_right);
		case (22):
			return (ORIENTATIONS[i].down_right);
		case (32):
			return (ORIENTATIONS[i].center_right);
		case (13):
			return (ORIENTATIONS[i].up_center);
		case (23):
			return (ORIENTATIONS[i].down_center);
		default:
			return (0);
	}
}

int get_dir(t_option *opt, t_player *from, t_player *to)
{
    t_vector dist = calc_k(from, to, opt);
    int tile_from = 0;

    if (from->x == to->x && from->y == to->y)
        return (0);
    tile_from += (dist.x == 1) ? 1 : (dist.x == -1) ? 2:3;
    tile_from += (dist.y == 1) ? 10 : (dist.y == -1) ? 20:30;
    return(get_real_dir(tile_from, to->direction));
}

void broadcast(t_player *p, t_case **map, char *buffer, t_team *team, t_option *options)
{
    char buf[4096];
    char *tmp = buf;
    int dir = 0;

    for (int i = 0;i < 8; i++) {
        for (int j = 0;j < team[i].len_team; j++) {
            if (team[i].player[j].sd != p->sd) {
                dir = get_dir(options, p, &team[i].player[j]);
                sprintf(tmp, "message %d, %s\n", dir, buffer);
			    send_message(team[i].player[j].sd, strdup(buf));
            }
        }
    }
}