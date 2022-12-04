/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include <vector>
#include <iostream>

typedef enum {
   UNDEFINED = -1,
   TRUE      = 0,
   FALSE     = 1
} Tristate;

class Component {
    public:
        Component(Tristate ts = UNDEFINED);
        ~Component();
        std::vector<Tristate> getInputs();
        std::vector<Tristate> getOutputs();
        Tristate exec();
        void setLink(Component *toLink);

    protected:
        Component *link;
        std::vector<Tristate> states;
    private:
};