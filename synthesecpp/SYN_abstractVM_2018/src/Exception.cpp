/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Exception
*/

#include "../include/Exception.hpp"

Exception::Exception(const std::string &msg) throw()
{
  this->_msg = msg;
}

Exception::~Exception() throw()
{
}

const char* Exception::what() const throw()
{
  return (this->_msg.c_str());
}