#pragma once
#include "Zwierze.h"
class Zmija :
    public Zwierze
{

public:

    Zmija(PUNKT _p, Swiat * _swiat);

    ~Zmija();

private:

    void reAkcja(Organizm* jedzacy);

};

