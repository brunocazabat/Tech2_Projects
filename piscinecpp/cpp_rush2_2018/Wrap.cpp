/*
** EPITECH PROJECT, 2019
** Wrap.cpp
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap()
{
    this->_obj = NULL;
    this->_isOpen = false;
}

bool Wrap::getOpen() {
    return (this->_isOpen);
}

bool Wrap::getEmpty() {
    return (this->_isEmpty);
}

Object *Wrap::getObject() {
    return (this->_obj);
}

void Wrap::isTaken() {
    std::cout << "whistles while working" << std::endl;
    this->_taken = true;
}