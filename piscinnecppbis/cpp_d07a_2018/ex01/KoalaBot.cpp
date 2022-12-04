/*
** EPITECH PROJECT, 2019
** Koala
** File description:
** Koala
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(const std::string &name)
{
    _serial = name;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}
    
void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}
    
void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    setParts(arms);
}

void KoalaBot::swapParts(Legs &legs)
{
    setParts(legs);
}

void KoalaBot::swapParts(Head &head)
{
    setParts(head);
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_arms.isFunctionnal() && _legs.isFunctionnal() && _head.isFunctionnal())
        return (true);
    else
        return (false);
}