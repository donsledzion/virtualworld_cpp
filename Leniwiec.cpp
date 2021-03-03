#include "Leniwiec.h"

void Leniwiec::akcja()
{
	if (this->getCzySieRuszyl() == false)
	{
		ruch();
		this->setCzySieRuszyl(true);
	}
	else
		this->setCzySieRuszyl(false);
}

void Leniwiec::setCzySieRuszyl(bool _czySieRuszyl) { czySieRuszyl = _czySieRuszyl;}
bool Leniwiec::getCzySieRuszyl() { return czySieRuszyl; }

void Leniwiec::wypiszOrganizm(std::ostream& os)
{
	os << getNazwa() << "\t";
	os << getSila() << "\t";
	os << getWiek() << "\t";
	os << getIleAkcji() << "\t";
	os << getDodatkowyRuch() << "\t";
	os << getPolozenie() << "\t";
	os << getPrzybywaZ() << "\t";
	os << getRozmnazalSie() << "\t";
	os << getCzySieRuszyl() << " ;\n";
}


//Leniwiec(PUNKT _p, Swiat* _swiat, unsigned short _sila, unsigned int _wiek, unsigned short _ileAkcji, bool _dodatkowyRuch, PUNKT _przybywaZ, bool _rozmnazalSie, bool _czySieRuszyl)
Leniwiec::Leniwiec(PUNKT _p, Swiat* _swiat, bool _czySieRuszyl)
{
	setSila(2);
	setInicjatywa(1);
	setWiek(0);

	setDomyslnieAkcji(1);
	setIleAkcji(0);
	setSzansaNaAkcje(100);
	setDodatkowyRuch(false);

	setSymbol('\351');
	setNazwa("Leniwiec");
	setKolor(11); // b³êkitny

	setPolozenie(_p);

	setPrzybywaZ(_p);		
	
	setSwiat(_swiat);
	setCzyZwierze(true);
	setCzySieRuszyl(false);
	setRozmnazalSie(_czySieRuszyl);

	//std::cout << "Tworze Leniwca o wspolrzednych: x = " << this->polozenie.getX() << ", y = " << this->polozenie.getY() << std::endl;
	//std::cout << "Tworze Leniwca o ID = " << this->swiat << std::endl;
}

Leniwiec::~Leniwiec()
{
	//std::cout << "Leniwiec spadl z drzewa :(!\n";
}