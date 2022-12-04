/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>
#include <exception>

class	Exception : public std::exception
{
    std::string	_msg;
    public:
    Exception (std::string const &msg) throw();
    virtual ~Exception() throw();
    virtual const char* what() const throw();
};

#endif /* !EXCEPTION_HPP_ */
