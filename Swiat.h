#include <iostream>
#include <algorithm>
#include "PUNKT.h"
#pragma once

class Organizm;
class Swiat
{

public:
	/*
	Swiat& operator=(Swiat *tmp) {
		
		std::cout << "Kopiowanie swiata!";
		//for (int i = 0; i < 100; i++)
			//for (int j = 0; j < 100; j++)
				//std::cout << " ko pio wa nie! -!<>?>#$%GF\n";
		return *tmp;
	}*/
	
	Swiat(unsigned short rozmiar=20, unsigned short _iloscOrganizmow=60);
	~Swiat();
	/**/
	Swiat& operator = (Swiat& prawa) 
	{
		setRozmiarSwiata(prawa.getRozmiarSwiata());
		setIloscOrganizmow(prawa.getIloscOrganizmow());
		setIloscGatunkow(prawa.getIloscGatunkow());
		setLicznikTur(prawa.getLicznikTur());

		setIloscZwierzat(prawa.getIloscZwierzat());
		setIloscRoslin(prawa.getIloscRoslin());
		
		setIloscWilkow(prawa.getIloscWilkow());
		setIloscNiedzwiedzi(prawa.getIloscNiedzwiedzi());
		setIloscZmij(prawa.getIloscZmij());
		setIloscLeniwcow(prawa.getIloscLeniwcow());
		setIloscOwiec(prawa.getIloscOwiec());
		setIloscKoki(prawa.getIloscKoki());
		setIloscTrawy(prawa.getIloscTrawy());
		setIloscMleczu(prawa.getIloscMleczu());

		setPrzebiegTury(prawa.getPrzebiegTury());

		/*
		unsigned short rozmiarSwiata;		// liczba pól w poziomie / pionie dla kwadratowej planszy
		unsigned short iloscOrganizmow;		// ³¹czna iloœæ organizmów znajduj¹cych siê aktualnie w œwiecie
		unsigned short iloscGatunkow;		// dostêpna iloœæ rodzajów gatunków zwierz¹t i roœlin 
		unsigned short licznikTur;

		unsigned short iloscZwierzat;
		unsigned short iloscRoslin;

		unsigned short iloscWilkow;
		unsigned short iloscNiedzwiedzi;
		unsigned short iloscZmij;
		unsigned short iloscLeniwcow;
		unsigned short iloscOwiec;
		unsigned short iloscKoki;
		unsigned short iloscTrawy;
		unsigned short iloscMleczu;

		char przebiegTury = 'r';
		unsigned short licznikKomunikatow;

		Organizm** organizmy;				// tablica (kontener) na organizmy znajduj¹ce siê na œwiecie
		*/

		for (int i = 0; i < getIloscOrganizmow(); i++)
			setOrganizm(i, nullptr);


		delete[] organizmy;
		Organizm** organizmy = new Organizm * [this->getRozmiarSwiata() * this->getRozmiarSwiata()];

		for (int i = 0; i < getIloscOrganizmow(); i++)
			organizmy[i] = prawa.organizmy[i];
			//swap(i, getOrganizm(i), i, prawa.getOrganizm(i));
			
		this->organizmy = organizmy;

		return *this;
	}
	/*
	Swiat& operator = (Swiat* prawa)
	{
		setRozmiarSwiata(prawa->getRozmiarSwiata());
		setIloscOrganizmow(prawa->getIloscOrganizmow());
		setIloscGatunkow(prawa->getIloscGatunkow());
		setPrzebiegTury(prawa->getPrzebiegTury());
		setLicznikTur(prawa->getLicznikTur());
		setIloscWilkow(prawa->getIloscWilkow());
		setIloscNiedzwiedzi(prawa->getIloscNiedzwiedzi());
		setIloscZmij(prawa->getIloscZmij());
		setIloscLeniwcow(prawa->getIloscLeniwcow());
		setIloscOwiec(prawa->getIloscOwiec());
		setIloscKoki(prawa->getIloscKoki());
		setIloscTrawy(prawa->getIloscTrawy());
		setIloscMleczu(prawa->getIloscMleczu());

		for (int i = 0; i < getRozmiarSwiata()*getRozmiarSwiata(); i++)
			setOrganizm(i, nullptr);

		//delete[] this->organizmy;


		for (int i = 0; i < getIloscOrganizmow(); i++)
			setOrganizm(i, prawa->getOrganizm(i));
		//swap(i, getOrganizm(i), i, prawa->getOrganizm(i));

		//delete prawa;
		return *this;
	}
	*/
	void wyswietlKomunikat(std::string komunikat);
	void czyscKomunikat();
	void wykonajTure(char _klawisz);
	void rysujSwiat();
	bool czyPoleNaPlanszy(PUNKT p);
	bool czyWolnePole(PUNKT p);
	PUNKT losujPole();
	PUNKT losujPole(unsigned short punkt);
	void zjedzOrganizm(Organizm* zjadany);							// metoda usuwa z listy organizmów wskazany organizm
	
