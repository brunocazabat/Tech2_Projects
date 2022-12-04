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
        Toy(const Toy &toy);
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        const Toy &operator=(const Toy &copy);
		Toy(ToyType type, const std::string &name, const std::string &file);
		~Toy();
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string &name);
        std::string getAscii() const;
        bool setAscii(const std::string &file);

	protected:
        ToyType _type;
        std::string _name;
        Picture *_picture;
	private:
};

#endif /* !TOY_HPP_ */
