#pragma once

#include "PUNKT.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <algorithm>
#include "Swiat.h"
#include "Wyjatek.h"
class Organizm
{
public:
	
	//==========================================================================================
	// SETTERY
	//==========================================================================================
	void setWiek(unsigned short _wiek)	{ wiek = _wiek; }
	void incWiek()						{ wiek++; }

	void setIleAkcji(unsigned short _ileAkcji)	{ ileAkcji = _ileAkcji; }
	void incIleAkcji() { ileAkcji++; }
	void decIleAkcji() { ileAkcji--; }

	void setDodatkowyRuch(bool _dodatkowyRuch) { dodatkowyRuch = _dodatkowyRuch; }

	void setPolozenie(PUNKT _polozenie) { polozenie = _polozenie; }

	void setPrzybywaZ(PUNKT _przybywaZ) { przybywaZ = _przybywaZ; }

	void setSymbol(char _symbol) { symbol = _symbol; }

	void setKolor(unsigned short _kolor) { kolor = _kolor; }

	void setNazwa(std::string _nazwa) { nazwa = _nazwa; }

	void setSila(unsigned short _sila) { sila = _sila; }

	void setInicjatywa(unsigned short _inicjatywa) { inicjatywa = _inicjatywa; }

	void setSwiat(Swiat* _swiat) { swiat = _swiat; }

	void setRozmnazalSie(bool _rozmnazalSie) { rozmnazalSie = _rozmnazalSie; }


	//==========================================================================================
	// GETTERY
	//==========================================================================================

	char			getSymbol()				{ return symbol;}

	std::string		getNazwa()				{ return nazwa; }

	unsigned short	getSila()				{ return sila;}

	unsigned short	getInicjatywa()			{ return inicjatywa;}

	unsigned short	getWiek()				{ return wiek; }

	unsigned short	getDomyslnieAkcji()		{ return domyslnieAkcji; }

	unsigned short	getIleAkcji()			{ return ileAkcji;}	
	
	bool getDodatkowyRuch() { return dodatkowyRuch; }

	PUNKT getPolozenie() { return polozenie; }

	PUNKT getPrzybywaZ() { return przybywaZ; }
	
	bool getCzyZwierze() { return czyZwierze; }

	bool getRozmnazalSie() { return rozmnazalSie; }

	Swiat* getSwiat() { return swiat; }

	//==========================================================================================
	// THE OTHERS //============================================================================
	//==========================================================================================

	virtual void wypiszOrganizm(std::ostream& os)
	{
		os << this->getNazwa() <<"\t\t";
		os << this->getSila() << "\t";
		os << this->getWiek() << "\t";
		os << this->getIleAkcji() << "\t";
		os << this->getDodatkowyRuch() << "\t";
		os << this->getPolozenie() << "\t";
		//os << getPolozenie().getY() << "\t";
		os << this->getPrzybywaZ() << "\t";
		//os << getPrzybywaZ() << "\t";
		os << this->getRozmnazalSie() << " ;\n";
	}

	virtual void akcja() = 0;

	virtual void reAkcja(Organizm* atakujacy) {} // nie tworzê metody jako czysto wirtualnej, poniewa¿ nie ka¿dy organizm bêdzie przekazywa³ reakcjê na kolizjê.

	virtual void rysowanie()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, this->kolor);
		std::cout << this->symbol;
		SetConsoleTextAttribute(hConsole, 15);
	}

	virtual void zjedz(Organizm*) {}
	
	virtual ~Organizm() {
		//std::cout << "Die Mama mia!!\n";
	}
		Organizm& operator = (Organizm& prawa)
		{
			this->symbol = prawa.symbol;
			this->kolor = prawa.kolor;
			this->nazwa = prawa.nazwa;
			this->sila = prawa.sila;
			this->inicjatywa = prawa.inicjatywa;
			this->wiek = prawa.wiek;
			this->domyslnieAkcji = prawa.domyslnieAkcji;
			this->ileAkcji = prawa.ileAkcji;
			this->szansaNaAkcje = prawa.szansaNaAkcje;
			this->dodatkowyRuch = prawa.dodatkowyRuch;
			this->polozenie = prawa.polozenie;
			this->przybywaZ = prawa.przybywaZ;
			this->swiat = prawa.swiat;
			this->czyZwierze = prawa.czyZwierze;
			this->rozmnazalSie = prawa.rozmnazalSie;

			return *this;
		}


protected:

	unsigned short	getKolor() { return kolor; }

	virtual void kolizja(Organizm*) = 0;

	unsigned short	getSzansaNaAkcje() { return szansaNaAkcje; }

	virtual void idzNaPole(PUNKT) = 0;

	virtual bool rozmnazanie()
	{
		unsigned short pole = 1;

		while ((getSwiat()->czyPoleNaPlanszy(getSwiat()->losujPole(pole) + this->polozenie) == false) || (getSwiat()->czyWolnePole(getSwiat()->losujPole(pole) + this->polozenie) == false))
		{
			if (pole > 10)
				return false;
			pole++;
		}
		PUNKT wylosowanePole = getSwiat()->losujPole();
		PUNKT docelowePole = wylosowanePole + this->polozenie;

		while ((getSwiat()->czyPoleNaPlanszy(docelowePole) == false) || (getSwiat()->czyWolnePole(docelowePole) == false))
		{
			wylosowanePole = getSwiat()->losujPole();
			docelowePole = this->polozenie + wylosowanePole;
		}

		this->getSwiat()->rozmnazajOrganizm(this, docelowePole);
		return true;
	}

	virtual void sprawdzKolizje() = 0;

	void setCzyZwierze(bool _czyZwierze) { czyZwierze = _czyZwierze; }

	void setDomyslnieAkcji(unsigned short _domyslnieAkcji) { domyslnieAkcji = _domyslnieAkcji; }

	void setSzansaNaAkcje(unsigned short _szansaNaAkcje) { szansaNaAkcje = _szansaNaAkcje; }



private:
	char symbol;
	unsigned short kolor;
	std::string nazwa;
	unsigned short sila;
	unsigned short inicjatywa;
	unsigned int wiek;
	unsigned short domyslnieAkcji; // zmienna na informacje ile akcji w turze ma domyslnie organizm
	unsigned short ileAkcji; // zmienna na informacje o tym czy organimz w danej turze ma dostepne akcje
	unsigned short szansaNaAkcje;

	bool dodatkowyRuch;	
	
	PUNKT polozenie;
	PUNKT przybywaZ;
	
	Swiat * swiat;
	bool czyZwierze;	
	bool rozmnazalSie;
};