#include <iostream>
#include <conio.h>
#include <time.h>
#include "Swiat.h"
#include "Wilk.h"
#include "Zmija.h"
#include "Leniwiec.h"
#include "Mlecz.h"
#include "Koka.h"
#include "Trawa.h"
#include "Owca.h"
#include "Niedzwiedz.h"
#include <iostream>
#include <fstream>


bool Swiat::setPrzebiegTury(char _klawisz)
{
	if ((_klawisz == 's') || (_klawisz == 'S'))
	{
		przebiegTury = 's';
		return true;
	}
	else if ((_klawisz == 'r') || (_klawisz == 'R'))
	{
		przebiegTury = 'r';
		return true;
	}
	else if ((_klawisz == 't') || (_klawisz == 'T'))
	{
		przebiegTury = 't';
		return true;
	}
	else if ((_klawisz == 'q') || (_klawisz == 'Q'))
	{
		przebiegTury = 'q';
		return true;
	}
	else if ((_klawisz == 'a') || (_klawisz == 'A'))
	{
		przebiegTury = 'a';
		return true;
	}
	else if ((_klawisz == 'z') || (_klawisz == 'Z'))
	{
		przebiegTury = 'z';
		return true;
	}
	else if ((_klawisz == 'w') || (_klawisz == 'W'))
	{
		przebiegTury = 'w';
		return true;
	}

	else przebiegTury = 'n'; //nienazwany
	return false;
}

void Swiat::rysujSwiat()
{
	
	char rozmiarPlanszy = 'S';

	if (this->getRozmiarSwiata() <= 20)
		rozmiarPlanszy = 'S';
	else if (this->getRozmiarSwiata() <= 40)
		rozmiarPlanszy = 'M';
	else if (this->getRozmiarSwiata() <= 60)
		rozmiarPlanszy = 'L';
	else if (this->getRozmiarSwiata() > 60)
		rozmiarPlanszy = 'X';

	switch (rozmiarPlanszy)
	{
	case 'S':
		rysujSwiatS(20);
		break;
	case 'M':
		rysujSwiatM(20);
		break;
	case 'L':
		rysujSwiatL();
		break;
	case 'X':
		rysujSwiatXL(17);
		break;
	default:
		rysujSwiatXL(17);
	}	
}

void Swiat::gotoxy(PUNKT p)
{
	unsigned short xOffset = 18;
	unsigned short yOffset = 14;
	if (this->getRozmiarSwiata() <= 20)
	{
		p.setX(4 * p.getX() + 21);
		p.setY(2 * p.getY() + 19);
		printf("\033[%d;%dH", p.getY(), p.getX());
	}
	else {
		//p.setX(p.getY() + xOffset);
		printf("\033[%d;%dH", p.getY()+yOffset, p.getX()+xOffset);
	}
}

void Swiat::rysujPlansze(long gora, long lewo, long dol, long prawo )
{
	system("CLS");
	long szerokosc = prawo - lewo;
	long wysokosc = dol - gora;
	
	for (int i = 0; i < szerokosc / 190; i++)
		std::cout << " ";
	std::cout << "\311";

	for (int i = 0; i < szerokosc / 9 ; i++)
		std::cout << "\315";
	std::cout << "\273\n";

	for (int i = 0; i < wysokosc / 18; i++)
	{
		for (int j = 0; j < szerokosc / 190; j++)
			std::cout << " ";
		std::cout << "\272";
		for (int j = 0; j < szerokosc / 9; j++)
			std::cout << " ";
		std::cout << "\272\n";
	}


	for (int i = 0; i < szerokosc / 190; i++)
		std::cout << " ";
	std::cout << "\310";

	for (int i = 0; i < szerokosc / 9; i++)
		std::cout << "\315";
	std::cout << "\274\n";

	if (this->getRozmiarSwiata() <= 20)
		rysujSwiatS(17);
	else
		rysujSwiatXL(17);

}

void Swiat::przedstawSie(unsigned short offset)
{
	unsigned short vOffset = 2;
	printf("\033[%d;%dH", vOffset, offset);
	std::cout << "ADAM CHOJACZYK - ALBUM 183269";
	printf("\033[%d;%dH", vOffset+1, offset);
	std::cout << "WIRTUALNY \227WIAT";
	printf("\033[%d;%dH", vOffset + 2, offset);
	std::cout << "J\250ZYKI PROGRAMOWANIA OBIEKTOWEGO";

	printf("\033[%d;%dH", vOffset + 3, offset-2);
	std::cout << "====================================================================================";
	printf("\033[%d;%dH", vOffset + 4, offset);
	std::cout << "=== NAWIGACJA ===================";
	printf("\033[%d;%dH", vOffset + 5, offset);
	std::cout << "< R > - KOLEJNY RUCH";
	printf("\033[%d;%dH", vOffset + 7, offset);
	std::cout << "< T > - KOLEJNA TURA (akcja po akcji)";
	printf("\033[%d;%dH", vOffset + 8, offset);
	std::cout << "< A > - KOLEJNA TURA (szybka rozgrywka)";
	printf("\033[%d;%dH", vOffset + 9, offset);
	std::cout << "< S > - ROZEGRAJ DO KONCA (akcja po akcji)";
	printf("\033[%d;%dH", vOffset + 10, offset - 1);
	std::cout << "====================================================================================";
	
	
}

void Swiat::rysujSwiatS(unsigned short offset) 
{
	// ==============================================================
	// pierwszy wiersz
	// ==============================================================
	przedstawSie(offset);
	int iOrg = 0;
	unsigned short vOffset = 17;
	bool trafiony = false;
	printf("\033[%d;%dH", vOffset, offset);
	std::cout << "  \263";
	for (int i = 0; i < this->getRozmiarSwiata() ; i++)
	{
		std::cout << " " << i;
		if(i<10) std::cout<< " \263";
		else std::cout<< "\263"; 
	}
	std::cout <<  "\n";
	printf("\033[%d;%dH", vOffset+1, offset);
	std::cout << "\304\304\305";
	for (int i = 0; i < this->getRozmiarSwiata() - 1; i++)
	{
		std::cout << "\304\304\304\305";
	}
	std::cout << "\304\304\304\264\n";

	printf("\033[%d;%dH", vOffset+2, offset);
	std::cout << "0 \263";
	for (int i = 0; i < this->getRozmiarSwiata(); i++)
	{		
		//=======================================================================================================
		//============ SYMBOL ORGANIZMU ========================================================================= 
		//=======================================================================================================
		iOrg = 0;
		trafiony = false;
		for(iOrg = 0 ; iOrg < getIloscOrganizmow() ; iOrg++)
		{
			if ((getOrganizm(iOrg)->getPolozenie().getY() == 0) && (getOrganizm(iOrg)->getPolozenie().getX() == i))
			{
				std::cout << "\040";
				getOrganizm(iOrg)->rysowanie();
				trafiony = true;
					std::cout << "\040\263";
				break;
			}
		} 
		if (trafiony == false)
		{
			if (i < getRozmiarSwiata())
				std::cout << "\040\040";

			//=======================================================================================================

			std::cout << "\040\263";
		}
	}
	std::cout << "\n";
	printf("\033[%d;%dH", vOffset+3, offset);
	// ==============================================================
	// srodek
	// ==============================================================

	for (int j = 1; j < this->getRozmiarSwiata(); j++)
	{
		std::cout << "\304\304\305";
		for (int i = 0; i < this->getRozmiarSwiata(); i++)
		{
			std::cout << "\304\304\304\305";
		}		
		std::cout<<"\010\264\n";
		printf("\033[%d;%dH", vOffset+2+2*j, offset);
		std::cout << j;
		if (j < 10) std::cout << " \263";
		else std::wcout << "\263";
		for (int i = 0; i < this->getRozmiarSwiata(); i++)
		{			
			//=======================================================================================================
			//  <============ SYMBOL ORGANIZMU
			iOrg = 0;
			trafiony = false;
			for(iOrg = 0 ; iOrg<getIloscOrganizmow() ; iOrg++)
			{
				if ((getOrganizm(iOrg)->getPolozenie().getY() == j) && (getOrganizm(iOrg)->getPolozenie().getX() == i))
				{
					std::cout << "\040";
					getOrganizm(iOrg)->rysowanie();
					trafiony = true;
						std::cout << "\040\263";
					break;
				}
			}
			if (trafiony == false)
			{
				if (i < getRozmiarSwiata())
					std::cout << "\040\040";

	//=======================================================================================================

				std::cout << "\040\263";
			}
		}			
			std::cout << "\n";
			printf("\033[%d;%dH", vOffset+3+2*j, offset);
	}
	// ==============================================================
	// ostatni wiersz
	// ==============================================================
	printf("\033[%d;%dH", vOffset+41, offset);
	std::cout << "\304\304\301";
	for (int i = 0; i < this->getRozmiarSwiata() - 1; i++)
	{
		std::cout << "\304\304\304\301";
	}
	std::cout << "\304\304\304\331\n";
}

