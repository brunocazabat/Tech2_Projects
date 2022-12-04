/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef oui
#define oui

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Arcade {
    public :
        Arcade();
        ~Arcade();
    private :
};

typedef struct Graphical_s
{
	std::string key_quitarcade;
	std::string key_menu;
	std::string key_nextgraphlib;
    std::string key_previousgraphlib;
    std::string key_nextgame;
    std::string key_previousgame;
    std::string key_restartarcade;
    std::string text;
    std::string visual;
    char key_quit;
    bool firstuse;
    int max_score;
    int posit_verti;
    int posit_horiz;
    int score;

}   Graphical_t;

#endif /* !oui */
