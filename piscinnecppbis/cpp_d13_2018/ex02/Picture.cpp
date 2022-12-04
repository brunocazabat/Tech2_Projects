/*
** EPITECH PROJECT, 2019
** picture
** File description:
** picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::Picture(const Picture &picture)
{
    data = picture.data;
}

const Picture &Picture::operator=(const Picture &copy)
{
    data = copy.data;
    return (copy);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    char c;
    std::ifstream myfile;

    myfile.open(file);
    if (!myfile) {
        data = "ERROR";
        myfile.close();
        return (false);
    }
    while (myfile.get(c))
        data += c;
    myfile.close();
    return (true);
}