/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/


#include "lib_ncurses.hpp"
#include <ncurses.h>
#include <curses.h>

Arcade::Arcade()
{

}

Arcade::~Arcade()
{

}

static std::vector<std::string> LOGO_ARCADE = {
    "                  AAA                RRRRRRRRRRRRRRRRR            CCCCCCCCCCCCC                AAA                DDDDDDDDDDDDD         EEEEEEEEEEEEEEEEEEEEEE",
    "                 A:::A               R::::::::::::::::R        CCC::::::::::::C               A:::A               D::::::::::::DDD      E::::::::::::::::::::E",
    "                A:::::A              R::::::RRRRRR:::::R     CC:::::::::::::::C              A:::::A              D:::::::::::::::DD    E::::::::::::::::::::E",
    "               A:::::::A             RR:::::R     R:::::R   C:::::CCCCCCCC::::C             A:::::::A             DDD:::::DDDDD:::::D   EE::::::EEEEEEEEE::::E",
    "              A:::::::::A              R::::R     R:::::R  C:::::C       CCCCCC            A:::::::::A              D:::::D    D:::::D    E:::::E       EEEEEE",
    "             A:::::A:::::A             R::::R     R:::::R C:::::C                         A:::::A:::::A             D:::::D     D:::::D   E:::::E             ",
    "            A:::::A A:::::A            R::::RRRRRR:::::R  C:::::C                        A:::::A A:::::A            D:::::D     D:::::D   E::::::EEEEEEEEEE   ",
    "           A:::::A   A:::::A           R:::::::::::::RR   C:::::C                       A:::::A   A:::::A           D:::::D     D:::::D   E:::::::::::::::E   ",
    "          A:::::A     A:::::A          R::::RRRRRR:::::R  C:::::C                      A:::::A     A:::::A          D:::::D     D:::::D   E:::::::::::::::E   ",
    "         A:::::AAAAAAAAA:::::A         R::::R     R:::::R C:::::C                     A:::::AAAAAAAAA:::::A         D:::::D     D:::::D   E::::::EEEEEEEEEE   ",
    "        A:::::::::::::::::::::A        R::::R     R:::::R C:::::C                    A:::::::::::::::::::::A        D:::::D     D:::::D   E:::::E             ",
    "       A:::::AAAAAAAAAAAAA:::::A       R::::R     R:::::R  C:::::C       CCCCCC     A:::::AAAAAAAAAAAAA:::::A       D:::::D    D:::::D    E:::::E       EEEEEE",
    "      A:::::A             A:::::A    RR:::::R     R:::::R   C:::::CCCCCCCC::::C    A:::::A             A:::::A    DDD:::::DDDDD:::::D   EE::::::EEEEEEEE:::::E",
    "     A:::::A               A:::::A   R::::::R     R:::::R    CC:::::::::::::::C   A:::::A               A:::::A   D:::::::::::::::DD    E::::::::::::::::::::E",
    "    A:::::A                 A:::::A  R::::::R     R:::::R      CCC::::::::::::C  A:::::A                 A:::::A  D::::::::::::DDD      E::::::::::::::::::::E",
    "   AAAAAAA                   AAAAAAA RRRRRRRR     RRRRRRR         CCCCCCCCCCCCC AAAAAAA                   AAAAAAA DDDDDDDDDDDDD         EEEEEEEEEEEEEEEEEEEEEE"
};

static std::vector<std::string> MAP_PACMAN = {
    "##########################",
    "#........................#",
    "# # #### ######## #### # #",
    "# #....#....##....#....# #",
    "# #### # #..##..# # #### #",
    "# #......#..##..#......# #",
    "# #.###..#......#..###.# #",
    "# #.###..########..###.# #",
    "#........................#",
    "# ### #.####  ####.# ### #",
    "# #...#.#        #.#...# #",
    "# # ###.#        #.### # #",
    "# #..##.##########.##..# #",
    "#........................#",
    "####.####.######.####.####",
    ".....#......##......#.....",
    "#### #.###..##..###.# ####",
    "#........#......#........#",
    "# ###### #..##..# ###### #",
    "# #......#..##..#......# #",
    "# #.####....##....####.# #",
    "# #.####.########.####.# #",
    "#........................#",
    "##########################"
};

