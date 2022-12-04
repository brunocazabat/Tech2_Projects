/*
** EPITECH PROJECT, 2019
** Box.cpp
** File description:
** Box
*/

#include "Box.hpp"

Box::Box() : Wrap()
{
    this->_title = "Box";
    this->_isOpen = false;
    this->_typeObj = BOX;
    this->_isEmpty = true;
    this->_obj = NULL;
    std::cout << "Wrap " << this->getTitle() << " created successfuly" << std::endl;
}

void Box::closeMe() {
    this->_isOpen = false;
}

void Box::wrapMeThat(Object *obj) {
    if (this->_isOpen == false) {
        std::cerr << "You can't wrap a Closed Box !" << std::endl;
    } else if (this->_isEmpty == false) {
        std::cerr << "You can't wrap a Box that is not empty !" << std::endl;
    } else {
        this->_obj = obj;
        this->_isEmpty = false;
        std::cout << "tuuuut tuuut tuut" << std::endl;
    }
}

Object *Box::openMe() {
    if (this->_taken) {
        this->_isOpen = true;
        return (this->_obj);
    } else {
        std::cerr << "You can't open the Box if you don't have already take the box!" << std::endl;
        return (0);
    }
}