void Swiat::rysujSwiatM(unsigned short offset)
{
	// ==============================================================
	// pierwszy wiersz
	// ==============================================================
	std::cout << "RYSUJE SWIAT\n";

	std::cout << "\332";
	for (int i = 0; i < this->getRozmiarSwiata() - 1; i++)
	{
		std::cout << "\304\304\302";
	}
	std::cout << "\304\304\277\n";
	// ==============================================================
	// srodek
	// ==============================================================

	for (int j = 0; j < this->getRozmiarSwiata() - 1; j++)
	{
		std::cout << "\303";
		for (int i = 0; i < this->getRozmiarSwiata() - 1; i++)
		{
			std::cout << "\304\304\305";
		}
		std::cout << "\304\304\264\n";
	}
	// ==============================================================
	// ostatni wiersz
	// ==============================================================
	std::cout << "\300";
	for (int i = 0; i < this->getRozmiarSwiata() - 1; i++)
	{
		std::cout << "\304\304\301";
	}
	std::cout << "\304\304\331\n";

	printf("\033[%d;%dH", 4, 5);
	std::cout << "\100";

	printf("\033[%d;%dH", 9, 11);
	std::cout << "\100";

	printf("\033[%d;%dH", 16, 19);
	std::cout << "\100";
	printf("\033[%d;%dH", this->getRozmiarSwiata() + 5, 2);

}

void Swiat::rysujSwiatL() 
{

}

void Swiat::rysujSwiatXL(unsigned short offset)
{
	przedstawSie(offset);
	int iOrg = 0;
	unsigned short vOffset = 13;
	bool trafiony = false;
	printf("\033[%d;%dH", vOffset, offset);
	// ==============================================================
	// pierwszy wiersz
	// ==============================================================
	std::cout << "\332";
	for (int i = 0; i < this->getRozmiarSwiata(); i++)
		std::cout << "\304";
	std::cout << "\277\n";

	// ==============================================================
	// œrodek planszy
	// ==============================================================
	
	iOrg = 0;
	for (int j = 0; j < this->getRozmiarSwiata(); j++)
	{
		vOffset++;
		printf("\033[%d;%dH", vOffset, offset);
		std::cout << "\263";
		for (int i = 0; i < this->getRozmiarSwiata(); i++)
		{	
			iOrg = 0;
			while ((getOrganizm(iOrg)!=nullptr)&&(iOrg<getRozmiarSwiata()*getRozmiarSwiata()))
			{				
				if ((getOrganizm(iOrg)->getPolozenie().getX() == j) && (getOrganizm(iOrg)->getPolozenie().getY() == i))
				{
					gotoxy(PUNKT(i, j));
					getOrganizm(iOrg)->rysowanie();
					iOrg = 0;
					break;
				}				
				iOrg++;				
			}
			if(i<getRozmiarSwiata())
			{
				gotoxy(PUNKT(i+1, j));
				std::cout << " ";
			}
		}
		gotoxy(PUNKT(this->getRozmiarSwiata(), j));
		std::cout << "\263\n";
	}


	// ==============================================================
	// ostatni wiersz
	// ==============================================================
	vOffset++;
	printf("\033[%d;%dH", vOffset, offset);
	std::cout << "\300";
	for (int i = 0; i < this->getRozmiarSwiata(); i++)
		std::cout << "\304";
	std::cout << "\331\n";

}

void Swiat::wykonajTure(char _klawisz)
{
	incLicznikTur();
	PUNKT pe = { 150,6 };
	if(getPrzebiegTury()=='a')
		wyswietlStatystyki(pe);
	setPrzebiegTury(_klawisz);
	
	sortujOrganizmy(getIloscOrganizmow());
	for (int i = 0; i < getIloscOrganizmow(); i++)
	{	
		if (getOrganizm(i)->getIleAkcji() > 0)
		{
			if (getPrzebiegTury() == 'r')
			{
				char klawisz = 'n';
				while (setPrzebiegTury(klawisz) == false)
				{
					klawisz = _getch();
				}
			}	
			std::string komunikat = "Tura [" + std::to_string(getLicznikTur())+"] ruch wykonuje " + getOrganizm(i)->getNazwa() + " ("+ std::to_string(i) + ") z pola [" + std::to_string(getOrganizm(i)->getPolozenie().getX())+"," + std::to_string(getOrganizm(i)->getPolozenie().getY()) +"]"  ;
			wyswietlRelacje(99, 3, komunikat);

			koniecGry();

			getOrganizm(i)->akcja();
			
			if (getPrzebiegTury() != 'a')
			{
				odswiezOrganizm(i);
				
				wyswietlStatystyki(pe);
			}

		}
		
		if(i<getIloscOrganizmow())
  			getOrganizm(i)->incWiek(); 			
	}
	for (int i = 0; i < getIloscOrganizmow(); i++)
	{
		getOrganizm(i)->setIleAkcji(getOrganizm(i)->getIleAkcji() + getOrganizm(i)->getDomyslnieAkcji());
		getOrganizm(i)->setRozmnazalSie(false);
		if (getOrganizm(i)->getDodatkowyRuch())
		{
			getOrganizm(i)->setDodatkowyRuch(false);
			getOrganizm(i)->incIleAkcji();
		}
	}
	if (getPrzebiegTury() == 'a')
		wyswietlStatystyki(pe);
}

void Swiat::odswiezOrganizm(unsigned short indeksOrganizmu)
{
	if (getOrganizm(indeksOrganizmu) != nullptr) // tu cos trzeba uwa¿aæ!
	{
		gotoxy(getOrganizm(indeksOrganizmu)->getPolozenie());
		getOrganizm(indeksOrganizmu)->rysowanie();
		for (unsigned short i = 1; i < 10; i++)
		{
			PUNKT odswiezanePole = losujPole(i);
			odswiezanePole= getOrganizm(indeksOrganizmu)->getPolozenie()+ odswiezanePole;
			for (unsigned short j = 0; j < getIloscOrganizmow(); j++)
			{
				if ((odswiezanePole.getX() >= 0) && (odswiezanePole.getY() >= 0) && (odswiezanePole.getX() < getRozmiarSwiata()) && (odswiezanePole.getY() < getRozmiarSwiata()))
				{					
					if ((getOrganizm(j)->getPolozenie().getX() == odswiezanePole.getX()) && (getOrganizm(j)->getPolozenie().getY() == odswiezanePole.getY()))
					{
						gotoxy(odswiezanePole);
						getOrganizm(j)->rysowanie();
						break;
					}
					gotoxy(odswiezanePole);
					std::cout << " ";
				}
			}
		}
	}
}

