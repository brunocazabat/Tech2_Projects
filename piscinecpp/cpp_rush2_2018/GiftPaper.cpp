/*
** EPITECH PROJECT, 2019
** GiftPaper.cpp
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap()
{
    this->_title = "Gift Paper";
    std::cout << "Wrap " << this->_title << " created with success!" << std::endl;
    this->_typeObj = GIFTPAPER;
}

void GiftPaper::wrapMeThat(Object *obj) {
    if (this->getEmpty() != false) {
        std::cerr << "GiftPaper is full of gift already ! You can't wrap a Box that is not empty !" << std::endl;
    } else if (this->getTaken() == true) {
        if (this->_obj == NULL) {
            this->_obj = obj;
            std::cout << "tuuuut tuuut tuut" << std::endl;
        } else {
            std::cerr << "GiftPaper is full of gift already" << std::endl;
        }
    } else {
        std::cerr << "You need to take the GiftPaper first before try to wrap!" << std::endl;
    }
}