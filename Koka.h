#pragma once
#include "Roslina.h"
class Koka :
    public Roslina
{

public:

    Koka(PUNKT _p, Swiat * _swiat);

    ~Koka();

private:

    void reAkcja(Organizm* jedzacy);
};

