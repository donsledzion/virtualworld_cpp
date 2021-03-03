#include "Mlecz.h"

Mlecz::Mlecz(PUNKT _p, Swiat * _swiat)
{

	setSymbol('\365');
	setNazwa("Mlecz");
	setKolor(10); // zielony dla roœlin

	setSila(0);
	setInicjatywa(0);
	setWiek(0);

	setDomyslnieAkcji(3);
	setIleAkcji(0);
	setSzansaNaAkcje(10);
	setDodatkowyRuch(false);

	setPolozenie(_p);

	setPrzybywaZ(_p);

	setSwiat(_swiat);

	setCzyZwierze(false);
	setRozmnazalSie(true);
	//setCzyZjedzony(false);
	//std::cout << "Tworze Mlecz o wspolrzednych: x = " << this->polozenie.getX() << ", y = " << this->polozenie.getY() << std::endl;
}

Mlecz::~Mlecz()
{	
	//std::cout << "Wyrwano Mlecz!";
}