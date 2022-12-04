/*
** EPITECH PROJECT, 2019
** Convoyerbelt.cpp
** File description:
** cpp
*/

#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt() {
    this->_obj = NULL;
    this->_full = false;
	this->_INButton = false;
	this->_OUTButton = false;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt() {

}

bool PapaXmasConveyorBelt::isFull() {
    return(_full);
}

void PapaXmasConveyorBelt::putObject(Object *object) {
    if(isFull() == false) {
        this->_obj = object;
        this->_full = true;
    } else {
        std::cout << "There is already an Object on the conveyor !!" << std::endl;
    }
}

Object *PapaXmasConveyorBelt::takeObject() {
    if(isFull() == true) {
        Object *ObjectTmp = this->_obj;
        std::cout << "The object "<< ObjectTmp->getTitle() << " has been removed from the conveyor Belt." << std::endl;
        this->_full = false;
        this->_obj = NULL;
        return(ObjectTmp);
    }
    std::cout << "The conveyor is empty.. nothing to removed" << std::endl;
    return (NULL);
}

IConveyorBelt *PapaXmasConveyorBelt::createConveyorBelt() {
    PapaXmasConveyorBelt *conveyorBelt;
    std::cout << "ConvoyerBelt created!" << std::endl;
    return (conveyorBelt);
}