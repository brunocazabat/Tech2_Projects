/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#pragma once

#include "Component.hpp"

class Circuit : public Component {
    public:
        Circuit();
        ~Circuit();
        void add(Component *toAdd);
        void remove(Component *toRm);
        void run();

    protected:
    private:
};
