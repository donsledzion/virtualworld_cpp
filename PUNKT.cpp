#include "PUNKT.h"

PUNKT::PUNKT(short _x, short _y) {
	x = _x;
	y = _y;
}

PUNKT::PUNKT()
{
	x = 0;
	y = 0;
}

PUNKT::~PUNKT() {}

short PUNKT::getX() { return this->x; }
short PUNKT::getY() { return this->y; }
PUNKT PUNKT::getWspolrzedne() { return PUNKT(this->x, this->y); }

void PUNKT::setX(short _x) { this->x = _x; }
void PUNKT::setY(short _y) { this->y = _y; }
void PUNKT::setWspolrzedne(PUNKT _location) { this->x = _location.getX(); this->y = _location.getY(); }