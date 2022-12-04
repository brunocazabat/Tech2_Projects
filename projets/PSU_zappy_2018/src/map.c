#include "../include/server.h"

int generate_random()
{
    int rd = rand() % 100;
    if (rd >= 20)
        return (0);
    else
        return (1);
}

void print_map(t_case **map, int x, int y)
{
        for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) { 
            printf("[%i", map[i][j].linemate);
            printf("%i", map[i][j].deraumere);
            printf("%i", map[i][j].sibur);
            printf("%i", map[i][j].mendiane);
            printf("%i", map[i][j].phiras);
            printf("%i", map[i][j].thystame);
            printf("%i]", map[i][j].food);
        }
        printf("\n");
    }
}

t_case **fill_map(t_case **map, int x, int y)
{
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            map[i][j].linemate = generate_random();
            map[i][j].deraumere = generate_random();
            map[i][j].sibur = generate_random();
            map[i][j].mendiane = generate_random();
            map[i][j].phiras = generate_random();
            map[i][j].thystame = generate_random();
            map[i][j].food = generate_random();
            map[i][j].player = malloc(sizeof(int) * 10);
            for (int k = 0; k < 10; k++)
                map[i][j].player[k] = -1;
            map[i][j].egg = malloc(sizeof(int) * 10);
            for (int k = 0; k < 10; k++)
                map[i][j].egg[k] = -1;
        }
    }
    return (map);
}

t_case **init_map(int x, int y)
{
    int i = 0;
    t_case **map;

    map = malloc(sizeof(t_case) * y + 1);
    while (i < x + 1) {
        map[i] = malloc(sizeof(t_case) * x + 1);
        i++;
    }
    map[i] = NULL;
    map = fill_map(map, x, y);
    return (map);
}