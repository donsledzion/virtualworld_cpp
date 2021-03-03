#include "Trawa.h"

Trawa::Trawa(PUNKT _p, Swiat * _swiat)
{
	setSymbol('\261');
	setNazwa("Trawa");
	setKolor(10); // zielony dla roœlin

	setSila(0);
	setInicjatywa(0);
	setWiek(0);

	setDomyslnieAkcji(1);
	setIleAkcji(0);
	setSzansaNaAkcje(15);
	setDodatkowyRuch(false);

	setPolozenie(_p);

	setPrzybywaZ(_p);

	setSwiat(_swiat);

	setCzyZwierze(false);
	setRozmnazalSie(true);
	//setCzyZjedzony(false);
	//std::cout << "Tworze Trawe o wspolrzednych: x = " << this->polozenie.getX() << ", y = " << this->polozenie.getY() << std::endl;
}

Trawa::~Trawa()
{
	//std::cout << "Zjedzono Trawe!";
}
