/*
** EPITECH PROJECT, 2019
** PapaXmas.cpp
** File description:
** cpp
*/

#include <string>
#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable()
{
    Object **tabObject = new Object *[10];
    for (int i = 0; i < 10; i++) {
        tabObject[i] = NULL;
    }    
}

PapaXmasTable::~PapaXmasTable() {}

int PapaXmasTable::searchSquare() 
{
     for (int i = 0; i < 10; i++) {
         if (this->tabObject[i] == NULL)
            return (i);
     }
     return(42);
 }

 void PapaXmasTable::PutObject(Object *Object) 
 {
     int i = searchSquare();
     if (i == 42) {
         //std::cout << "No more space on the table..." << std::endl; OU DELETE ???? 
         std::cout << "Oh noooo! The table collapses... :( " << std::endl;
         this->~PapaXmasTable();
     } else {
         this->tabObject[i] = Object;
     }
 }

 Object *PapaXmasTable::takeObject(std::string nameObject) 
 {
    Object *tmpObject;
    
    for(int i = 0; i < 10; i++) {
        if (this->tabObject[i]->getTitle() == nameObject) {
            tmpObject = this->tabObject[i];
            this->tabObject[i] = NULL;
            return(tmpObject);
        }
    }
    std::cout << "This object isn't on the table..." << std::endl;
    return (NULL);
 }

 ITable *PapaXmasTable::createTable() {
     PapaXmasTable *papaTable;
     std::cout << "Table created!" << std::endl;
     return (papaTable);
 }

std::string *PapaXmasTable::lookTable() {
    std::string *TabName = new std::string[10];
    for(int i = 0; i < 10; i++) {
        if (this->tabObject[i] == NULL) {
            std::cout << "There is nothing on the n*" << i << " of the table" << std::endl;
            TabName[i] = "empty";
        } else {
            TabName[i] = tabObject[i]->getTitle();
            std::cout << "There is the object " << TabName[i] << " on the n*" << i << " of the table" << std::endl;
        }
    }
    TabName[11] = nullptr;
    return(TabName);

}