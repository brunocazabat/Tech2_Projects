/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef GRAPHICAL_HPP_
	#define GRAPHICAL_HPP_

#include <cstring>
#include <iostream>
#include <string>

class Graphical {
	public:
		Graphical();
		~Graphical();

	protected:
	private:
};

typedef struct Graphical_s
{
	char key_quit;
	std::string HOSTNAME;
	std::string OS;
	std::string time;

}   Graphical_t;

int text_init(Graphical_t *data);
int graphical_init();
void help_exec();
#endif /* !GRAPHICAL_HPP_ */