bool Swiat::czyPoleNaPlanszy(PUNKT p)
{
	if ((p.getX() >= 0) && (p.getY() >= 0) && (p.getX() < getRozmiarSwiata()) && (p.getY() < getRozmiarSwiata()))
		return true;
	else return false;
}

bool Swiat::czyWolnePole(PUNKT p)
{
	for (unsigned short i = 0; i < getIloscOrganizmow(); i++)
	{
		if (getOrganizm(i) != nullptr)
			if ((getOrganizm(i)->getPolozenie().getX() == p.getX()) && (getOrganizm(i)->getPolozenie().getY() == p.getY()))
				return false;
	}
	return true;
}

PUNKT Swiat::losujPole()				// metoda zwraca losowy punkt wzgledem organizmu na jakim zostala wykonana 
{
	PUNKT przesunSieO = { 0,0 };
	unsigned short pole = rand() % 9 + 1;	// wartosci liczb calkowitych od 1 do 9 okreslaja kolejne pola wokol pola bazowego

	switch (pole)
	{
	case 1:
		przesunSieO = { -1,-1 };
		break;
	case 2:
		przesunSieO = { 0,-1 };
		break;
	case 3:
		przesunSieO = { 1,-1 };
		break;
	case 4:
		przesunSieO = { 1,0 };
		break;
	case 5:
		przesunSieO = { 1,1 };
		break;
	case 6:
		przesunSieO = { 0,1 };
		break;
	case 7:
		przesunSieO = { -1,1 };
		break;
	case 8:
		przesunSieO = { -1,0 };
		break;

	default: przesunSieO = { 0,0 };
	}
	return przesunSieO;
}

PUNKT Swiat::losujPole(unsigned short pole)
{
	PUNKT przesunSieO = { 0,0 };

	switch (pole)
	{
	case 1:
		przesunSieO = { -1,-1 };
		break;
	case 2:
		przesunSieO = { 0,-1 };
		break;
	case 3:
		przesunSieO = { 1,-1 };
		break;
	case 4:
		przesunSieO = { 1,0 };
		break;
	case 5:
		przesunSieO = { 1,1 };
		break;
	case 6:
		przesunSieO = { 0,1 };
		break;
	case 7:
		przesunSieO = { -1,1 };
		break;
	case 8:
		przesunSieO = { -1,0 };
		break;
	case 9:
		przesunSieO = { 0,0 };
		break;
	default: przesunSieO = { 0,0 };
	}
	return przesunSieO;
}

Organizm* Swiat::cudNarodzin(Organizm* dawcaDNA, PUNKT nowyDom)
{
	std::string nazwaDawcy = dawcaDNA->getNazwa();
	if (nazwaDawcy == "Wilk")
	{
		incIloscZwierzat();
		incIloscWilkow();
		return new Wilk(nowyDom, this); 
	}

	else if (nazwaDawcy == "Misio")
	{
		incIloscZwierzat();
		incIloscNiedzwiedzi();
		return new Niedzwiedz(nowyDom, this);
	}
	else if (nazwaDawcy == "Owca")
	{
		incIloscZwierzat();
		incIloscOwiec();
		return new Owca(nowyDom, this);
	}
	else if (nazwaDawcy == "Zmija")
	{
		incIloscZwierzat();
		incIloscZmij();
		return new Zmija(nowyDom, this);
	}
	else if (nazwaDawcy == "Leniwiec") {
		incIloscZwierzat();
		incIloscLeniwcow();
		return new Leniwiec(nowyDom, this,true);
	}
	else if (nazwaDawcy == "Trawa")
	{
		incIloscRoslin();
		incIloscTrawy();
		return new Trawa(nowyDom, this);
	}
	else if (nazwaDawcy == "Koka")
	{
		incIloscRoslin();
		incIloscKoki();
		return new Koka(nowyDom, this);
	}
	else if (nazwaDawcy == "Mlecz")
	{
		incIloscRoslin();
		incIloscMleczu();
		return new Mlecz(nowyDom, this);
	}
	else return new Mlecz(nowyDom, this);	
}

void Swiat::zjedzOrganizm(Organizm* zjadany)
{
	std::string komunikat;
	komunikat= "zjadany ==> " + zjadany->getNazwa() + " [ " + std::to_string(zjadany->getPolozenie().getX()) + " , " + std::to_string(zjadany->getPolozenie().getY()) + " ]\n";
	//wyswietlRelacje(2,0,komunikat);
	// std::cout << "zjadany ==> " << zjadany->nazwa << " [ " << zjadany->polozenie.getX() << " , " << zjadany->polozenie.getY() << " ]\n";
	
	for (int i = 0; i < getIloscOrganizmow(); i++)
	{
		if (((getOrganizm(i)->getPolozenie().getX()) == zjadany->getPolozenie().getX()) &&
			((getOrganizm(i)->getPolozenie().getY()) == zjadany->getPolozenie().getY()) &&
			((getOrganizm(i)->getNazwa()) == (zjadany->getNazwa()))
			)
		{
			if ((getRozmiarSwiata() <= 20)&&(getPrzebiegTury()!='a'))
				odswiezOrganizm(i);
			inwentaryzujOrganizmy(false, i);

			setOrganizm(i,nullptr);

			swap(i,getOrganizm(i), getIloscOrganizmow()-1,getOrganizm(getIloscOrganizmow() - 1));
			decIloscOrganizmow();
			break;
		}
	}
}

bool Swiat::czyNaPoluZwierz(PUNKT p)
{
	for (unsigned short i = 0; i < getIloscOrganizmow(); i++)
	{
		if (getOrganizm(i) != nullptr)
			if ((getOrganizm(i)->getPolozenie().getX() == p.getX()) && (getOrganizm(i)->getPolozenie().getY() == p.getY()))
				if (getOrganizm(i)->getCzyZwierze() == true)
					return true;
	}
	return false;
}

bool Swiat::czyZwierzSieRozmnozy(Organizm* zwierz)
{
	for (int i = 1; i < 10; i++)
	{
		PUNKT losowePole = losujPole(i);
		losowePole = zwierz->getPolozenie()+losowePole ;

		if ((czyPoleNaPlanszy(losowePole) == true) && (czyNaPoluZwierz(losowePole) == false))
			return true;
	}
	return false;
}

PUNKT Swiat::poleDlaMlodegoZwierza(Organizm* rodzic)
{
	PUNKT losowePole = losujPole();
	losowePole = rodzic->getPolozenie()+ losowePole;
	while ((czyPoleNaPlanszy(losowePole) == false) || (czyNaPoluZwierz(losowePole) == true))
	{
		losowePole = rodzic->getPolozenie();
		losowePole = losujPole()+ losowePole;
	}
	return losowePole;
}

void Swiat::rozmnazajOrganizm(Organizm* rozsadzany, PUNKT cel)
{
	{
		setOrganizm(getIloscOrganizmow(),cudNarodzin(rozsadzany, cel));
		incIloscOrganizmow();
		sortujOrganizmy(getIloscOrganizmow());
	}
}

