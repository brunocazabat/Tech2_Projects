/*
** EPITECH PROJECT, 2019
** Cesar
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar() : _shift(3)
{
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainchar)
{
    std::string alphaMin = "abcdefghijklmnopqrstuvwxyz";
    std::string alphaMaj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key = _shift;
    int toCrypt;

    if (plainchar >= 'a' && plainchar <= 'z') {
        toCrypt = plainchar - 'a';
        while (--key != -1)
            toCrypt = (toCrypt == 25) ? 0 : toCrypt + 1;
        std::cout << alphaMin[toCrypt];
    } else if (plainchar >= 'A' && plainchar <= 'Z') {
        toCrypt = plainchar - 'A';
        while (--key != -1)
            toCrypt = (toCrypt == 25) ? 0 : toCrypt + 1;
        std::cout << alphaMaj[toCrypt];
    } else
        std::cout << plainchar;
    _shift += 1;
}

void Cesar::decryptChar(char cipherchar)
{
    std::string alphaMin = "abcdefghijklmnopqrstuvwxyz";
    std::string alphaMaj = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key = _shift;
    int toCrypt;

    if (cipherchar >= 'a' && cipherchar <= 'z') {
        toCrypt = cipherchar - 'a';
        while (--key != -1)
            toCrypt = (toCrypt == 0) ? 25 : toCrypt - 1;
        std::cout << alphaMin[toCrypt];
    } else if (cipherchar >= 'A' && cipherchar <= 'Z') {
        toCrypt = cipherchar - 'A';
        while (--key != -1)
            toCrypt = (toCrypt == 0) ? 25 : toCrypt - 1;
        std::cout << alphaMaj[toCrypt];
    } else
        std::cout << cipherchar;
    _shift += 1;

}

void Cesar::reset()
{
    _shift = 3;    
}