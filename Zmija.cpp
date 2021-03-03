#include "Zmija.h"

void Zmija::reAkcja(Organizm* jedzacy)
{
	std::string komunikat = jedzacy->getNazwa() + " z pola ["+ std::to_string(jedzacy->getPolozenie().getX()) + ","+std::to_string(jedzacy->getPolozenie().getY())+ "] w zabijajac zmije zostal smiertelnie zatruty i ginie!\n";
	getSwiat()->wyswietlRelacje(2, 1, komunikat);
	//std::cout << jedzacy->nazwa << " w walce ze zmija zostal smiertelnie zatruty i ginie!\n";
	getSwiat()->zjedzOrganizm(jedzacy);
}

Zmija::Zmija(PUNKT _p, Swiat* _swiat)
{
	setSila(2);
	setInicjatywa(3);
	setWiek(0);

	setDomyslnieAkcji(1);
	setIleAkcji(0);
	setSzansaNaAkcje(100);
	setDodatkowyRuch(false);

	setSymbol('\270');
	setNazwa("Zmija");
	setKolor(13); // fioletowy

	setPolozenie(_p);

	setPrzybywaZ(_p);

	setSwiat(_swiat);
	setCzyZwierze(true);
	setRozmnazalSie(true);
	//setCzyZjedzony(false);
	//std::cout << "Tworze Zmije o wspolrzednych: x = " << this->polozenie.getX() << ", y = " << this->polozenie.getY() << std::endl;
	//std::cout << "Tworze Zmije o ID = " << this->swiat << std::endl;
}

Zmija::~Zmija()
{
	//std::cout << "Rozdeptano Zmije!\n";
}