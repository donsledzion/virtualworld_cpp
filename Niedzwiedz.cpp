#include "Niedzwiedz.h"

Niedzwiedz::Niedzwiedz(PUNKT _p, Swiat * _swiat)
{
	setSila(10);
	setInicjatywa(4);
	setWiek(0);

	setDomyslnieAkcji(1);
	setIleAkcji(0);
	setSzansaNaAkcje(100);
	setDodatkowyRuch(false);

	setSymbol('\345');
	setNazwa("Misio");
	setKolor(12); // czerwony

	setPolozenie(_p);

	setPrzybywaZ(_p);

	setSwiat(_swiat);
	setCzyZwierze(true);
	setRozmnazalSie(true);
	//std::cout << "Tworze Niedzwiedzia o wspolrzednych: x = " << this->polozenie.getX() << ", y = " << this->polozenie.getY() << std::endl;
	//std::cout << "Tworze Niedzwiedzia o ID = " << this->swiat << std::endl;
}

Niedzwiedz::~Niedzwiedz()
{
	//std::cout << "Polegl Niedzwiedz!\n";
}