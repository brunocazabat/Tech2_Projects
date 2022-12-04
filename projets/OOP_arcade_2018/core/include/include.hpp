/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#ifndef INCLUDE_HPP_
    #define INCLUDE_HPP_

#include <cstring>
#include <dirent.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <curses.h>
#include <ncurses.h>
#include <dlfcn.h>
#include <sstream>

class Menu
{
    public:
        virtual void start();
};
 
class arcade
{
 public:
    virtual void start();
};

typedef arcade *(*maker_arcade)();

#endif /* !INCLUDE_HPP_ */
