/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef PICTURE_HPP_
	#define PICTURE_HPP_

#include <string>
#include <iostream>
#include <fstream>

class Picture {
	public:
        Picture();
		Picture(const std::string &file);
		~Picture();
        std::string data;
        bool getPictureFromFile(const std::string &file);
	protected:
	private:
};

#endif /* !PICTURE_HPP_ */