#pragma once
#include "Zwierze.h"
class Leniwiec :
    public Zwierze
{
public:

    Leniwiec(PUNKT _p, Swiat* _swiat, bool _czySieRuszyl);

    ~Leniwiec();

    void wypiszOrganizm(std::ostream& os);

	Leniwiec& operator = (Leniwiec& prawa)
	{
		this->setSymbol(prawa.getSymbol());
		this->setKolor(prawa.getKolor());
		this->setNazwa(prawa.getNazwa());
		this->setSila(prawa.getSila());
		this->setInicjatywa(prawa.getInicjatywa());
		this->setWiek(prawa.getWiek());
		this->setDomyslnieAkcji(prawa.getDomyslnieAkcji());
		this->setIleAkcji(prawa.getIleAkcji());
		this->setSzansaNaAkcje(prawa.getSzansaNaAkcje());
		this->setDodatkowyRuch(prawa.getDodatkowyRuch());
		this->setPolozenie(prawa.getPolozenie());
		this->setPrzybywaZ(prawa.getPrzybywaZ());
		this->setSwiat(prawa.getSwiat());
		this->setCzyZwierze(prawa.getCzyZwierze());
		this->setRozmnazalSie(prawa.getRozmnazalSie());

		this->czySieRuszyl = prawa.czySieRuszyl;

		return *this;
	}

private:
    void akcja();

    void setCzySieRuszyl(bool _czySieRuszyl);

    bool getCzySieRuszyl();

    bool czySieRuszyl;

};

