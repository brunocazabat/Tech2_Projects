/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

#include "Picture.hpp"
#include <string>
#include <iostream>
#include <fstream>

class Toy {
	public:
    enum ToyType {
            BASIC_TOY, ALIEN, BUZZ, WOODY
        };
		Toy();
        Toy(Toy &toy);
        Toy(ToyType type, std::string name, std::string file);
		~Toy();
        void	    speak(std::string statement);
        ToyType     type;
        std::string	name;
        Picture	    picture;
        ToyType     getType() const;
        std::string	getName() const;
        std::string getAscii() const;
        void		 setName(std::string const name);
        bool		setAscii(std::string const data);
        Toy		&operator <<(std::string const &data);
};

std::ostream &operator <<(std::ostream &os, Toy &toy);


#endif /* !TOY_HPP_ */
