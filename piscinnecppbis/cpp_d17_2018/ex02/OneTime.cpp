/*
** EPITECH PROJECT, 2019
** one
** File description:
** one
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string &key)
{
    std::string str = key;
    std::locale loc;
    for(std::string::size_type i = 0; i < key.length(); ++i)
        str[i] = std::tolower(key[i], loc);
    _key = str;
    _pos = 0;
}

OneTime::~OneTime()
{
}

void OneTime::encryptChar(char plainchar)
{
    int key = 0;
    char c;

    if (_pos == _key.size())
         _pos = 0;
    if (std::isalpha(plainchar)) {
        if (std::islower(plainchar)) {
            key = (_key[_pos] - 'a') + (plainchar - 'a');
            key = (key > 25) ? key - 26 : key;
            c = key + 'a';
        } else {
            key = (_key[_pos] - 'a') + (plainchar - 'A');
            key = (key > 25) ? key - 26 : key;
            c = key + 'A';
        }
        std::cout << c;
    } else
        std::cout << plainchar;    
    _pos += 1;
}

void OneTime::decryptChar(char cipherchar)
{
    int key = 0;
    char c;

    if (_pos == _key.size())
         _pos = 0;
    if (std::isalpha(cipherchar)) {
        if (std::islower(cipherchar)) {
            key = (cipherchar - 'a') - (_key[_pos] - 'a');
            key = (key < 0) ? 26 + key : key;
            c = key + 'a';
        } else {
            key = (cipherchar - 'A') - (_key[_pos] - 'a');
            key = (key < 0) ? 26 + key : key;
            c = key + 'A';
        }
        std::cout << c;
    } else
        std::cout << cipherchar;
    _pos += 1;
}

void OneTime::reset()
{
    _pos = 0;
}