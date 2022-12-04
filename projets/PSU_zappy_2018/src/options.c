#include "../include/server.h"

bool show_option(t_option *const option)
{
    size_t i;

    if (option == NULL)
        return (true);
    printf("port : %s\n", option->p);
    printf("x : %i\n", option->x);
    printf("y : %i\n", option->y);
    printf("population : %i\n", option->c);
    printf("t : %i\n", option->f);
    if (option->team != NULL)
    {
        for (i = 0; option->team[i] != NULL; i++)
            printf("team = %lu : %s\n", i, option->team[i]);
        if (option->n != NULL)
            printf("team = %lu : %s\n", i, option->n);
    }
    return (false);
}


static t_option *init_option(t_option *const option)
{
    static char *team[] = {"team1", "team2", NULL};

    if (option == NULL)
        return (NULL);
    option->p = "4242";
    option->n = NULL;
    option->x = 42;
    option->y = 42;
    option->c = 1;
    option->g = false;
    option->f = 100;
    option->team = team;
    return (option);
}


static bool set_option(t_option *const option, char **argv,
                       int const c)
{
    if (c == 'p')
        option->p = optarg;
    else if (c == 'n') {
        option->n = optarg;
    }
    else if (c == 'g')
        option->g = true;
    else if (c == 'x')
        option->x = atoi(optarg);
    else if (c == 'y')
        option->y = atoi(optarg);
    else if (c == 'c')
/*        if ((option->c = strtoul(optarg, NULL, 10)) > MAX_CLIENTS)
            option->c = MAX_CLIENTS;*/
        option->c = atoi(optarg);
    else if (c == 'f')
        option->f = atoi(optarg);
    else if (c == 'h') {
        fprintf(stderr, "%s: [-p 4242] [-x 30] [-y 30] [-c 6] "
                        "[-n team1 team2 etc] [-f 100]\n",
                *argv);
        exit(84);
    }
    else
        return (true);
    return (false);
}

bool get_option(t_option *const option, char **argv, int const argc)
{
    int c;
    bool ret;

    if (option == NULL || argv == NULL)
        return (true);
    ret = false;
    init_option(option);
    while ((c = getopt(argc, argv, "ghp:x:y:c:n:f:")) != -1)
        if (set_option(option, argv, c) == true)
            ret = true;
    if (argv[optind] != NULL || option->n != NULL)
        option->team = argv + optind;
    return (ret);
}
