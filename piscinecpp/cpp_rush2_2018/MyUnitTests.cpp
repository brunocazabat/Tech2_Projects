#include "Object.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Toy.hpp"
#include "Wrap.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "IConveyorBelt.hpp"
#include "ITable.hpp"
#include "PapaXmasTable.hpp"
#include "PapaXmasConveyorBelt.hpp"

Object **MyUnitTests() 
{
    std::cout << "---- TEST UNITAIRE 1 DEBUT ----" << std::endl;
    Object *pon = new LittlePony("happy pony");
    Object *ted = new Teddy("cuddles");
    Object **tab = new Object *[2];
    tab[0] = pon;
    tab[1] = ted;
    std::cout << "----- TEST UNITAIRE 1 FIN ----" << std::endl;
    return (tab);
}

void test1() {
    std::cout << "TEST PERSO DEBUT 1"<< std::endl;
    Object *ted = new Teddy("Ted");
    Object *pony = new LittlePony("Unicorn");

    std::cout << ted->getTitle() << std::endl;
    std::cout << pony->getTitle() << std::endl;

    if (pony->getTaken()) {
        std::cout << "taken"<< std::endl;
    } else {
        std::cout << "not taken"<< std::endl;
    }
    if (ted->getTaken()) {
        std::cout << "taken"<< std::endl;
    } else {
        std::cout << "not taken"<< std::endl;
    }
    ted->isTaken();
    pony->isTaken();

    if (pony->getTaken()) {
        std::cout << "taken"<< std::endl;
    } else {
        std::cout << "not taken"<< std::endl;
    }
    if (ted->getTaken()) {
        std::cout << "taken"<< std::endl;
    } else {
        std::cout << "not taken"<< std::endl;
    }
    std::cout << "TEST PERSO FIN 1"<< std::endl;
}

Object *MyUnitTests(Object **obj)
{
    std::cout << "----- TEST UNITAIRE 2 DEBUT ----" << std::endl;
    Teddy *teddy = (Teddy *)obj[0];
    Box *box = (Box *)obj[1];
    GiftPaper *giftPaper = (GiftPaper *)obj[2];

    std::cout << "--Take the box :" << std::endl;
    box->isTaken();
    std::cout << "--Open the box :" << std::endl;
    box->openMe();
    if (box->getOpen()) {
        std::cout << "open"<< std::endl;
    } else {
        std::cout << "not open"<< std::endl;
    }
    std::cout << "--Wrap the box :" << std::endl;
    box->wrapMeThat(teddy);
    std::cout << "--Take the GiftPaper :" << std::endl;
    giftPaper->isTaken();
    std::cout << "--Wrap the box with GiftPaper :" << std::endl;
    giftPaper->wrapMeThat(box);
    std::cout << "---- TEST UNITAIRE 2 FIN ----" << std::endl;
    return (giftPaper);
}

int main(void)
{
    test1();
    Object **obj = MyUnitTests();
    LittlePony *ponny = (LittlePony *)obj[0];
    Teddy *teddy = (Teddy *)obj[1];
    ponny->isTaken();
    teddy->isTaken();
    obj = new Object*[4];
    obj[0] = new Teddy("bisounours");
    obj[1] = new Box;
    obj[2] = new GiftPaper;
    obj[3] = NULL;
    std::cout << obj[0]->getTitle() << std::endl;
    std::cout << obj[1]->getTitle() << std::endl;
    std::cout << obj[2]->getTitle() << std::endl;    
    MyUnitTests(obj);
    return (0);
}