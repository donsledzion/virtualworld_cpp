#include "Koka.h"

void Koka::reAkcja(Organizm* jedzacy)
{
	std::string komunikat = jedzacy->getNazwa() + " dostal kokainowego kopa i w kolejnej turze bedzie mial dodatkowy ruch!\n";
	getSwiat()->wyswietlRelacje(3, 1, komunikat);
	jedzacy->setDodatkowyRuch(true);
}

Koka::Koka(PUNKT _p, Swiat * _swiat)
{
	setSymbol('\200');
	setNazwa("Koka");
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
	//std::cout << "Tworze Koke o wspolrzednych: x = " << this->polozenie.getX() << ", y = " << this->polozenie.getY() << std::endl;
}

Koka::~Koka() 
{
	//std::cout << "DEA are on their way!";
}