static std::vector<std::string> LOGO_PACMAN = {
"                           000000000000                                                        000000000000                              ",
"                       00000000000000000000                                                00000000000000000000                          ",
"                   0000000000000000000000000000                                        0000000000000000000000000000                      ",
"               000000000000000000000000000000000000                                000000000000000000000000000000000000                  ",
"             0000000000000000000000000000000000000000                            0000000000000000000000000000000000000000                ",
"           00000000000000000000  0000000000000000000000                        00000000000000000000  0000000000000000000000              ",
"          0000000000000000000      00000000000000000000                        000000000000000000      00000000000000000000              ",
"         0000000000000000000000  000000000000000000000000                          0000000000000000  000000000000000000000000            ",
"        00000000000000000000000000000000000000000000000000                           00000000000000000000000000000000000000000           ",
"              00000000000000000000000000000000000000000000                             0000000000000000000000000000000000000000          ",
"                     00000000000000000000000000000000000000                              000000000000000000000000000000000000000         ",
"                        000000000000000000000000000000000000                                0000000000000000000000000000000000000        ",
"                          0000000000000000000000000000000000                                  00000000000000000000000000000000000        ",
"                        0000000000000000000000000000000000000                               0000000000000000000000000000000000000        ",
"                    00000000000000000000000000000000000000000                            000000000000000000000000000000000000000         ",
"              0000000000000000000000000000000000000000000000                           0000000000000000000000000000000000000000          ",
"       0000000000000000000000000000000000000000000000000000                          000000000000000000000000000000000000000000          ",
"        00000000000000000000000000000000000000000000000000                         000000000000000000000000000000000000000000            ",
"         00000000000000000000000000000000000000000000000                         0000000000000000000000000000000000000000000             ",
"          000000000000000000000000000000000000000000000                        00000000000000000000000000000000000000000000              ",
"           0000000000000000000000000000000000000000000                         0000000000000000000000000000000000000000000               ",
"             0000000000000000000000000000000000000000                            0000000000000000000000000000000000000000                ",
"               000000000000000000000000000000000000                                000000000000000000000000000000000000                  ",
"                   0000000000000000000000000000                                        0000000000000000000000000000                      ",
"                       00000000000000000000                                                00000000000000000000                          ",
"                           000000000000                                                        000000000000                              "
};

void ascii_print(WINDOW *asciiart)
{
    int i = 0;
    while (i != 16) {
        mvwprintw(asciiart, i+2, 5, LOGO_ARCADE[i].c_str());
        i = i + 1;
    }
}

void key_print(WINDOW *keybind, Graphical_t *data)
{
    mvwprintw(keybind, 0, 3, "Voilà les touches");
    mvwprintw(keybind, 3, 3, "Quitter l'arcade : ");
    mvwprintw(keybind, 3, 39, data->key_quitarcade.c_str());
    mvwprintw(keybind, 6, 3, "Afficher le menu : ");
    mvwprintw(keybind, 6, 39, data->key_menu.c_str());
    mvwprintw(keybind, 9, 3, "Librairie graphique suivante : ");
    mvwprintw(keybind, 9, 39, data->key_nextgraphlib.c_str());
    mvwprintw(keybind, 12, 3, "Librairie graphique précedente : ");
    mvwprintw(keybind, 12, 40, data->key_previousgraphlib.c_str());
    mvwprintw(keybind, 15, 3, "Jeu suivant : ");
    mvwprintw(keybind, 15, 39, data->key_nextgame.c_str());
    mvwprintw(keybind, 18, 3, "Jeu précedent : ");
    mvwprintw(keybind, 18, 39, data->key_previousgame.c_str());
    mvwprintw(keybind, 21, 3, "Redemarrer l'arcade : ");
    mvwprintw(keybind, 21, 39, data->key_restartarcade.c_str());
}

void pacman_map_print(WINDOW *pacman)
{
    int i = 0;
    while (i != 24) {
        mvwprintw(pacman, i+1, 1, MAP_PACMAN[i].c_str());
        i = i + 1;
    }
}

void pacman_logo(WINDOW *ascii_art)
{
    int i = 0;
    while (i != 26) {
        mvwprintw(ascii_art, i+1, 1, LOGO_PACMAN[i].c_str());
        i = i + 1;
    }
}

