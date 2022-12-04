/**
    Handle multiple socket connections with select and fd_set on Linux
*/
#include "../include/server.h"

#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 8


int stock_team(t_team *team, char *name, t_option options, int sd, t_case **map)
{
    int i = 0;
    int j = 0;
    char str[6];
    char str2[2];
    int k = 0;
    static int init_team = 0;

    name[strlen(name) - 1] = '\0';

    if (init_team == 0) {
    while (team[i].name != NULL) {
        team[i].player = malloc(sizeof(t_player) * 10 + 1);
        team[i].len_team = 0;
        i++;
    }
    i = 0;
            while (i < MAX_CLIENTS) {
            i++;
        }
    init_team++;
    }

    i = 0;

    while (team[i].name != NULL/* i < 8*/ ) {
        if (strcmp(team[i].name, name) == 0) {
            team[i].len_team += 1;
            team[i].player[team[i].len_team - 1].sd = sd;
            team[i].player[team[i].len_team - 1].x = rand() % options.x;
            team[i].player[team[i].len_team - 1].y = rand() % options.y;
            while (map[team[i].player[team[i].len_team - 1].y][team[i].player[team[i].len_team - 1].x].player[0] != -1)
                k++;
            map[team[i].player[team[i].len_team - 1].y][team[i].player[team[i].len_team - 1].x].player[k] = sd;
            team[i].player[team[i].len_team - 1].direction = UP;
            team[i].player[team[i].len_team - 1].iventory.deraumere = 0;
            team[i].player[team[i].len_team - 1].iventory.food = 9;
            team[i].player[team[i].len_team - 1].iventory.linemate = 0;
            team[i].player[team[i].len_team - 1].iventory.mendiane = 0;
            team[i].player[team[i].len_team - 1].iventory.phiras = 0;
            team[i].player[team[i].len_team - 1].iventory.sibur = 0;
            team[i].player[team[i].len_team - 1].iventory.thystame = 0;
            team[i].player[team[i].len_team - 1].lvl = 1;
            team[i].player[team[i].len_team - 1].cmds = NULL;
            team[i].player[team[i].len_team - 1].time_remain = 0;
            team[i].player[team[i].len_team - 1].food = clock();
            team[i].player[team[i].len_team - 1].time_death = 126;
            team[i].player[team[i].len_team - 1].start = 0;
            sprintf(str2, "%d\n", (options.c - team[i].len_team));
            send_message(sd, str2);
            sprintf(str, "%d %d\n", options.x, options.y);
            send_message(sd, str);
            return (1);
        }
        i++;
    }
    return (0);
}

int init_socket(struct sockaddr_in *address, t_option *options, struct timeval *tv)
{
    int opt = TRUE;
    int master_socket;

    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(atoi(options->p));
    tv->tv_sec = 2;
    tv->tv_usec = 0;
    return (master_socket);
}

/* void init_data(t_option *options, t_team **team, int (*client_socket)[MAX_CLIENTS], int (*state)[MAX_CLIENTS])
{
    int i = 0;

}*/

int send_message(int sd, char *msg)
{
    return (send(sd, msg, strlen(msg), 0));
}

int main(int argc, char *argv[])
{
    int master_socket, addrlen, new_socket, activity, i, valread, sd;
    int max_sd;
    int client_socket[MAX_CLIENTS];
    int state[MAX_CLIENTS];
    struct sockaddr_in address;
    struct timeval tv;
    char buffer[1025]; //data buffer of 1K
    t_team *team;
    t_case **map;

    srand(time(NULL));

    t_option options;
    get_option(&options, argv, argc);
    show_option(&options);

    map = init_map(options.y, options.x);

    print_map(map, options.y, options.x);

    team = malloc(sizeof(t_team) * 5 + 1);
    master_socket = init_socket(&address, &options, &tv);

    fd_set readfds;

    //init_data(&options, &team, &client_socket, &state);

    for (i = 0; i < MAX_CLIENTS; i++)
    {
        client_socket[i] = 0;
        state[i] = 0;
    }

    for (i = 0; options.team[i] != NULL; i++)
        team[i].name = options.team[i];
    if (options.n != NULL)
        team[i].name = options.n;
    i++;
    team[i].name = NULL;
    //bind the socket to localhost port 8888
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", atoi(options.p));

    //try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 8) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //accept the incoming connection
    addrlen = sizeof(address);
    printf("Waiting for connections ...\n");

    while (TRUE)
    {
        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        //add child sockets to set
        for (i = 0; i < MAX_CLIENTS; i++)
        {
            //socket descriptor
            sd = client_socket[i];

            //if valid socket descriptor then add to read list
            if (sd > 0)
                FD_SET(sd, &readfds);

            //highest file descriptor number, need it for the select function
            if (sd > max_sd)
                max_sd = sd;
        }

        //wait for an activity on one of the sockets , timeout is 2 seconds, so continue in loop if nothing seen in 2 seconds.
        activity = select(max_sd + 1, &readfds, NULL, NULL, &tv);

        if ((activity < 0) && (errno != EINTR))
        {
            printf("select error");
        }

        //If something happened on the master socket , then its an incoming connection
        if (FD_ISSET(master_socket, &readfds))
        {
            if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform user of socket number - used in send and receive commands
            printf("New connection , socket fd is %d , ip is : %s , port : %d \n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            if (send_message(new_socket, _message) == -1)
            {
                perror("send");
            }


            //add new socket to array of sockets
            for (i = 0; i < MAX_CLIENTS; i++)
            {
                //if position is empty
                if (client_socket[i] == 0)
                {
                    client_socket[i] = new_socket;
                    printf("Adding to list of sockets as %d\n", i);

                    break;
                }
            }
        }

        //else its some IO operation on some other socket :)
        for (i = 0; i < MAX_CLIENTS; i++)
        {
            sd = client_socket[i];

            if (FD_ISSET(sd, &readfds))
            {
                //Check if it was for closing , and also read the incoming message
                if ((valread = read(sd, buffer, 1024)) == 0)
                {
                    //Somebody disconnected , get client details and print
                    getpeername(sd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
                    printf("Host disconnected , ip %s , port %d \n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

                    //Close the socket and mark as 0 in list for reuse
                    close(sd);
                    state[i] = 0;
                    client_socket[i] = 0;
                }

                //Echo back the message that came in
                else
                {
                    buffer[valread] = '\0';
                    //printf("dzq\n");
                if (strcmp(buffer, "Graph\n") == 0)
                      send_message(sd, create_msg(map, team, options));
                else {
                    if (state[i] == 0) {
                        if (stock_team(team, buffer, options, sd, map)) {
                            state[i]++;
                        }
                        else
                            send_message(sd, _ko);
                    }
                    else
                        stock_move(sd, buffer, team);
                        //cmd(sd, team, buffer, map, &options);
                }
                }
            }
            //send_message(sd, create_msg(map, team, options));
        }
//            sleep(1/options.f);
        //handle_move(client_socket, team, map, &options);
        //handle_food(team, &options);
    }
    return 0;
}