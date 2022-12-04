/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <exception>
#include <string>

namespace Arcade {
	class LogicException : public std::exception {
	public:
		explicit LogicException(const std::string &message);
		~LogicException();
		const std::string &what();

	private:
		std::string message;
	};
}
