/*
** EPITECH PROJECT, 2019
** error
** File description:
** error
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) : _component(component), _message(message)
{
}

const std::string &NasaError::getComponent() const
{
    return (_component);
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
}

std::string const CommunicationError::getComponent() const
{
    return ("CommunicationDevice");
}