void Swiat::rozmnazajOrganizm(Organizm* rodzic, Organizm* partner)
{
	
	//std::cout << "\nTu beda sie rozmnazaly" << rodzic->nazwa << " [ " << rodzic->polozenie.getX() << " , " << rodzic->polozenie.getY() << " ] i ";
	//std::cout << partner->nazwa << " [ " << partner->polozenie.getX() << " , " << partner->polozenie.getY() << " ] " << " niech probuja ;) !\n ";
	if (czyZwierzSieRozmnozy(rodzic))
	{
		PUNKT poleNowegoZwierza = poleDlaMlodegoZwierza(rodzic);
		//std::cout << "Wokol INICJATORA znalazlo sie miejsce dla mlodego: [ " << poleNowegoZwierza.getX() << " , " << poleNowegoZwierza.getY() << " ]\n";
		Organizm * czyRoslinaNaPolu = raportZpola(poleNowegoZwierza);
		if ((getIloscOrganizmow() < (getRozmiarSwiata() * getRozmiarSwiata())) || (czyRoslinaNaPolu != nullptr))
		{		
			setOrganizm(getIloscOrganizmow(),cudNarodzin(rodzic, poleNowegoZwierza));
			incIloscOrganizmow(); 
			
			sortujOrganizmy(getIloscOrganizmow());
			if (czyRoslinaNaPolu != nullptr) 
				zjedzOrganizm(czyRoslinaNaPolu);
			sortujOrganizmy(getIloscOrganizmow());
		}		
	}
	else if (czyZwierzSieRozmnozy(partner))
	{
		PUNKT poleNowegoZwierza = poleDlaMlodegoZwierza(partner);
		
		//std::cout << "Wokol PARTNERA znalazlo sie miejsce dla mlodego: [ " << poleNowegoZwierza.getX() << " , " << poleNowegoZwierza.getY() << " ]\n";
		Organizm* czyRoslinaNaPolu = raportZpola(poleNowegoZwierza);
		if ((getIloscOrganizmow() < (getRozmiarSwiata() * getRozmiarSwiata())) || (czyRoslinaNaPolu != nullptr))
		{
			setOrganizm(getIloscOrganizmow(), cudNarodzin(partner, poleNowegoZwierza));
			std::string komunikat = "Rodzi sie " + partner->getNazwa() + " na polu [" + std::to_string(partner->getPolozenie().getX()) + "," + std::to_string(partner->getPolozenie().getY())+"]";
			wyswietlRelacje(1, 1, komunikat);
			incIloscOrganizmow();
			if (czyRoslinaNaPolu != nullptr)
				zjedzOrganizm(czyRoslinaNaPolu);
			sortujOrganizmy(getIloscOrganizmow());
		}
	}
	else
	{
		//std::cout << "Niestety! Nie ma wolnego pola do rozmnazania :/ (Error - niedogodne warunki lokalowe) \n";
	}
}

Organizm* Swiat::raportZpola(PUNKT p)
{
	bool czyCosJestNaPolu = false;
	for (unsigned short i = 0; i < getIloscOrganizmow(); i++)
	{
		if (getOrganizm(i) != nullptr)
		{
			if ((getOrganizm(i)->getPolozenie().getX() == p.getX()) && (getOrganizm(i)->getPolozenie().getY() == p.getY()))
			{
				czyCosJestNaPolu = true;
				//std::cout << "Na polu [ " << p.getX() << " , " << p.getY() << " ] znajduje sie " << getOrganizm(i)->nazwa << "\n";
				return getOrganizm(i);
			}
		}
	}
	if (czyCosJestNaPolu == false)
	{
		//std::cout << "Na polu [ " << p.getX() << " , " << p.getY() << " ] NIC NIE MA!\n";
		return nullptr;
	}
	return nullptr;
}

