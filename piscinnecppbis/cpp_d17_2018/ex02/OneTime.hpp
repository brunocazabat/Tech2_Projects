/*
** EPITECH PROJECT, 2019
** one
** File description:
** one
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>
#include <string>
#include <algorithm>

class OneTime : public IEncryptionMethod {
	public:
        OneTime(const std::string &key);
		~OneTime();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
		void reset();

	protected:
	private:
        std::string _key;
        unsigned int _pos;
};

#endif /* !ONETIME_HPP_ */
