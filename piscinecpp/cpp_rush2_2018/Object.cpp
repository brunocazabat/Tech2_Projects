/*
** EPITECH PROJECT, 2019
** Object.cpp
** File description:
** Object
*/

#include "Object.hpp"

Object::Object() = default;

Object::~Object() = default;

std::string Object::getTitle() {
    return (this->_title);
}

bool Object::getTaken() {
    return (this->_taken);
}

void Object::isTaken() {
    this->_taken = true;
}