void Swiat::sortujInicjatywa(int left, int right)
{
	int i = left;
	int j = right;
	int x = getOrganizm((left + right) / 2)->getInicjatywa();
	do
	{
		while (getOrganizm(i)->getInicjatywa() > x)
			i++;

    		while (getOrganizm(j)->getInicjatywa() < x)
			j--;

		if (i <= j) 
		{
			swap(i,getOrganizm(i), j,getOrganizm(j));

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) sortujInicjatywa(left, j);

	if (right > i) sortujInicjatywa(i, right);

}

void Swiat::sortujWiek(int left, int right)
{
	int i = left;
	int j = right;
	unsigned short x = getOrganizm((left + right) / 2)->getWiek();
	do
	{
		while (getOrganizm(i)->getWiek() > x)
			i++;

		while (getOrganizm(j)->getWiek() < x)
			j--;

		if (i <= j)
		{
			swap(i,getOrganizm(i), j,getOrganizm(j));

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) sortujWiek(left, j);

	if (right > i) sortujWiek(i, right);

}

void Swiat::sortujOrganizmy(int iOrg)
{
	//std::cout << "sortujOrganizmy = iOrg = " << iOrg << std::endl;
	Swiat::sortujInicjatywa(0, iOrg - 1);

	unsigned short ileInicjatyw = 1;
	for (int i = 1; i < iOrg; i++) // PÊTLA ZLICZA ILE RÓ¯NYCH POZIOMÓW INICJATYWY JEST WŒRÓD WSZYSTKICH ORGANIZMÓW
	{
		if (getOrganizm(i)->getInicjatywa() != getOrganizm(i - 1)->getInicjatywa())
			ileInicjatyw++;
	}

	PUNKT* przedzialyInicjatywy = new PUNKT[ileInicjatyw];
	przedzialyInicjatywy[0].setX(0);
	unsigned short pInicjatywy = 0;

	for (int i = 1; i < iOrg; i++) // PÊTLA UZUPE£NIA TABLICÊ PRZEDZIA£ÓW W JAKICH ZNAJDUJ¥ SIÊ RÓ¯NE POZIOMY INICJATYWY
	{
		if ((getOrganizm(i)->getInicjatywa() != getOrganizm(i - 1)->getInicjatywa()) || (i == iOrg - 1))
		{
			przedzialyInicjatywy[pInicjatywy].setY(i - 1);
			pInicjatywy++;
			if (pInicjatywy >= ileInicjatyw)
			{
				przedzialyInicjatywy[ileInicjatyw - 1].setY(iOrg - 1);
				break;
			}
			else
				przedzialyInicjatywy[pInicjatywy].setX(i);
		}
	}
	
	for (int i = 0; i < ileInicjatyw; i++)	// PÊTLA, DLA KOLEJNYCH PRZEDZIA£ÓW INICJATYWY SPRAWDZA CZY S¥ TO PRZEDZIA£Y "NIEJEDNO-ELEMENTOWE"
	{										// A NASTÊPNIE WYKONUJE WEWN¥TRZ TYCH PRZEDZIA£ÓW SORTOWANIE WG WIEKU
		if ((przedzialyInicjatywy[i].getY() - przedzialyInicjatywy[i].getX()) > 0)
			Swiat::sortujWiek(przedzialyInicjatywy[i].getX(), przedzialyInicjatywy[i].getY());
	}
}

void Swiat::inwentaryzujOrganizmy(bool przyrost,unsigned short i)
{
	if (przyrost == true)
	{
		if (getOrganizm(i)->getCzyZwierze() == true)
		{
			incIloscZwierzat();
			if (getOrganizm(i)->getNazwa() == "Wilk") incIloscWilkow();
			else if (getOrganizm(i)->getNazwa() == "Misio") incIloscNiedzwiedzi();
			else if (getOrganizm(i)->getNazwa() == "Zmija") incIloscZmij();
			else if (getOrganizm(i)->getNazwa() == "Owca") incIloscOwiec();
			else if (getOrganizm(i)->getNazwa() == "Leniwiec") incIloscLeniwcow();
		}
		else
		{
			incIloscRoslin();
			if (getOrganizm(i)->getNazwa() == "Trawa") incIloscTrawy();
			else if (getOrganizm(i)->getNazwa() == "Mlecz") incIloscMleczu();
			else if (getOrganizm(i)->getNazwa() == "Koka") incIloscKoki();
		}
	}
	else if (przyrost == false)
	{
		if (getOrganizm(i)->getCzyZwierze() == true)
		{
			decIloscZwierzat();
			if (getOrganizm(i)->getNazwa() == "Wilk") decIloscWilkow();
			else if (getOrganizm(i)->getNazwa() == "Misio") decIloscNiedzwiedzi();
			else if (getOrganizm(i)->getNazwa() == "Zmija") decIloscZmij();
			else if (getOrganizm(i)->getNazwa() == "Owca") decIloscOwiec();
			else if (getOrganizm(i)->getNazwa() == "Leniwiec") decIloscLeniwcow();
		}
		else
		{
			decIloscRoslin();
			if (getOrganizm(i)->getNazwa() == "Trawa") decIloscTrawy();
			else if (getOrganizm(i)->getNazwa() == "Mlecz") decIloscMleczu();
			else if (getOrganizm(i)->getNazwa() == "Koka") decIloscKoki();
		}
	}
}

void Swiat::wyswietlStatystyki(PUNKT p)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	
	printf("\033[%d;%dH", p.getY(),p.getX()-20 );
	std::cout << "STATYSTYKI SWIATA      |  TURA  " << getLicznikTur();
	printf("\033[%d;%dH", p.getY()+1, p.getX()-25);
	std::cout << "========================================================";

	printf("\033[%d;%dH", p.getY() + 2, p.getX() - 20);
	std::cout << "Organizmow ogolem:                       ";
	printf("\033[%d;%dH", p.getY() + 2, p.getX());
	std::cout<< this->getIloscOrganizmow();
	SetConsoleTextAttribute(hConsole, 12);
	printf("\033[%d;%dH", p.getY() + 3, p.getX() - 20);
	//SetConsoleTextAttribute(hConsole, 124);
	std::cout << "Zwierzat ogolem:                         ";
	printf("\033[%d;%dH", p.getY() + 3, p.getX());
	std::cout << getIloscZwierzat();
	SetConsoleTextAttribute(hConsole, 10);
	printf("\033[%d;%dH", p.getY() + 4, p.getX() - 20);
	std::cout << "Roslin ogolem:                           ";
	printf("\033[%d;%dH", p.getY() + 4, p.getX());
	std::cout<< getIloscRoslin();

	printf("\033[%d;%dH", p.getY() + 5, p.getX() - 20);
	float pZ = 50 * getIloscZwierzat() / getIloscOrganizmow();
	int procentZwierzat = (int)pZ;
	SetConsoleTextAttribute(hConsole, 12);	
	printf("\033[%d;%dH", p.getY() + 5, p.getX() - 20);
	for (int i = 0; i < procentZwierzat; i++)
	{
		std::cout << "\262";
	}

	SetConsoleTextAttribute(hConsole, 10);
	
	for (int i = procentZwierzat; i <50 ; i++)
	{
		printf("\033[%d;%dH", p.getY() + 5, p.getX() - 20 + i);
		std::cout << "\262";
	}
	//================================================================================
	// statystyki poszczególnych organizmow
	//================================================================================
	unsigned short wiersz = 0;
	printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscWilkow() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 8);
		std::cout << "       Wilki [W] ";
		pZ = 50 * getIloscWilkow() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;		
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";
		}
		std::cout << " (" << getIloscWilkow() << " - " << 2 * procentOrganizmow << "%)";
		wiersz++;
	}
	printf("\033[%d;%dH", p.getY() + 7+wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscOwiec() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "        Owce [\317] ";
		pZ = 50 * getIloscOwiec() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;
		
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";
		}
		std::cout << " (" << getIloscOwiec() << " - " << 2 * procentOrganizmow << "%)";
		wiersz++;
	}

	printf("\033[%d;%dH", p.getY() + 7+wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscLeniwcow() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << "     Leniwce [\351] ";
		pZ = 50 * getIloscLeniwcow() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";
		}
		std::cout << " (" << getIloscLeniwcow() << " - " << 2 * procentOrganizmow << "%)";
		wiersz++;
	}
	
	printf("\033[%d;%dH", p.getY() + 7+wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscZmij() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 13);
		std::cout << "       Zmije [\270] ";
		pZ = 50 * getIloscZmij() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";
		}
		std::cout << " (" << getIloscZmij() << " - " << 2 * procentOrganizmow << "%)";
		wiersz++;
	}
		
	printf("\033[%d;%dH", p.getY() + 7+wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscNiedzwiedzi() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Niedzwiedzie [\345] ";
		pZ = 50 * getIloscNiedzwiedzi() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";
		}
		std::cout << " (" << getIloscNiedzwiedzi() << " - " << 2*procentOrganizmow << "%)";
		wiersz++;
	}

	printf("\033[%d;%dH", p.getY() + 7+wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscTrawy() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "       Trawa [\261] ";
		pZ = 50 * getIloscTrawy() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";			
		}
		std::cout << " (" << getIloscTrawy() << " - " << 2 * procentOrganizmow << "%)";
		wiersz++;
	}
	
	printf("\033[%d;%dH", p.getY() + 7+wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscMleczu() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "       Mlecz [\365] ";
		pZ = 50 * getIloscMleczu() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";
		}
		std::cout << " (" << getIloscMleczu() << " - " << 2 * procentOrganizmow << "%)";
		wiersz++;
	}
	
	printf("\033[%d;%dH", p.getY() + 7+wiersz, p.getX() - 37);
	std::cout << "                                                                               ";
	if (getIloscKoki() > 0)
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "        Koka [\200] ";
		pZ = 50 * getIloscKoki() / getIloscOrganizmow();
		int procentOrganizmow = (int)pZ;
		for (int i = 0; i < procentOrganizmow; i++)
		{
			std::cout << "\262";
		}
		std::cout << " (" << getIloscKoki() << " - " << 2 * procentOrganizmow << "%)";
		wiersz++;
	}
	for (int i = wiersz; i <= getIloscGatunkow(); i++);
	{
		printf("\033[%d;%dH", p.getY() + 7 + wiersz, p.getX() - 37);
		std::cout << "                                                                               ";
	}

	SetConsoleTextAttribute(hConsole, 15);
}

void Swiat::wyswietlRelacje(unsigned short flagaKategorii, unsigned short flagaHierarchii, std::string relacja)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	PUNKT p = { 0,0 };
	//if (getRozmiarSwiata() <= 20)
		p = { 110,27 }; // sparametryzowaæ w zale¿noœci od rozmiaru planszy
	if (flagaKategorii == 99)
	{
		SetConsoleTextAttribute(hConsole, 112);
		printf("\033[%d;%dH", p.getY() - 3, p.getX());
		std::cout << "                                                                                    ";
		printf("\033[%d;%dH", p.getY() - 3, p.getX());
		std::cout << relacja;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		for (unsigned short i = 0; i < 30; i++)
		{
			printf("\033[%d;%dH", p.getY() + i, p.getX() - 6);
			std::cout << "      ";
			if (i == getLicznikKomunikatow())
			{
				printf("\033[%d;%dH", p.getY() + i, p.getX() - 6);
				std::cout << "===>  ";
			}
		}

		

		if (flagaKategorii == 0) // neutralny komunikat - bia³y
			SetConsoleTextAttribute(hConsole, 15);
		else if (flagaKategorii == 1) // rozmnazanie - zielony komunikat
			SetConsoleTextAttribute(hConsole, 10);
		else if (flagaKategorii == 2) // walka - czerwony komunikat
			SetConsoleTextAttribute(hConsole, 12);
		else if (flagaKategorii == 3) // odurzenie kokain¹ - na ró¿owo
			SetConsoleTextAttribute(hConsole, 13);

		printf("\033[%d;%dH", p.getY() + getLicznikKomunikatow(), p.getX());
		std::cout << "                                                                                ";
		printf("\033[%d;%dH", p.getY() + getLicznikKomunikatow(), p.getX());
		std::cout << relacja;
		incLicznikKomunikatow();
		if (getLicznikKomunikatow() > 30) setLicznikKomunikatow(0);
	}
}

