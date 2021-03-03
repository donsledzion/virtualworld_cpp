#pragma once
#include "Organizm.h"

class Roslina :
	public Organizm
{	
protected:

	virtual void akcja()
	{
		while ((this->getIleAkcji() > 0) && (this->getSwiat()->getIloscOrganizmow() < this->getSwiat()->getRozmiarSwiata() * this->getSwiat()->getRozmiarSwiata()))
		{
			if (probaRozsadzenia() == true)
			{
				rozmnazanie();
			}
			if (getIleAkcji()>0)
				this->decIleAkcji();
		}
	}

private:

	virtual void kolizja(Organizm*) {}

	virtual void idzNaPole(PUNKT) {}

	virtual void sprawdzKolizje() {}

	virtual bool probaRozsadzenia() 
	{
		unsigned short wylosowano = rand() % 100 + 1;
		if (wylosowano <= this->getSzansaNaAkcje())
			return true;
		else return false;
	}
};

