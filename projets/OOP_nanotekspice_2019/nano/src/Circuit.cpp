/*
** EPITECH PROJECT, 2020
** ouioui
** File description:
** oui
*/

#include "Circuit.hpp"

nts::Circuit::Circuit(std::string const &filename, std::vector<std::pair<std::string, std::string>> const &in) : __filename(filename)
{
    std::string mouhoub = "";
    size_t pos = filename.find_last_of(".");
    if (pos == std::string::npos || filename.substr(pos, filename.size()) != ".nts")
        throw nts::FileError("Error: bad file format");
    std::ifstream ifs(__filename.data());
    __root = NULL;
    __parser = new Parser(in);
    if (ifs)
    {
        try
        {
            while (std::getline(ifs, mouhoub))
                __parser->feed(mouhoub);
            __root = __parser->createTree();
        }
        catch (nts::NtsError const &e)
        {
            throw e;
        }
        ifs.close();
    }
    else
        throw nts::FileError("Error: " + filename + " can't be open");
}

nts::Circuit::~Circuit(void)
{
    deleteRoot(__root);
    delete __parser;
}

void nts::Circuit::load(void)
{
    try
    {
        __parser->parseTree(*__root);
    }
    catch (nts::NtsError const &e)
    {
        throw e;
    }
}

void nts::Circuit::deleteRoot(t__ast__node *root)
{
    if (root)
    {
        if ((*root->children)[0])
            deleteRoot((*root->children)[0]);
        delete (root->children);
        delete (root);
        root = NULL;
    }
}

void nts::Circuit::updateInput(std::string const &name, std::string const &val)
{
    try
    {
        __parser->updateInput(name, val);
    }
    catch (nts::Inputerror const &e)
    {
        throw e;
    }
}

void nts::Circuit::displayOutput(void) const
{
    __parser->displayOuput();
}

void nts::Circuit::dump(void) const
{
    __parser->dump();
}

void nts::Circuit::inverseClock(void) const
{
    __parser->inverseClock();
}