void Swiat::swap(unsigned short _iLewy, Organizm* _lewy, unsigned short _iPrawy, Organizm* _prawy)
{
	Organizm* tmp = _lewy;
	setOrganizm(_iLewy, _prawy);
	setOrganizm(_iPrawy, tmp);
}

bool Swiat::koniecGry()
{
	RECT wO = { 0,0,1024,768 };
	LPRECT wymiaryOkna = &wO;

	GetWindowRect(GetConsoleWindow(), wymiaryOkna);
	unsigned int iloscPol = getRozmiarSwiata() * getRozmiarSwiata();
	std::string werdykt;
	if (getIloscOrganizmow() >= iloscPol)
	{
		if (getIloscZwierzat() == 0)
		{
			setPrzebiegTury('q');
			werdykt = "ROSLINY ";
		}
		else if (getIloscNiedzwiedzi() >= iloscPol)
		{
			setPrzebiegTury('q');
			werdykt = "NIEDZWIEDZIE ";
		}
		else if (getIloscWilkow() >= iloscPol)
		{
			setPrzebiegTury('q');
			werdykt = "WILKI ";
		}
		else if (getIloscLeniwcow() >= iloscPol)
		{
			setPrzebiegTury('q');
			werdykt = "LENIWCE ";
		}
		else if (getIloscZmij() >= iloscPol)
		{
			setPrzebiegTury('q');
			werdykt = "ZMIJE ";
		}
		else if (getIloscOwiec() >= iloscPol)
		{
			setPrzebiegTury('q');
			werdykt = "OWCE ";
		}
		if(getPrzebiegTury()=='q')
		{
			werdykt += "ZDOMINOWALY SWIAT!";
			while(true)
			{
				
				printf("\033[%d;%dH", (wymiaryOkna->bottom - wymiaryOkna->top) / 30-1, (wymiaryOkna->right - wymiaryOkna->left) / 50 - 5);
				std::cout << "                                      ";
				printf("\033[%d;%dH", (wymiaryOkna->bottom - wymiaryOkna->top) / 30+1, (wymiaryOkna->right - wymiaryOkna->left) / 50 - 5);
				std::cout << "                                      ";
				printf("\033[%d;%dH", (wymiaryOkna->bottom - wymiaryOkna->top) / 30, (wymiaryOkna->right - wymiaryOkna->left) / 50-5);
				std::cout << "                                      ";
				Sleep(1000);
				printf("\033[%d;%dH", (wymiaryOkna->bottom - wymiaryOkna->top) / 30, (wymiaryOkna->right - wymiaryOkna->left) / 50);
				std::cout << werdykt;
				Sleep(1000);
				
			}
			return true;
		}
		return false;
	}
}

void Swiat::wyswietlKomunikat(std::string komunikat)
{
	if (rozmiarSwiata <= 20)
	{
		printf("\033[%d;%dH", 8, 69);
		std::cout << "==============================";
		printf("\033[%d;%dH", 9, 69);
		std::cout << "======== " << komunikat << " ========";
		printf("\033[%d;%dH", 10, 69);
		std::cout << "==============================";
		setPrzebiegTury(_getch());
	}
}

void Swiat::czyscKomunikat()
{
	if (rozmiarSwiata <= 20)
	{
		printf("\033[%d;%dH", 8, 69);
		std::cout << "                              ";
		printf("\033[%d;%dH", 9, 69);
		std::cout << "                              ";
		printf("\033[%d;%dH", 10, 69);
		std::cout << "                              ";
	}
}

bool Swiat::zapiszGre()
{
	std::ofstream zapis("d:/zapisanegry/zapis.txt");
	if (zapis.is_open())
	{
		zapis << (zapis, *this);

		zapis.close();
		wyswietlKomunikat("ZAPISANO GRE");
		setPrzebiegTury(_getch());

		return true;
	}
	else
	{
		wyswietlKomunikat("BLAD ZAPISU!");
		setPrzebiegTury(_getch());
		throw Wyjatek::Wyjatek("Blad! Nie udalo sie utworzyc pliku do zapisu!");
	}

}

