/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/
#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    std::ifstream stream(file.c_str());
    std::string string;

    if (stream) 
    {
        this->data = "";
        while (getline(stream, string, '\0'))
            this->data = this->data + string;
        stream.close();
    }
    else
        this->data = "ERROR";
}

Picture::~Picture()
{
}


bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream stream(file.c_str());
    std::string string;

    if (stream) 
    {
        this->data = "";
        while (getline(stream, string, '\0'))
            this->data = this->data + string;
        stream.close();
    }
    else {
        this->data = "ERROR";
        return (false);
    }
    return (true);
}