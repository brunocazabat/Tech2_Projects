/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <exception>
#include <string>
#include <utility>
#include <fstream>
#include <vector>
#include <regex>
#include <limits.h>

#define INT8MAX = 127
#define INT8MIN = -128
#define INT16MAX = 32767
#define INT16MIN = -32768
#define INT32MAX = 2147483647
#define INT32MIN = -2147483648
#define FLOATMAX = 3.4028235E38
#define FLOATMIN = 1.4E-45

class Parser {
	public:
		Parser();
		~Parser();
        int readinit(const std::string s, bool i);
		bool is_empty(std::ifstream& pFile);
		int readfile(const std::string s);
		int readline(void);
		int printmystack(std::vector<std::string> stack, int j);

	protected:
	private:
};

#endif /* !PARSER_HPP_ */