Swiat* Swiat::wczytajGre()
{
	RECT wO = { 0,0,1024,768 };
	LPRECT wymiaryOkna = &wO;

	GetWindowRect(GetConsoleWindow(), wymiaryOkna);
	system("cls");
	std::ifstream odczyt("d:/zapisanegry/zapis.txt");

	if(odczyt.is_open())
	{
		std::string wczytanyString;
		unsigned short _rozmiarSwiata;
		unsigned short _licznikTur;
		char _przebiegTury;
		unsigned short _iloscGatunkow;
		unsigned short _iloscOrganizmow;
		unsigned short _iloscZwierzat;
		unsigned short _iloscRoslin;
		unsigned short _iloscWilkow;
		unsigned short _iloscNiedzwiedzi;
		unsigned short _iloscZmij;
		unsigned short _iloscLeniwcow;
		unsigned short _iloscOwiec;
		unsigned short _iloscKoki;
		unsigned short _iloscTrawy;
		unsigned short _iloscMleczu;
		//======================================================================
		// WCZYTYWANIE KOLEJNYCH PARAMETRÓW ŒWIATA
		//======================================================================
		// ROZMIAR
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _rozmiarSwiata;
		odczyt >> wczytanyString;

		//======================================================================
		// LICZBA TUR
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _licznikTur;
		odczyt >> wczytanyString;
	
		//======================================================================
		// PRZEBIEG TURY
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _przebiegTury;
		odczyt >> wczytanyString;

		//======================================================================
		// LICZBA GATUNKOW
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscGatunkow;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA ORGANIZMOW
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscOrganizmow;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA ZWIERZAT
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscZwierzat;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA ROSLIN
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscRoslin;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA WILKOW
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscWilkow;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA NIEDZWIEDZI
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscNiedzwiedzi;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA ZMIJ
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscZmij;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA LENIWCOW
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscLeniwcow;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA OWIEC
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscOwiec;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA KOKI
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscKoki;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA TRAWY
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscTrawy;
		odczyt >> wczytanyString;
		//======================================================================
		// LICZBA MLECZU
		while (wczytanyString != ":")
		{
			odczyt >> wczytanyString;
		}
		odczyt >> _iloscMleczu;
		odczyt >> wczytanyString;
	
		Swiat* tymczasowySwiat = new Swiat(_rozmiarSwiata, _iloscOrganizmow);
		tymczasowySwiat->setLicznikTur(_licznikTur);
		tymczasowySwiat->setPrzebiegTury(_przebiegTury);
		tymczasowySwiat->setIloscGatunkow(_iloscGatunkow);
		tymczasowySwiat->setIloscOrganizmow(_iloscOrganizmow);
		tymczasowySwiat->setIloscZwierzat(_iloscZwierzat);
		tymczasowySwiat->setIloscRoslin(_iloscRoslin);
		tymczasowySwiat->setIloscWilkow(_iloscWilkow);
		tymczasowySwiat->setIloscNiedzwiedzi(_iloscNiedzwiedzi);
		tymczasowySwiat->setIloscZmij(_iloscZmij);
		tymczasowySwiat->setIloscLeniwcow(_iloscLeniwcow);
		tymczasowySwiat->setIloscOwiec(_iloscOwiec);
		tymczasowySwiat->setIloscKoki(_iloscKoki);
		tymczasowySwiat->setIloscTrawy(_iloscTrawy);
		tymczasowySwiat->setIloscMleczu(_iloscMleczu);


		std::string _nazwa;
		unsigned short _sila;
		unsigned short _wiek;
		unsigned short _ileAkcji;
		bool _dodatkowyRuch;
		PUNKT _polozenie;
		PUNKT _przybywaZ;
		bool _rozmnazalSie;
		bool _czySieRuszyl;
	
		for (int i = 0; i < _iloscOrganizmow; i++)
		{
			odczyt >> _nazwa;//nazwa
	

			odczyt >> _sila;//si³a
	
			odczyt >> _wiek;//wiek
	
			odczyt >> _ileAkcji;//ileAkcji
	
			odczyt >> _dodatkowyRuch;//dodatkowy ruch
	
			short tmpX;
			odczyt >> tmpX;
			_polozenie.setX(tmpX);
			//odczyt >> _polozenie.getX();//polozenie x
	
			odczyt >> wczytanyString; // wydmuszka na przecinek

			short tmpY;
			odczyt >> tmpY;
			_polozenie.setY(tmpY);
			//odczyt >> _polozenie.getY();// polozenie y
	

			short tmpX2;
			odczyt >> tmpX2;
			_przybywaZ.setX(tmpX2);

			//odczyt >> _przybywaZ.getX();// przybywaZ x	

			odczyt >> wczytanyString; // wydmuszka na przecinek


			short tmpY2;
			odczyt >> tmpY2;
			_przybywaZ.setY(tmpY2);

			//odczyt >> _przybywaZ.getY();// przybywaZ y
	
			odczyt >> _rozmnazalSie;// rozmnazal sie
	
			if (_nazwa == "Leniwiec")
			{
				odczyt >> _czySieRuszyl;// czySieRuszyl (LENIWIEC)
	
			}
			odczyt >> wczytanyString;// srednik
		
			if (_nazwa == "Wilk")
			{
				tymczasowySwiat->setOrganizm(i, new Wilk(_polozenie, tymczasowySwiat)) ;
			}
			else if (_nazwa == "Misio")
			{
				tymczasowySwiat->setOrganizm(i, new Niedzwiedz(_polozenie, tymczasowySwiat));
			}
			else if (_nazwa == "Zmija")
			{
				tymczasowySwiat->setOrganizm(i, new Zmija(_polozenie, tymczasowySwiat));
			}
			else if (_nazwa == "Leniwiec")
			{
				tymczasowySwiat->setOrganizm(i, new Leniwiec(_polozenie, tymczasowySwiat, _czySieRuszyl));
			}
			else if (_nazwa == "Owca")
			{
				tymczasowySwiat->setOrganizm(i, new Owca(_polozenie, tymczasowySwiat));
			}
			else if (_nazwa == "Koka")
			{
				tymczasowySwiat->setOrganizm(i, new Koka(_polozenie, tymczasowySwiat));
			}
			else if (_nazwa == "Trawa")
			{
				tymczasowySwiat->setOrganizm(i, new Trawa(_polozenie, tymczasowySwiat));
			}
			else
			{
				tymczasowySwiat->setOrganizm(i, new Mlecz(_polozenie, tymczasowySwiat));
			}		
			tymczasowySwiat->getOrganizm(i)->setSila(_sila);
			tymczasowySwiat->getOrganizm(i)->setWiek(_wiek);
			tymczasowySwiat->getOrganizm(i)->setIleAkcji(_ileAkcji);
			tymczasowySwiat->getOrganizm(i)->setDodatkowyRuch(_dodatkowyRuch);
		
			tymczasowySwiat->getOrganizm(i)->setPolozenie(_polozenie);
			tymczasowySwiat->getOrganizm(i)->setPrzybywaZ(_przybywaZ);
			tymczasowySwiat->getOrganizm(i)->setRozmnazalSie(_rozmnazalSie);		
		}

		odczyt.close();	
	
		tymczasowySwiat->rysujPlansze(wymiaryOkna->top, wymiaryOkna->left, wymiaryOkna->bottom, wymiaryOkna->right);
		tymczasowySwiat->wyswietlKomunikat("WCZYTANO GRE");

		return tymczasowySwiat;
	 }
	 else 
	 {
		rysujPlansze(wymiaryOkna->top, wymiaryOkna->left, wymiaryOkna->bottom, wymiaryOkna->right);
		wyswietlKomunikat("BLAD WCZYTYWANIA");
		 throw Wyjatek::Wyjatek("Blad! Nie udalo sie otworzyc pliku!");
		 return nullptr;
	  }
}

void Swiat::wypiszSwiat(std::ostream& os)
{
	os << "Rozmiar planszy		: " << getRozmiarSwiata()<< std::endl;
	os << "Rozgrywana tura		: " << getLicznikTur() << std::endl;
	os << "Przebieg tury		: " << getPrzebiegTury() << std::endl;
	os << "Ilosc Gatunkow		: " << getIloscGatunkow() << std::endl;
	os << "Ilosc Organizmow	: " << getIloscOrganizmow() << std::endl;
	os << "Ilosc Zwierzat		: " << getIloscZwierzat() << std::endl;
	os << "Ilosc Roslin		: " << getIloscRoslin() << std::endl;
	os << "Ilosc Wilkow		: " << getIloscWilkow() << std::endl;
	os << "Ilosc Niedzwiedzi	: " << getIloscNiedzwiedzi() << std::endl;
	os << "Ilosc Zmij		: " << getIloscZmij() << std::endl;
	os << "Ilosc Leniwcow		: " << getIloscLeniwcow() << std::endl;
	os << "Ilosc Owiec		: " << getIloscOwiec() << std::endl;
	os << "Ilosc Koki		: " << getIloscKoki() << std::endl;
	os << "Ilosc Trawy		: " << getIloscTrawy() << std::endl;
	os << "Ilosc Mleczu		: " << getIloscMleczu() << std::endl;
	os << "Organizmy:" << std::endl;
	for (int i = 0; i < getIloscOrganizmow(); i++)
	{
		getOrganizm(i)->wypiszOrganizm(os);
	}

}

std::ostream& operator<<(std::ostream& os, Swiat& swiat)
{
	swiat.wypiszSwiat(os);
	return os;
}

//===========================================================
// INKREMENTATORY
//===========================================================

void Swiat::incIloscOrganizmow() { iloscOrganizmow++; }

void Swiat::incLicznikTur() { licznikTur++; }

void Swiat::incLicznikKomunikatow() { licznikKomunikatow++; }

void Swiat::incIloscZwierzat() { iloscZwierzat++; }

void Swiat::incIloscRoslin() { iloscRoslin++; }

void Swiat::incIloscWilkow() { iloscWilkow++; }

void Swiat::incIloscNiedzwiedzi() { iloscNiedzwiedzi++; }

void Swiat::incIloscZmij() { iloscZmij++; }

void Swiat::incIloscLeniwcow() { iloscLeniwcow++; }

void Swiat::incIloscOwiec() { iloscOwiec++; }

void Swiat::incIloscKoki() { iloscKoki++; }

void Swiat::incIloscTrawy() { iloscTrawy++; }

void Swiat::incIloscMleczu() { iloscMleczu++; }


//===========================================================
// DEKREMENTATORY
//===========================================================
void Swiat::decIloscOrganizmow() { iloscOrganizmow--; }

void Swiat::decIloscZwierzat() { iloscZwierzat--; }

void Swiat::decIloscRoslin() { iloscRoslin--; }

void Swiat::decIloscWilkow() { iloscWilkow--; }

void Swiat::decIloscNiedzwiedzi() { iloscNiedzwiedzi--; }

void Swiat::decIloscZmij() { iloscZmij--; }

void Swiat::decIloscLeniwcow() { iloscLeniwcow--; }

void Swiat::decIloscOwiec() { iloscOwiec--; }