void pacman_move(Graphical_t *data, int ch)
{
    if (data->max_score != 0) {
        MAP_PACMAN[data->posit_verti][data->posit_horiz] = '@';
        switch(ch)
        {
            case KEY_UP:
                if (MAP_PACMAN[data->posit_verti-1][data->posit_horiz] == '.') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_verti--;
                    data->score = data->score + 1;
                }
                if (MAP_PACMAN[data->posit_verti-1][data->posit_horiz] == ' ') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_verti--;
                }
                break;
            case KEY_DOWN:
                if (MAP_PACMAN[data->posit_verti+1][data->posit_horiz] == '.') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_verti++;
                    data->score = data->score + 1;
                }
                if (MAP_PACMAN[data->posit_verti+1][data->posit_horiz] == ' ') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_verti++;
                }
                break;
            case KEY_LEFT:
                if (MAP_PACMAN[data->posit_verti][data->posit_horiz-1] == '.') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_horiz--;
                    data->score = data->score + 1;
                }
                if (MAP_PACMAN[data->posit_verti][data->posit_horiz-1] == ' ') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_horiz--;
                }
                break;
            case KEY_RIGHT:
                if (MAP_PACMAN[data->posit_verti][data->posit_horiz+1] == '.') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_horiz++;
                    data->score = data->score + 1;
                }
                if (MAP_PACMAN[data->posit_verti][data->posit_horiz+1] == ' ') {
                    MAP_PACMAN[data->posit_verti][data->posit_horiz] = ' ';
                    data->posit_horiz++;
                }
                break;
        }
    }
}

void topscore_pacman(WINDOW *topscore, Graphical_t *data)
{
    std::stringstream score;
    std::stringstream max_score;
    score << data->score;
    max_score << data->max_score;
    std::string str1(score.str());
    std::string str2(max_score.str());
    mvwprintw(topscore, 0, 2, "Tableau des scores :");
    mvwprintw(topscore, 2, 3, "Score actuel : ");
    mvwprintw(topscore, 2, 20, str1.c_str());
    mvwprintw(topscore, 4, 3, "Score maximum : ");
    mvwprintw(topscore, 4, 20, str2.c_str());

}

int pacman(Graphical_t *data, int ch)
{
    WINDOW *pacman      = subwin(stdscr, 26, 28, 4, 10);
    WINDOW *ascii_art   = subwin(stdscr, 28, 140, 30, 98);
    WINDOW *topscore    = subwin(stdscr, 15, 30, 4, 50);

    start_color();
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(3));
    wborder(topscore, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, 0, 0, 0, 0);
    pacman_logo(ascii_art);
    topscore_pacman(topscore, data);
    pacman_map_print(pacman);
    pacman_move(data, ch);
    attroff(3);

    return (0);
}


int show_keys_text(Graphical_t *data)
{
    WINDOW *keybind = subwin(stdscr, 25, 50, 25, 90);
    WINDOW *asciiart = subwin(stdscr, 20, 170, 1, 32);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    wborder(asciiart, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_VLINE, 0, 0, 0, 0);
    wborder(keybind, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_VLINE, 0, 0, 0, 0);
    ascii_print(asciiart);
    key_print(keybind, data);
    attroff(1);
    
    return (0);
}

int text_start(Graphical_t *data)
{    
    int ch;
    initscr();
    curs_set(FALSE);
    cbreak();
    while (ch != 27) {
        if (!data->firstuse)
            show_keys_text(data);
        else
            pacman(data, ch);
        if (ch == 32)
            data->firstuse = 1;
        refresh();
        keypad(stdscr, TRUE);
	    timeout(100);
        ch = getch();
        clear();
    }
    endwin();
    return (0);
}

void init_struct(Graphical_t *data)
{
    data->firstuse = 0;
    data->key_menu = 'm';
    data->key_nextgame = 'p';
    data->key_previousgame = 'o';
    data->key_quitarcade = 'q';
    data->key_restartarcade = 'r';
    data->key_nextgraphlib = 'z';
    data->key_previousgraphlib = 'a';
    data->score = 0;
    data->max_score = 256;
    data->posit_verti = 22;
    data->posit_horiz = 12;

    data->text = "./lib_arcade_NCURSES.so";
    data->visual = "./lib_arcade_SFML.so";
}

extern "C"
{
    Arcade *make_arcade()
    {
		return new Arcade();
    }
}