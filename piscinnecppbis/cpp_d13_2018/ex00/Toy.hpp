/*
** EPITECH PROJECT, 2019
** toy
** File description:
** toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include "Picture.hpp"

class Toy {
	public:
		Toy();
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
		Toy(ToyType type, const std::string &name, const std::string &file);
		~Toy();
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        std::string getAscii() const;
        bool setAscii(const std::string &file);

	protected:
	private:
        ToyType _type;
        std::string _name;
        Picture *_picture;
};

#endif /* !TOY_HPP_ */
