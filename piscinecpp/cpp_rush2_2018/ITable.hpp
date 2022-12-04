/*
** EPITECH PROJECT, 2019
** ITable.hpp
** File description:
** hpp
*/

#ifndef ITABLE_HPP_
	#define ITABLE_HPP_

class ITable {
	public:
		virtual ITable *createTable() = 0;
		virtual ~ITable() = default;

};

#endif /* !ITABLE_HPP_ */
