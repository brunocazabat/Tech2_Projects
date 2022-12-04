/*
** EPITECH PROJECT, 2019
** picture
** File description:
** picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <string>
#include <iostream>
#include <fstream>

class Picture {
	public:
        Picture(const std::string &file = "");
		~Picture() {};
        bool getPictureFromFile(const std::string &file);
        std::string data;

	protected:
	private:
};

#endif /* !PICTURE_HPP_ */
