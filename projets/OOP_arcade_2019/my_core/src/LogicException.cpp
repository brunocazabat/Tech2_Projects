/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "../include/LogicException.hpp"

Arcade::LogicException::LogicException(const std::string &message) : exception(), message(message)
{

}

Arcade::LogicException::~LogicException()
{
}

const std::string &Arcade::LogicException::what()
{
	return this->message;
}