/*
** EPITECH PROJECT, 2019
** Parts
** File description:
** Parts
*/

#ifndef PARTS_HPP_
	#define PARTS_HPP_

#include <string>
#include <iostream>

class Arms {
	public:
		Arms(const std::string &serial = "A-01", bool functional = true);
		~Arms();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;

	protected:
	private:
        std::string _serial;
        bool _functional;
};

class Legs {
	public:
		Legs(const std::string &serial = "L-01", bool functional = true);
		~Legs();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;

	protected:
	private:
        std::string _serial;
        bool _functional;
};

class Head {
	public:
		Head(const std::string &serial = "H-01", bool functional = true);
		~Head();
        bool isFunctionnal() const;
        std::string serial() const;
        void informations() const;

	protected:
	private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */
