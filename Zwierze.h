#pragma once
#include "Organizm.h"
class Zwierze :
	public Organizm
{
protected:

	virtual void akcja()
	{
		ruch();
	}

	virtual void ruch()
	{

		PUNKT wylosowanePole = getSwiat()->losujPole();

		PUNKT docelowePole = { getPolozenie().getX() + wylosowanePole.getX(),getPolozenie().getY() + wylosowanePole.getY() };
		while (getSwiat()->czyPoleNaPlanszy(docelowePole) == false)
		{
			wylosowanePole = getSwiat()->losujPole();
			docelowePole = { getPolozenie().getX() + wylosowanePole.getX(),getPolozenie().getY() + wylosowanePole.getY() };
		}
		idzNaPole(docelowePole);
		sprawdzKolizje();
	}

private:

	virtual void sprawdzKolizje()
	{
		for (int i = 0; i < getSwiat()->getIloscOrganizmow(); i++)
		{
			if ((getSwiat()->getOrganizm(i)->getPolozenie().getX() == this->getPolozenie().getX()) && (getSwiat()->getOrganizm(i)->getPolozenie().getY() == this->getPolozenie().getY()))
				if (this != getSwiat()->getOrganizm(i))
					this->kolizja(getSwiat()->getOrganizm(i));
		}
	}

	virtual void idzNaPole(PUNKT p)
	{
		this->setPrzybywaZ(getPolozenie());

		this->setPolozenie(p);

		if (getIleAkcji() > 0)
			this->decIleAkcji();
	}

	virtual void kolizja(Organizm* organizm)
	{
		if (this->getNazwa() == organizm->getNazwa())
		{
			this->idzNaPole(this->getPrzybywaZ());
			if ((this->getRozmnazalSie() == false) && (organizm->getRozmnazalSie() == false))
			{
				this->getSwiat()->rozmnazajOrganizm(this, organizm);
			}
		}

		else if (this->getSila() >= organizm->getSila())
			zjedz(organizm);
		else if (this->getSila() < organizm->getSila())
		{
			//std::cout << "Ups! Zbyt odwaznie! ";
			organizm->zjedz(this);
		}
	}

	virtual void zjedz(Organizm* zjadany)
	{
		std::string komunikat = getNazwa() + " z pola [ " + std::to_string(getPrzybywaZ().getX()) + " , " + std::to_string(getPrzybywaZ().getY()) + " ] zjada ";
		komunikat += zjadany->getNazwa() + " z pola [ " + std::to_string(zjadany->getPolozenie().getX()) + " , " + std::to_string(zjadany->getPolozenie().getY()) + " ]";
		unsigned short flaga;

		if (zjadany->getCzyZwierze()) flaga = 2;
		else flaga = 0;
		getSwiat()->wyswietlRelacje(flaga, 2, komunikat);

		zjadany->reAkcja(this);
		this->getSwiat()->zjedzOrganizm(zjadany);
	}

};