	void rysujPlansze(long, long, long, long);
	void rysujSwiatS(unsigned short offset);
	void rysujSwiatM(unsigned short offset);
	void rysujSwiatXL(unsigned short offset);
	bool koniecGry();
	char getPrzebiegTury();
	bool zapiszGre();
	Swiat* wczytajGre();
	bool setPrzebiegTury(char _klawisz);
	Organizm* getOrganizm(unsigned short i);
	unsigned short getRozmiarSwiata();
	unsigned short getIloscOrganizmow();
	void wyswietlRelacje(unsigned short flagaKategorii, unsigned short flagaHierarchii, std::string relacja); 
	friend std::ostream& operator<<(std::ostream& os,Swiat& swiat);
	void rozmnazajOrganizm(Organizm* rozsadzany, PUNKT cel);		// metoda rozsadzania roslin (jeden rodzic)
	void rozmnazajOrganizm(Organizm* rodzic, Organizm* partner);		// metoda rozmnazania zwierzat (dwoch rodzicow)

	void gotoxy(PUNKT p);
private:
	void wypiszSwiat(std::ostream& os);
	void sortujOrganizmy(int);
	virtual bool czyNaPoluZwierz(PUNKT p);
	bool czyZwierzSieRozmnozy(Organizm* zwierz);
	PUNKT poleDlaMlodegoZwierza(Organizm* rodzic);
	Organizm* cudNarodzin(Organizm* dawcaDNA, PUNKT nowyDom);		// metoda z zaimplementowan¹ fabryk¹ organizmów -> zwraca wskaŸnik do nowo utworzonego organizmu

	
	void rysujSwiatL();
	Organizm* raportZpola(PUNKT p);
	void inwentaryzujOrganizmy(bool przyrost, unsigned short indeks);
	void wyswietlStatystyki(PUNKT p);

	void swap(unsigned short _iLewy,Organizm* _lewy, unsigned short _iPrawy, Organizm* _prawy);

	//===========================================================
	// SETTERY

	void setRozmiarSwiata(unsigned short rozmiar);
	void setIloscOrganizmow(unsigned short _iloscOrganizmow);
	void setIloscZwierzat(unsigned short _iloscZwierzat);
	void setIloscRoslin(unsigned short _iloscRoslin);
	void setIloscGatunkow(unsigned short _iloscGatunkow);
	void setLicznikTur(unsigned short _licznikTur);

	void setIloscWilkow(unsigned short _iloscWilkow);
	void setIloscNiedzwiedzi(unsigned short _iloscNiedzwiedzi);
	void setIloscZmij(unsigned short _iloscZmij);
	void setIloscLeniwcow(unsigned short _iloscLeniwcow);
	void setIloscOwiec(unsigned short _iloscOwiec);
	void setIloscKoki(unsigned short _iloscKoki);
	void setIloscTrawy(unsigned short _iloscTrawy);
	void setIloscMleczu(unsigned short _iloscMleczu);

	void setLicznikKomunikatow(unsigned short _licznikKomunikatow);

	void setOrganizm(unsigned short i, Organizm* _organizm);

	//===========================================================
	// INKREMENTATORY
	void incIloscOrganizmow();
	void incLicznikTur();									// zwiêksza o 1 wartoœæ licznika tur
	void incLicznikKomunikatow();
	void incIloscZwierzat();
	void incIloscRoslin();

	void incIloscWilkow();
	void incIloscNiedzwiedzi();
	void incIloscZmij();
	void incIloscLeniwcow();
	void incIloscOwiec();
	void incIloscKoki();
	void incIloscTrawy();
	void incIloscMleczu();


	//===========================================================
	// DEREMENTATORY
	void decIloscOrganizmow();
	void decIloscZwierzat();
	void decIloscRoslin();

	void decIloscWilkow();
	void decIloscNiedzwiedzi();
	void decIloscZmij();
	void decIloscLeniwcow();
	void decIloscOwiec();
	void decIloscKoki();
	void decIloscTrawy();
	void decIloscMleczu();

	//===========================================================
	// GETTERY

	unsigned short getIloscGatunkow();
	unsigned short getLicznikTur();
	unsigned short getLicznikKomunikatow();

	unsigned short getIloscZwierzat();
	unsigned short getIloscRoslin();

	unsigned short getIloscWilkow();
	unsigned short getIloscNiedzwiedzi();
	unsigned short getIloscZmij();
	unsigned short getIloscLeniwcow();
	unsigned short getIloscOwiec();
	unsigned short getIloscKoki();
	unsigned short getIloscTrawy();
	unsigned short getIloscMleczu();

	void odswiezOrganizm(unsigned short indeksOrganizmu);
	
	void przedstawSie(unsigned short offset);

	void sortujInicjatywa(int, int);
	void sortujWiek(int, int);

	unsigned short rozmiarSwiata;		// liczba pól w poziomie / pionie dla kwadratowej planszy
	unsigned short iloscOrganizmow;		// ³¹czna iloœæ organizmów znajduj¹cych siê aktualnie w œwiecie
	unsigned short iloscGatunkow;		// dostêpna iloœæ rodzajów gatunków zwierz¹t i roœlin 
	unsigned short licznikTur;

	unsigned short iloscZwierzat;
	unsigned short iloscRoslin;

	unsigned short iloscWilkow;
	unsigned short iloscNiedzwiedzi;
	unsigned short iloscZmij;
	unsigned short iloscLeniwcow;
	unsigned short iloscOwiec;
	unsigned short iloscKoki;
	unsigned short iloscTrawy;
	unsigned short iloscMleczu;

	char przebiegTury = 'r';
	unsigned short licznikKomunikatow;

	Organizm** organizmy;				// tablica (kontener) na organizmy znajduj¹ce siê na œwiecie

};