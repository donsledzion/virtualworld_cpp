#include "Wilk.h"

Wilk::Wilk(PUNKT _p, Swiat *_swiat)
{
	setSila(9);
	setInicjatywa(5);
	setWiek(0);
	
	setDomyslnieAkcji(1);
	setIleAkcji(0);
	setSzansaNaAkcje(100);	

	setSymbol('W');
	setNazwa("Wilk");
	setKolor(8); // szary

	setPolozenie(_p);

	setPrzybywaZ(_p);

	setSwiat(_swiat);
	setCzyZwierze(true);
	setRozmnazalSie(true);
	//setCzyZjedzony(false);
	
	//std::cout << "Tworze wilka na polu x = " << this->getPolozenie().getX() << ", y = " << this->getPolozenie().getY() << std::endl;
	//std::cout << "Tworze wilka o ID = " << this->swiat << std::endl;
}

Wilk::~Wilk()
{
	//std::cout << "Wilk Zdycha!\n";
}