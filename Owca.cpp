#include "Owca.h"
#include <iostream>

Owca::Owca(PUNKT _p, Swiat * _swiat)
{
	setSila(4);
	setInicjatywa(4);
	setWiek(0);

	setDomyslnieAkcji(1);
	setIleAkcji(0);
	setSzansaNaAkcje(100);
	setDodatkowyRuch(false);

	setSymbol('\317');
	setNazwa("Owca");
	setKolor(15); // bia³y

	setPolozenie(_p);

	setPrzybywaZ(_p);

	setSwiat(_swiat);
	setCzyZwierze(true);
	setRozmnazalSie(true);
	//setCzyZjedzony(false);
	//std::cout << "Tworze Owce o wspolrzednych: x = " << this->polozenie.getX() << ", y = " << this->polozenie.getY() << std::endl;
	//std::cout << "Tworze Owce o ID = " << this->swiat << std::endl;
}

Owca::~Owca()
{
	//std::cout << "Ktos zrobil sobie sweterek z Owcy!\n";
}