/*
** EPITECH PROJECT, 2019
** Koala
** File description:
** Koala
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot
{
  public:
    KoalaBot(const std::string &_name = "Bob-01");
    ~KoalaBot();
    void setParts(const Arms &arms);
    void setParts(const Legs &legs);
    void setParts(const Head &head);
    void swapParts(Arms &arms);
    void swapParts(Legs &legs);
    void swapParts(Head &head);
    void informations() const;
    bool status() const;

  protected:
  private:
    std::string _serial;
    Arms _arms;
    Legs _legs;
    Head _head;
};

#endif /* !KOALABOT_HPP_ */
