/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Parser
*/

#include "../include/Parser.hpp"
#include "../include/Exception.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

int Parser::readfile(const std::string s)
{
    std::ifstream   file(s.c_str(), std::ios::in);
    std::regex      reg("([ ]+)?exit([ ]+)?");
    std::string     content;
    std::string     line;
    std::vector<std::string> stack;
    int i = 0;

    if (!file || is_empty(file)) {
        throw Exception("File not found or empty.");
        return (84);
    }

    else {
        while (getline(file, content) && !regex_match(content, reg)) {
            stack.push_back(content);
            i++;
        }
        if (!regex_match(content, reg))
            throw Exception("No EXIT command found in the file.");
        file.close();
    }

    return (0);
}

int Parser::printmystack(std::vector<std::string> stack, int j)
{
    for(int i = 0; i < j; i++) {
        std::cout << stack[i] << std::endl;
    }

    return (0);
}

int Parser::readline(void)
{
    std::vector<std::string> stack;
	std::regex reg("([ ]+)?exit([ ]+)?");
    std::regex goodcmd("([ ]+)?((add|pop|dump|sub|mul|div|mod|print|exit)|((push|assert)[ ]((int(8|16|32)[(]-?[0-9]+[)])|(float|double)[(]-?[0-9]+(.[0-9]+)?[)])))([ ]+)?");
    std::regex operato("([ ]+)?(add|sub|mul|div|mod)([ ]+)?");

    std::string      content;
    int         i = 0;
    int         j = 0;

    while (getline(std::cin, content) && content.compare(";;") != 0) {
        if (regex_match(content, goodcmd)) {
            stack.push_back(content);
            j++;
        }
        else if (regex_match(content, operato)) {
            if (j < 2) {
                std::cerr << "Not enougth values before commands." << std::endl;
                break;
            }
        }
        else {
            std::cerr << "Invalid line or invalid command." << std::endl;
        }
        if (regex_match(content, reg))
			i++;
    }
    if (!content.compare(";;"))
        //printmystack(stack, j);
    if (i == 0)
        throw Exception("No 'exit' command found in the file.");

    return (0);
}

int Parser::readinit(const std::string s, bool i)
{
    try {
        if (i == 0 && readline() == 84)
            return (84);
        if (i == 1 && readfile(s) == 84)
            return (84);
    }
    catch (const Exception &e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    return (0);
}