/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Circuit.hpp"

nts::Circuit::Circuit(std::string const &filename, std::vector<std::pair<std::string, std::string>> const &in) : _filename(filename)
{
    std::string buffer = "";
    size_t pos = filename.find_last_of(".");
    if (pos == std::string::npos || filename.substr(pos, filename.size()) != ".nts")
        throw nts::FileError("Error: bad file format");
    std::ifstream ifs(_filename.data());
    _root = NULL;
    _parser = new ASTParser(in);
    if (ifs)
    {
        try
        {
            while (std::getline(ifs, buffer))
                _parser->feed(buffer);
            _root = _parser->createTree();
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
    deleteRoot(_root);
    delete _parser;
}

void nts::Circuit::load(void)
{
    try
    {
        _parser->parseTree(*_root);
    }
    catch (nts::NtsError const &e)
    {
        throw e;
    }
}

void nts::Circuit::deleteRoot(t_ast_node *root)
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

void nts::Circuit::updateInput(std::string const &name, std::string const &value)
{
    try
    {
        _parser->updateInput(name, value);
    }
    catch (nts::InputError const &e)
    {
        throw e;
    }
}

void nts::Circuit::displayOutput(void) const
{
    _parser->displayOuput();
}

void nts::Circuit::dump(void) const
{
    _parser->dump();
}

void nts::Circuit::inverseClock(void) const
{
    _parser->inverseClock();
}