void Swiat::decIloscKoki() { iloscKoki--; }

void Swiat::decIloscTrawy() { iloscTrawy--; }

void Swiat::decIloscMleczu() { iloscMleczu--; }



//===========================================================
// GETTERY
//===========================================================
unsigned short Swiat::getRozmiarSwiata() { return rozmiarSwiata; }

unsigned short Swiat::getIloscOrganizmow() { return iloscOrganizmow; }

unsigned short Swiat::getIloscGatunkow() { return iloscGatunkow; }

unsigned short Swiat::getLicznikTur() { return licznikTur; }

unsigned short Swiat::getLicznikKomunikatow() { return licznikKomunikatow; }

unsigned short Swiat::getIloscZwierzat() { return iloscZwierzat; }

unsigned short Swiat::getIloscRoslin() { return iloscRoslin; }

unsigned short Swiat::getIloscWilkow() { return iloscWilkow; }

unsigned short Swiat::getIloscNiedzwiedzi() { return iloscNiedzwiedzi; }

unsigned short Swiat::getIloscZmij() { return iloscZmij; }

unsigned short Swiat::getIloscLeniwcow() { return iloscLeniwcow; }

unsigned short Swiat::getIloscOwiec() { return iloscOwiec; }

unsigned short Swiat::getIloscKoki() { return iloscKoki; }

unsigned short Swiat::getIloscTrawy() { return iloscTrawy; }

unsigned short Swiat::getIloscMleczu() { return iloscMleczu; }

char Swiat::getPrzebiegTury() { return przebiegTury; }

Organizm* Swiat::getOrganizm(unsigned short i) { return this->organizmy[i]; }

//===========================================================
// SETTERY
//===========================================================

void Swiat::setRozmiarSwiata(unsigned short rozmiar) { rozmiarSwiata = rozmiar; }
void Swiat::setIloscOrganizmow(unsigned short _iloscOrganizmow) { iloscOrganizmow = _iloscOrganizmow; }
void Swiat::setIloscGatunkow(unsigned short _iloscGatunkow) { iloscGatunkow = _iloscGatunkow; }
void Swiat::setIloscZwierzat(unsigned short _iloscZwierzat) { iloscZwierzat = _iloscZwierzat; }
void Swiat::setIloscRoslin(unsigned short _iloscRoslin) { iloscRoslin = _iloscRoslin; }
void Swiat::setLicznikTur(unsigned short _licznikTur) { licznikTur = _licznikTur; }
void Swiat::setLicznikKomunikatow(unsigned short _licznikKomunikatow) { licznikKomunikatow = _licznikKomunikatow; }

void Swiat::setIloscWilkow(unsigned short _iloscWilkow) { iloscWilkow = _iloscWilkow;}
void Swiat::setIloscNiedzwiedzi(unsigned short _iloscNiedzwiedzi) { iloscNiedzwiedzi = _iloscNiedzwiedzi ;}
void Swiat::setIloscZmij(unsigned short _iloscZmij) { iloscZmij = _iloscZmij;}
void Swiat::setIloscLeniwcow(unsigned short _iloscLeniwcow) { iloscLeniwcow = _iloscLeniwcow ;}
void Swiat::setIloscOwiec(unsigned short _iloscOwiec) { iloscOwiec = _iloscOwiec ;}
void Swiat::setIloscKoki(unsigned short _iloscKoki) { iloscKoki = _iloscKoki ;}
void Swiat::setIloscTrawy(unsigned short _iloscTrawy) { iloscTrawy = _iloscTrawy ;}
void Swiat::setIloscMleczu(unsigned short _iloscMleczu) { iloscMleczu = _iloscMleczu ;}

void Swiat::setOrganizm(unsigned short i, Organizm* _organizm) { organizmy[i] = _organizm; }

Swiat::Swiat(unsigned short  r, unsigned short _iloscOrganizmow)
{
	//=================================================================================================
	//======== POCZ¥TKOWE PARAMETRY
	//=================================================================================================
	setRozmiarSwiata(r);						// d³ugoœæ boku planszy
	setIloscOrganizmow(_iloscOrganizmow);		// 
	setIloscGatunkow(8);						// nale¿y ka¿dorazowo uaktualniæ o liczbê dostêpnych na œwiecie gatunków!!!

	setLicznikTur(0);
	setIloscWilkow(0);
	setIloscNiedzwiedzi(0);
	setIloscZmij(0);
	setIloscLeniwcow(0);
	setIloscOwiec(0);
	setIloscKoki(0);
	setIloscTrawy(0);
	setIloscMleczu(0);

	setLicznikKomunikatow(0);

	unsigned int iloscPol = getRozmiarSwiata() * getRozmiarSwiata();
	unsigned short proporcja = getIloscOrganizmow() / getIloscGatunkow();

	srand((unsigned int)(time)(NULL));
	PUNKT coord;

	unsigned short int iOrg = 0;
	bool dubel = false;
	organizmy = new Organizm * [iloscPol];

	//=====================================================================================================================================
	//============================ TWORZENIE ORGANIZMOW ===================================================================================
	//=====================================================================================================================================

	for (iOrg = 0; iOrg < getIloscOrganizmow(); iOrg++)
	{
		coord.setX(rand() % getRozmiarSwiata());
		coord.setY(rand() % getRozmiarSwiata());

		for (unsigned short j = 0; j < iOrg; j++)
		{
			if ((getOrganizm(j)->getPolozenie().getX() == coord.getX()) && (getOrganizm(j)->getPolozenie().getY() == coord.getY()))
			{
				dubel = true;
			}
		}
		while (dubel == true)
		{
			dubel = false;
			coord.setX(rand() % getRozmiarSwiata());
			coord.setY(rand() % getRozmiarSwiata());
			for (unsigned short j = 0; j < iOrg; j++)
			{
				if ((getOrganizm(j)->getPolozenie().getX() == coord.getX()) && (getOrganizm(j)->getPolozenie().getY() == coord.getY()))
				{
					dubel = true;
				}
			}
		}
		if (iOrg < (1 * proporcja))
			setOrganizm(iOrg,new Wilk(coord, this));
		else if (iOrg < (2 * proporcja))
			setOrganizm(iOrg, new Leniwiec(coord, this,true)); // - oddaæ leniwca
		else if (iOrg < (3 * proporcja))
			setOrganizm(iOrg, new Niedzwiedz(coord, this));  //------ oddaæ misia!!!
		else if (iOrg < (4 * proporcja))
			setOrganizm(iOrg, new Zmija(coord, this));
		else if (iOrg < (5 * proporcja))
			setOrganizm(iOrg, new Owca(coord, this));
		else if (iOrg < (6 * proporcja))
			setOrganizm(iOrg, new Koka(coord, this));
		else if (iOrg < (7 * proporcja))
			setOrganizm(iOrg, new Mlecz(coord, this));
		else
			setOrganizm(iOrg, new Trawa(coord, this));
		getOrganizm(iOrg)->setWiek((getIloscOrganizmow() - iOrg));
	}

	sortujOrganizmy(iOrg);
	while (iOrg < iloscPol)
	{
		setOrganizm(iOrg,nullptr);
		iOrg++;
	}
	for (int i = 0; i < getIloscOrganizmow(); i++)
	{
		inwentaryzujOrganizmy(true, i);
	}
}

Swiat::~Swiat()
{
	std::cout << "\nApocalypse now!\n";	
	
	for (int i = 0; i < getIloscOrganizmow(); i++)
	{
		//std::cout << "Usuwam organizm\n";
		//this->getOrganizm(i)->wypiszOrganizm(std::cout);
		//std::cout<< "\n";
			delete organizmy[i];
	}
	delete []organizmy;
	std::cout << "Apocalypse finished!\n";
}