/*
** EPITECH PROJECT, 2019
** SYN_abstractVM_2018
** File description:
** IOperand
*/

#ifndef IOPERAND_HPP_
#define IOPERAND_HPP_

#include <iostream>
#include <exception>
#include <string>
#include <utility>
#include <fstream>
#include <vector>
#include <regex>
#include <cstdio>
#include <cstdlib>
#include <sstream>

enum eOperandType {
	Int8,
	Int16,
	Int32,
	Float,
	Double,
    BigDecimal,
};

class IOperand {
	public:
	virtual std::string toString() const = 0; // string that represents the instance
    virtual eOperandType getType() const = 0; // returns the type of instance
    virtual IOperand *operator +(const IOperand &rhs) const = 0; // sum
    virtual IOperand * operator -(const IOperand &rhs) const = 0; // difference
    virtual IOperand * operator *(const IOperand & rhs) const = 0; // product
    virtual IOperand * operator /(const IOperand & rhs) const = 0; // quotient
    virtual IOperand * operator %(const IOperand & rhs) const = 0; // modulo
    virtual ~ IOperand() {}
};

#endif /* !IOPERAND_HPP_ */
