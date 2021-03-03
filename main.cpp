#include <conio.h>
#include "Swiat.h"
#include "Wyjatek.h"
#include <windows.h>
#include <stdlib.h>

void maximizeWindow() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);	
}

int main()
{
	maximizeWindow();
	
	RECT wO = { 0,0,1024,768 };
	LPRECT wymiaryOkna = &wO;

	GetWindowRect(GetConsoleWindow(), wymiaryOkna);
	
	int rozmiarSwiata = 20;
	int populacjaStartowa = 3 * rozmiarSwiata;


	//std::cout << std::endl;
	char klawisz = 'r';	
	Swiat nowySwiat(rozmiarSwiata,populacjaStartowa);
	nowySwiat.rysujPlansze(wymiaryOkna->top,wymiaryOkna->left,wymiaryOkna->bottom,wymiaryOkna->right);
	while ((klawisz=='s')||(klawisz = _getch()))
	{
		try 
		{
			nowySwiat.setPrzebiegTury(klawisz);
			if (nowySwiat.getPrzebiegTury() == 'w')
			{
				nowySwiat = *nowySwiat.wczytajGre();
				nowySwiat.setPrzebiegTury(klawisz = _getch());
			}
			nowySwiat.setPrzebiegTury(klawisz);
			if ((klawisz == 'z') || (klawisz == 'Z') || (nowySwiat.getPrzebiegTury() == 'z'))
				nowySwiat.zapiszGre();
			nowySwiat.czyscKomunikat();
			if ((klawisz == 'q') || (klawisz == 'Q') || (nowySwiat.getPrzebiegTury() == 'q'))
				break;

			nowySwiat.wykonajTure(nowySwiat.getPrzebiegTury());
			if (nowySwiat.getPrzebiegTury() == 'a')
			{
				if (nowySwiat.getRozmiarSwiata() <= 20)
					nowySwiat.rysujSwiatS(17);
				else
					nowySwiat.rysujSwiatXL(17);
			}
		}
		catch (Wyjatek& w) 
		{
			std::cout << "\nPrzechwycony wyjatek:\n" << w._tresc;
		}
		
	}
	if(nowySwiat.koniecGry())
		klawisz = _getch();
	return 0;
}