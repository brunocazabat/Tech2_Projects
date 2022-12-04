/*
** EPITECH PROJECT, 2019
** PapaXmasTable.hpp
** File description:
** hpp
*/

#ifndef PAPAXMASTABLE_HPP_
	#define PAPAXMASTABLE_HPP_

#include "Object.hpp"
#include "ITable.hpp"

    class PapaXmasTable : public ITable {
        public:
            PapaXmasTable();
            ~PapaXmasTable();
            void PutObject(Object *Object);
			Object *takeObject(std::string nameObject);
            Object *initTabObjects(Object **tabObject);
            int searchSquare();
            std::string *lookTable();
            ITable *createTable();

        protected:
        private:
            Object **tabObject;

    };


#endif /* !PAPAXMASTABLE_HPP_ */
